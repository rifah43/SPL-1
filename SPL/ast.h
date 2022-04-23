#ifndef AST_H
#define AST_H

#include<bits/stdc++.h>
using namespace std;

void tab();
void binOp(string left,string op, string right);
void assign(string left, string right);
void priPrnt(string left,vector<string> right);
void check(vector<string> tok);
vector <keepData> getStruct();

void lineMaking();

vector <int> getLine();

vector <vector<string>> getHold();

int lineNo();


#endif

