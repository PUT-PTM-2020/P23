#pragma once
#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>
#include <WifiMoje.cpp>
#include <HttpRequester.cpp>
#include <StringMoje.cpp>
#include <Logger.cpp>
#include <string> 
#include <Config.cpp> 
using namespace std;

#define SS_PIN 4
#define RST_PIN 5
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.



WifiMoje moje;
Config config;

String LastId = "";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  moje.connect();
  Serial.println("Polaczono z sukcesem");
  Logger::logInfo("Polaczono z sukcesem");
  Logger::logInfo("Nazwa sieci WiFi: " + string(WiFi.SSID().c_str()) );

  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522

  Serial.println("Approximate your card to the reader...");
  Serial.println();
}

String readCard()
{
  String bytes = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     bytes += String(mfrc522.uid.uidByte[i]);
  }
  Logger::logInfo("Card ID:" + string(bytes.c_str()));
  return bytes;
}

void SendResponse(String response)
{
  Serial.println(response);
}

void HandleCommand(String Command)
{
  if(Command.substring(0,9) == "GetLastId")
  {
    if(LastId.length() == 0)
    {
      SendResponse("null");
      return;
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
    String response = HttpRequester::Get(Command.substring(15).c_str());
    SendResponse(response);
  }
}


void loop() {


    if ( mfrc522.PICC_IsNewCardPresent()) 
    {
      if (mfrc522.PICC_ReadCardSerial()) 
      {
        LastId = readCard();
        mfrc522.PICC_HaltA();
      }
    }

    while(Serial.available() > 0)
    {
          String s1 = Serial.readStringUntil('\n');
          HandleCommand(s1);
    }


  
}


