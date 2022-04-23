#ifndef PUNCTUATION_H
#define PUNCTUATION_H
#include<bits/stdc++.h>
using namespace std;
vector<char>punctuation;
void puncList()
{
    punctuation.push_back('+');
    punctuation.push_back('-');
    punctuation.push_back('*');
    punctuation.push_back('/');
    punctuation.push_back(',');
    punctuation.push_back(':');
    punctuation.push_back(';');
    punctuation.push_back('>');
    punctuation.push_back('<');
    punctuation.push_back('=');
    punctuation.push_back(')');
    punctuation.push_back('(');
    punctuation.push_back('|');
    punctuation.push_back('&');
    punctuation.push_back('[');
    punctuation.push_back(']');
    punctuation.push_back('"');
    punctuation.push_back('\n');
    punctuation.push_back('\t');
}

    vector <char> getPunctuation() {
        puncList();
        return { punctuation };
    }
#endif