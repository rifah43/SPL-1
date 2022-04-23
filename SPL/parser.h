#ifndef PARSER_H
#define PARSER_H
#include<bits/stdc++.h>
#include"keywords.h"
#include"punctuation.h"
#include"operator.h"
using namespace std;

struct keepData
{
    int line;
    int indentation;
    string expression;
    string dataType;
    string value;
};

vector<keepData>keep;

string convertToString(char* charArray, int size)
{
    int i;
    string convStr = "";
    for (i = 0; i < size; i++) {
        convStr = convStr + charArray[i];
    }
    return convStr;
}


void moduleM();

#endif