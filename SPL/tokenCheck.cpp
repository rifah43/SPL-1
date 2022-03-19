#include<bits/stdc++.h>
#include"tokenCheck.h"
using namespace std;

vector<string>keywords;
vector<char>digit;
vector<char>punc;
vector<char>oprtr;
vector<string>boolOprtr;
vector<string>spcOprtr1;
vector<string>spcOprtr2;

string convertToString(char* charArray, int size)
{
    int i;
    string convStr = "";
    for (i = 0; i < size; i++) {
        convStr = convStr + charArray[i];
    }
    return convStr;
}

void keywordList()
{
    keywords.push_back("If");
    keywords.push_back("print");
    keywords.push_back("For");
    keywords.push_back("AsyncFor");
    keywords.push_back("While");
    keywords.push_back("With");
    keywords.push_back("AsyncWith");
    keywords.push_back("Raise");
    keywords.push_back("Match");
    keywords.push_back("Try");
    keywords.push_back("Assert");
    keywords.push_back("Import");
    keywords.push_back("Global");
    keywords.push_back("Nonlocal");
    keywords.push_back("Pass");
    keywords.push_back("Break");
    keywords.push_back("Continue");
    keywords.push_back("Return");
    keywords.push_back("Delete");
    keywords.push_back("Assign");
}

void numList()
{
    digit.push_back('1');
    digit.push_back('2');
    digit.push_back('3');
    digit.push_back('4');
    digit.push_back('5');
    digit.push_back('6');
    digit.push_back('7');
    digit.push_back('8');
    digit.push_back('9');
    digit.push_back('0');
}

void puncList()
{
    punc.push_back('+');
    punc.push_back('-');
    punc.push_back('*');
    punc.push_back('/');
    punc.push_back(',');
    punc.push_back(':');
    punc.push_back(';');
    punc.push_back('>');
    punc.push_back('<');
    punc.push_back('=');
    punc.push_back(')');
    punc.push_back('(');
    punc.push_back('|');
    punc.push_back('&');
    punc.push_back('[');
    punc.push_back(']');
    punc.push_back('"');
    punc.push_back('\n');
    punc.push_back('\t');
}

void opList()
{
    oprtr.push_back('+');
    oprtr.push_back('-');
    oprtr.push_back('*');
    oprtr.push_back('/');
    oprtr.push_back('>');
    oprtr.push_back('<');
    oprtr.push_back('=');
    oprtr.push_back('|');
    oprtr.push_back('&');
    oprtr.push_back('!');
    oprtr.push_back('%');
    oprtr.push_back('^');
    oprtr.push_back('~');
}

void boolOpList()
{
    boolOprtr.push_back("and");
    boolOprtr.push_back("or");
    boolOprtr.push_back("not");
}

void spcOpList1()
{
    spcOprtr1.push_back("is");
    spcOprtr1.push_back("is not");
}

void spcOpList2()
{
    spcOprtr2.push_back("in");
    spcOprtr2.push_back("not in");
}

bool isPunc(char ch)
{		
    int counter=0;
    for(int i=0;i<punc.size();i++)
    {
        if(ch==punc.at(i))
        {
            counter++;
        }
    }
    if(counter!=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isDigit(char ch)
{
    int counter=0;
    for(int i=0;i<digit.size();i++)
    {
        if(ch==digit.at(i))
        {
            counter++;
        }
    }
    if(counter!=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool validId(char* str)
{
    char temp=str[0];
    
    if(ispunct(temp)==true || isDigit(temp)== true)
    {
        return false;
    }									
    int i,len = strlen(str);
    if (len == 1)
    {
        return true;
    }
    else
    {
    for (i = 1 ; i < len ; i++)
    {
        if (isPunc(str[i]) == true)
        {
            return false;
        }
    }
    }
    return true;
}

bool isOperator(char ch)
{
    int counter=0;
    for(int i=0;i<oprtr.size();i++)
    {
        if(ch==oprtr.at(i))
        {
            counter++;
        }
    }
    if(counter!=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isKeyword(char *str)
{
    char carray[10];
    strcpy(carray,str);
    string temp= convertToString(carray,strlen(carray));
    int counter=0;
    for(int i=0;i<keywords.size();i++)
    {
        if(temp==keywords[i])
        {
            counter++;
        }
    }
    if(counter!=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isboolOprtr(char *str)
{
    char carray[5];
    strcpy(carray,str);
    string temp= convertToString(carray,strlen(carray));
    int counter=0;
    for(int i=0;i<boolOprtr.size();i++)
    {
        if(temp==boolOprtr[i])
        {
            counter++;
        }
    }
    if(counter!=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isSpcOprtr1(char *str)
{
    char carray[5];
    strcpy(carray,str);
    string temp= convertToString(carray,strlen(carray));
    int counter=0;
    for(int i=0;i<spcOprtr1.size();i++)
    {
        if(temp==spcOprtr1[i])
        {
            counter++;
        }
    }
    if(counter!=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isSpcOprtr2(char *str)
{
    char carray[5];
    strcpy(carray,str);
    string temp= convertToString(carray,strlen(carray));
    int counter=0;
    for(int i=0;i<spcOprtr2.size();i++)
    {
        if(temp==spcOprtr2[i])
        {
            counter++;
        }
    }
    if(counter!=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isNumber(char* str)
{
    int i, len = strlen(str),numOfDecimal = 0;
    if (len == 0)
    {
        return false;
    }
    for (i = 0 ; i < len-2 ; i++)
    {
        if (isDigit(str[i])==true && str[i+1] == '.' && isDigit(str[i+2])==true)
        {
            return true;
        }
     
        if (isDigit(str[i])==false || (str[i] == '-' && i > 0))
            {
                return false;
            }
    }
    return true;
}