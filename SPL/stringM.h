#ifndef STRINGM_H
#define STRINGM_H
#include<bits/stdc++.h>
using namespace std;
char* subString(char* realStr, int l, int r)				
{
    int i;

    char* str = (char*) malloc(sizeof(char) * (r - l + 2));

    for (i = l; i <= r; i++)
    {
        str[i - l] = realStr[i];
        str[r - l + 1] = '\0';
    }
    return str;
}
#endif