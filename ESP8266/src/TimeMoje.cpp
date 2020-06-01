#pragma once
#include <string>
#include <AllIncludesAtOnce.cpp>
using namespace std;
class TimeMoje
{
private:
    /* data */
    string timeUrl = "http://dominik716.ct8.pl/arduino/Logger/set.php?data=";
public:
    static void updateTime()
    {
        if(WiFi.status()== WL_CONNECTED){

        }

    }
};
