#ifndef KEYWORDS_H
#define KEYWORDS_H
#include<bits/stdc++.h>
using namespace std;
vector<string>keywords;
void keywordList()
{
    keywords.push_back("if");
    keywords.push_back("print");
    keywords.push_back("for");
    keywords.push_back("asyncFor");
    keywords.push_back("while");
    keywords.push_back("with");
    keywords.push_back("asyncWith");
    keywords.push_back("raise");
    keywords.push_back("match");
    keywords.push_back("try");
    keywords.push_back("assert");
    keywords.push_back("import");
    keywords.push_back("global");
    keywords.push_back("nonlocal");
    keywords.push_back("pass");
    keywords.push_back("break");
    keywords.push_back("continue");
    keywords.push_back("return");
    keywords.push_back("del");
    keywords.push_back("assign");
    keywords.push_back("as");
    keywords.push_back("and");
    keywords.push_back("class");
    keywords.push_back("def");
    keywords.push_back("else");
    keywords.push_back("elif");
    keywords.push_back("except");
    keywords.push_back("exec");
    keywords.push_back("finally");
    keywords.push_back("from");
    keywords.push_back("and");
    keywords.push_back("or");
    keywords.push_back("not");
    keywords.push_back("is");
    keywords.push_back("in");
    keywords.push_back("lambda");
    keywords.push_back("False");
    keywords.push_back("None");
    keywords.push_back("True");
    keywords.push_back("yield");
}

    vector <string> getKeywords() {
        keywordList();
        return { keywords };
    }
#endif