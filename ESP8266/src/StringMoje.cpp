#pragma once
#include <cctype>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

class StringMoje
{
private:
    /* data */
public:
    static string urlEncode(string str)
    {
        string new_str = "";
        char c;
        int ic;
        const char *chars = str.c_str();
        char bufHex[10];
        int len = strlen(chars);

        for (int i = 0; i < len; i++)
        {
            c = chars[i];
            ic = c;
            // uncomment this if you want to encode spaces with +
            /*if (c==' ') new_str += '+';   
        else */
            if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~')
                new_str += c;
            else
            {
                sprintf(bufHex, "%X", c);
                if (ic < 16)
                    new_str += "%0";
                else
                    new_str += "%";
                new_str += bufHex;
            }
        }
        return new_str;
    }



};
