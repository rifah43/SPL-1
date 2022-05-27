#ifndef TOKENMAKER_H
#define TOKENMAKER_H
#include<bits/stdc++.h>
#include"parser.h"
using namespace std;

vector<string>kwds = getKeywords();
vector<char>punc = getPunctuation();
vector<char>oprtr= getOperator();
vector<string>Oprtr2= getOperator2();

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
    
    if('0'<=ch && ch<='9')
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
    for(int i=0;i<kwds.size();i++)
    {
        if(temp==kwds[i])
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

bool isOprtr2(char *str)
{
    char carray[5];
    strcpy(carray,str);
    string temp= convertToString(carray,strlen(carray));
    int counter=0;
    for(int i=0;i<Oprtr2.size();i++)
    {
        if(temp==Oprtr2[i])
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

bool isInt(char* str)
{
    int i, len = strlen(str),numOfDecimal=0;
    if (len == 0)
    {
        return false;
    }
    for (i = 0 ; i < len ; i++)
    {
        if (numOfDecimal > 1 && str[i] == '.')
        {
            return false;
        }
        else if (numOfDecimal <= 1)
        {
            numOfDecimal++;
        }
     
        if (isDigit(str[i])==false || (str[i] == '-' && i > 0))
        {
            return false;
        }
    }
    return true;
}

bool isDouble(char* str)
{
    int i, len = strlen(str);
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

        if (isDigit(str[i])==true)
        {
            continue;
        }
     
        if (isDigit(str[i])==false || (str[i] == '-' && i > 0))
            {
                return false;
            }
    }
    return false;
}
#endif