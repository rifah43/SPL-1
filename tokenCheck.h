#ifndef TOKENCHECK_H
#define TOKENCHECK_H

#include<bits/stdc++.h>
using namespace std;
void  keywordList();
void numList();
void puncList();
void opList();
void boolOpList();
void spcOpList1();
void spcOpList2();
bool isPunc(char ch);
bool isDigit(char ch);
bool validId(char* str);
bool isOperator(char ch);
bool isKeyword(char *str);
bool isboolOprtr(char *str);
bool isSpcOprtr1(char *str);
bool isSpcOprtr2(char *str);
bool isNumber(char* str);
#endif