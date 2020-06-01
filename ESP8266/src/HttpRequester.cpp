#pragma once
#include <ESP8266HTTPClient.h>

using namespace std;

class HttpRequester
{
private:
    /* data */
public:
    static String Get(string url)
    {
        String payload = "";
        HTTPClient http;
        http.begin(url.c_str());
        int httpCode = http.GET();
        if (httpCode > 0)
        {
            if (httpCode == HTTP_CODE_OK)
            {
                payload = http.getString();
            }
        }

        http.end();
        return payload;
    }
};
