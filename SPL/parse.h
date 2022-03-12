#ifndef PARSE_H
#define PARSE_H
#include<bits/stdc++.h>
#include"tokenizer.h"
#include"stringM.h"
using namespace std;

void callFunc()
{
    keywordList();
    numList();
    puncList();
    opList();
    boolOpList();
    spcOpList1();
    spcOpList2();
}

void parse(char* str)
{
    int left = 0, right = 0;
    int len = strlen(str);
    while (right <= len && left <= right)
    {
        if (isPunc(str[right]) == false)
            {
                right++;
            }

        if (isPunc(str[right]) == true && left == right)
            {
                int cnt=0;
                if (isOperator(str[right]) == true && isOperator(str[right+1]) == true)
                {
                    cnt=2;
                    if(str[right]=='>' && str[right+1]=='=' )
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep.push_back(make_pair("GtE",a));
                    }
                    else if(str[right]=='>' && str[right+1]=='=' )
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep.push_back(make_pair("LtE",a));
                    }
                    else if(str[right]=='!' && str[right]=='=')
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep.push_back(make_pair("NotEq",a));
                    }
                    else if(str[right]=='=' && str[right]=='=')
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep.push_back(make_pair("Eq",a));
                    }
                    else if(str[right]=='*' && str[right]=='*')
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep.push_back(make_pair("Pow",a));
                    }
                    else if(str[right]=='/' && str[right]=='/')
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep.push_back(make_pair("FloorDiv",a));
                    }
                    else if(str[right]=='>' && str[right]=='>')
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep.push_back(make_pair("RShift",a));
                    }
                    else if(str[right]=='<' && str[right]=='<')
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep.push_back(make_pair("LShift",a));
                    }
                    else if(str[right]=='+' && (str[right]=='+' || str[right+1]=='='))
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep.push_back(make_pair("INCREMENT OPERATOR",a));
                    }
                    else if(str[right]=='-' && (str[right]=='-' || str[right+1]=='='))
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep.push_back(make_pair("DECREMENT OPERATOR",a));
                    }
                }
                if (isOperator(str[right]) == true && isOperator(str[right+1]) == false)
                {
                    cnt=1;
                    if(str[right]=='>')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep.push_back(make_pair("Gt",a));
                    }
                    else if(str[right]=='<')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep.push_back(make_pair("Lt",a));
                    }
                    else if(str[right]=='=')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep.push_back(make_pair("Assignment",a));
                    }
                    else if(str[right]=='+')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep.push_back(make_pair("Add",a));
                    }
                    else if(str[right]=='-')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep.push_back(make_pair("Sub",a));
                    }
                    else if(str[right]=='*')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep.push_back(make_pair("Mult",a));
                    }
                    else if(str[right]=='/')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep.push_back(make_pair("Div",a));
                    }
                    else if(str[right]=='%')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep.push_back(make_pair("Mod",a));
                    }
                    else if(str[right]=='&')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep.push_back(make_pair("BitAnd",a));
                    }
                    else if(str[right]=='|')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep.push_back(make_pair("BitOr",a));
                    }
                    else if(str[right]=='^')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep.push_back(make_pair("BitXor",a));
                    }
                }
                if(cnt==2)
                {
                    right=right+2;
                }
                else
                {
                    right++;
                }
                left = right;
            }
            else if (isPunc(str[right]) == true && left != right
            || (right == len && left != right))
            {
                if(str[right]=='(')
                {
                    string a;
                    a.push_back(str[right]);
                    keep.push_back(make_pair("LParenthesis",a));
                }
                else if(str[right]==')')
                {
                    string a;
                    a.push_back(str[right]);
                    keep.push_back(make_pair("RParenthesis",a));
                }
                else if(str[right]=='\t')
                {
                    string a;
                    a.push_back(str[right]);
                    keep.push_back(make_pair("Indentation","->"));
                }
                else if(str[left-1]=='"')
                {
                    string temp;
                    while(str[left]!='"' && str[left]>=32 && str[left]<=127)
                    {
                        if(str[left]=='"')
                        {
                            break;
                        }
                        else
                        {
                            string tchar;
                            tchar=str[left];
                            temp.append(tchar);
                            left++;
                        }
                    }
                    keep.push_back(make_pair("STRING_LITERAL",temp));
                }
            
            else
            {
                char* sub = subString(str, left, right - 1);
                string st= convertToString(sub,strlen(sub));
                if (isKeyword(sub) == true)
                {
                    keep.push_back(make_pair("KEYWORD",st));
                }
                else if (isNumber(sub) == true)
                {
                    int z=0;
                    for(int i=0;i<strlen(sub);i++)
                    {
                        if(sub[i]=='.')
                        {
                            z++;
                        }
                    }
                    if(z>0)
                    {
                        keep.push_back(make_pair("DOUBLE",st));
                    }
                    else
                    {
                        keep.push_back(make_pair("INTEGER",st));
                    }
                }
                else if (isboolOprtr(sub) == true)
                {
                    if(strcmp(sub,"and")==0)
                    {
                        keep.push_back(make_pair("And",st));
                    }
                    else if(strcmp(sub,"or")==0)
                    {
                        keep.push_back(make_pair("Or",st));
                    }
                    else
                    {
                        keep.push_back(make_pair("Not",st));
                    }
                }
                else if (isSpcOprtr1(sub) == true)
                {
                    if(strcmp(sub,"is")==0)
                    {
                        keep.push_back(make_pair("Is",st));
                    }
                    else
                    {
                        keep.push_back(make_pair("IsNot",st));
                    }
                }
                else if (isSpcOprtr2(sub) == true)
                {
                    if(strcmp(sub,"in")==0)
                    {
                        keep.push_back(make_pair("In",st));
                    }
                    else
                    {
                        keep.push_back(make_pair("NotIn",st));
                    }
                }
                else if (validId(sub) == true
                && isPunc(str[right - 1]) == false)
                {
                    keep.push_back(make_pair("Valid Identifier",st));
                }
                else if (validId(sub) == false
                && isPunc(str[right - 1]) == false)
                {
                    keep.push_back(make_pair("Non-Valid Identifier",st));
                }
            }

            left = right;
            }
    }
    return;
}