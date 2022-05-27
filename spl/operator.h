#ifndef OPERATOR_H
#define OPERATOR_H
#include<bits/stdc++.h>
using namespace std;
vector<char>op;
vector<string>op2;

void opList()
{
    op.push_back('+');
    op.push_back('-');
    op.push_back('*');
    op.push_back('/');
    op.push_back('>');
    op.push_back('<');
    op.push_back('=');
    op.push_back('|');
    op.push_back('&');
    op.push_back('!');
    op.push_back('%');
    op.push_back('^');
    op.push_back('~');
}

vector <char> getOperator() {
    opList();
    return { op };
}

void opList2()
{
    op2.push_back("and");
    op2.push_back("or");
    op2.push_back("not");
    op2.push_back("is");
    op2.push_back("is not");
    op2.push_back("in");
    op2.push_back("not in");
}

vector <string> getOperator2() {
    opList2();
    return { op2 };
}
#endif