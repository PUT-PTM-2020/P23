#pragma once
#include <string>
#include <HttpRequester.cpp>
#include <WifiMoje.cpp>
#include <StringMoje.cpp>
#include <Arduino.h>

using namespace std;

class Logger
{
private:
    /* data */
public:
    static void logInfo(string data)
    {
        if(WiFi.status()== WL_CONNECTED){
            string dataUrlEncoded = StringMoje::urlEncode(data);
            //Serial.print("data: ");
            //Serial.println(dataUrlEncoded.c_str());
            HttpRequester::Get("http://dominik716.ct8.pl/arduino/Logger/set.php?data=" + dataUrlEncoded);
        }
        else
        {
            Serial.println("Cant log info to server");
        }
        
    }
};

