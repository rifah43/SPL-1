#include"header.h"

string commentDel(string code)
{
    int n = code.length();
    string temp;
 
    bool single = false;
 
    for (int i=0; i<n; i++)
    {
        if (single == true && code[i] == '\n')
        {
            single = false;
        }
 
        else if (single)
        {
            continue;
        }
 
        else if (code[i] == '#')
        {
            single = true, i++;
        }
        else 
        {
            temp += code[i];
        }
    }
    return temp;
}

string commentDelmulti(string code)
{
    int n = code.length();
    string temp;

    bool multiple = false;
 
    for (int i=0; i<n-2; i++)
    {
        if (multiple == false && code[i] == '"' && code[i+1] == '"' && code[i+2] == '"')
        {
            multiple = true,  i=i+3;
        }

        else if (multiple == true && code[i] == '"' && code[i+1] == '"' && code[i+2] == '"')
        {
            multiple = false;
        }
 
        else if (multiple)
        {
            continue;
        }
 
        else 
        {
            temp += code[i];
        }
    }
    return temp;
}
