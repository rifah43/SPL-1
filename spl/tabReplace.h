#ifndef TABREPLACE_H
#define TABREPLACE_H
#include<bits/stdc++.h>
using namespace std;
string replaceTab(string code)
{
    int n = code.length(),i;
    string temp;
 
    for (i=0; i<n-3; i++)
    {
        if(code[i]==' ' && code[i+1]==' ' && code[i+2]==' ' && code[i+3]==' ')
        {
            temp +='\t';
            i=i+3;
        }
        else
        {
            temp += code[i];
        }
    }
    temp += code[i];
    temp += code[i+1];
    temp += code[i+2];
    temp += code[i+3];
    return temp;

}
#endif