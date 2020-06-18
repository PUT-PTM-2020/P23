#pragma once
#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>
#include <SoftwareSerial.h>
#include <WifiMoje.cpp>
#include <HttpRequester.cpp>
#include <StringMoje.cpp>
#include <Logger.cpp>
#include <string> 
#include <String> 
#include <Config.cpp> 
using namespace std;

#define SS_PIN 4
#define RST_PIN 5
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.



WifiMoje moje;
Config config;

String LastId = "";
SoftwareSerial SSerial(3,1);


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on by making the voltage LOW
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
  SSerial.begin(9600);
  Serial.println("Uruchomiono plytke");
  SSerial.println("Uruchomiono plytke SS.");
  moje.connect();
  Serial.println("Polaczono z sukcesem");
  Logger::logInfo("Polaczono z sukcesem");
  Logger::logInfo("Nazwa sieci WiFi: " + string(WiFi.SSID().c_str()) );

  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522

  Serial.println("Approximate your card to the reader...");
  Serial.println();
  digitalWrite(LED_BUILTIN, HIGH);   // Turn the LED on by making the voltage LOW
}

String readCard()
{
  String bytes = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     bytes += String(mfrc522.uid.uidByte[i]);
  }

  while(bytes.length() < 12)
    bytes += "1";
  Logger::logInfo("Card ID:" + string(bytes.c_str()));    // Przykładowe: "137240182178" <- 12 znaków
  return bytes;
}

void SendResponse(String response)
{
  for(int i = 0; i < response.length(); i++)
  {
      Serial.print(response[i]);
      SSerial.print(response[i]);
      delayMicroseconds(20 * 1000);
  }
  Serial.println("");
  SSerial.println("");
}

bool isCardRead()
{
    if ( mfrc522.PICC_IsNewCardPresent()) 
    {
      if (mfrc522.PICC_ReadCardSerial()) 
      {
        LastId = readCard();
        mfrc522.PICC_HaltA();
        return true;
      }
    }
    Logger::logInfo("Karta nie jest odczytana");
    return false;
}

void HandleCommand(String Command)
{
  if(Command.substring(0,9) == "GetLastId")
  {
    if(LastId.length() == 0)
    {
      while(!isCardRead());
    }

    SendResponse(LastId);
  }
  else if(Command.substring(0,11) == "ClearLastId")
  {
    LastId = "";
    SendResponse("Ok");
  }
  else if(Command.substring(0,14) == "GetHttpRequest")
  {
    string link = Command.substring(15).c_str();
    String response = HttpRequester::Get(link);
    //delayMicroseconds(50 * 1000);
    //if(link.find("Device/sendKey") != std::string::npos)
    //if(!strstr(link.c_str(),"Device/sendKey"))
    //{
      SendResponse(response);
    //}else
    //{
       //Logger::logInfo("Pomijam wysylanie odpowiedzi do wcisnietego klawisza");
    //}   
  }
}



void loop() {



    /*while(Serial.available() > 0)
    {
      Logger::logInfo("Otrzymalem cos na hardware serial");
          String s1 = Serial.readStringUntil('\n');
          HandleCommand(s1);
    }*/

    while(SSerial.available() > 0)
    {
          String s1 = SSerial.readStringUntil('\n');
          Logger::logInfo(String("Otrzymalem cos na serial: " + s1).c_str());
          HandleCommand(s1);
    }


  

}


