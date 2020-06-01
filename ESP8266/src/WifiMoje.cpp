#pragma once
//#include <WiFiManager.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

class WifiMoje
{
private:
    /* data */

    ESP8266WiFiMulti wifiMulti;

public:
    void connect()
    {
        WiFi.mode(WIFI_STA);
        wifiMulti.addAP("internet-dom76", "PASSWORD");
        //wifiMulti.addAP("AndroidAP_7555", "test");
        Serial.print("Connecting WiFi ");

        int i = 0;
        while (wifiMulti.run() != WL_CONNECTED)
        { // Wait for the Wi-Fi to connect
            delay(1000);
            Serial.print(++i);
            Serial.print(' ');
        }

        Serial.println('\n');
        Serial.println("Connection established!");
        Serial.print("IP address:\t");
        Serial.println(WiFi.localIP());
        Serial.println("My mac Adress " + WiFi.macAddress());
        Serial.println("Connected to: " + WiFi.SSID() );

    }

    String getMyIPAdress()
    {
        return WiFi.localIP().toString();
    }
};
