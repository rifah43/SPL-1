#include<bits/stdc++.h>
using namespace std;

string convertToString(char* a, int size);
string commentDel(string code);
string commentDelmulti(string code);
void keywordList();
void numList();
void puncList();
void opList();
void boolOpList();
void spcOpList1();
void spcOpList2();
void callFunc();
bool isPunc(char ch);
bool isDigit(char ch);
bool validId(char* str);
bool isOperator(char ch);
bool isboolOprtr(char* str);
bool isSpcOprtr1(char* str);
bool isSpcOprtr2(char* str);
bool isKeyword(char *str);
bool isNumber(char* str);
char* subString(char* realStr, int l, int r);
void parse(char* str);