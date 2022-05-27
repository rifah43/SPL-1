#ifndef COMMENTM_H
#define COMMENTM_H
#include<bits/stdc++.h>
using namespace std;
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
    int n = code.length(),i;
    string temp;

    bool multiple = false;
 
    for (i=0; i<n-2; i++)
    {
        if (multiple == true && code[i] == '"' && code[i+1] == '"' && code[i+2] == '"')
        {
            multiple = false; i=i+3;
        }
 
        else if (multiple== true)
        {
            i++;
        }

        else if (multiple == false && code[i] == '"' && code[i+1] == '"' && code[i+2] == '"')
        {
            multiple = true;  i=i+2;
        }
 
        else 
        {
            temp += code[i];
        }
    }
    temp += code[i];
    temp += code[i+1];
    temp += code[i+2];
    return temp;
}
#endif