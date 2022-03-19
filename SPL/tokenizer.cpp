#include<bits/stdc++.h>
#include"tokenCheck.h"
#include"stringManipulate.h"
#include"tokenizer.h"
using namespace std;

int Cnt=0,ln=1;

struct keepData
{
    int line;
    string expression;
    string dataType;
};

vector<keepData>keep;

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

string convertToString(char* charArray, int size)
{
    int i;
    string convStr = "";
    for (i = 0; i < size; i++) {
        convStr = convStr + charArray[i];
    }
    return convStr;
}

void token_making(char* str)
{
    callFunc();
    int left = 0, right = 0;
    int len = strlen(str);
    while (right <= len && left <= right)
    {
        keep.push_back(keepData());
        if(str[right]=='\n')
        {
            ln++;
        }
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
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="GtE";
                    }
                    else if(str[right]=='>' && str[right+1]=='=' )
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="LtE";
                    }
                    else if(str[right]=='!' && str[right+1]=='=')
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="NotEq";
                    }
                    else if(str[right]=='=' && str[right+1]=='=')
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="Eq";
                    }
                    else if(str[right]=='*' && str[right+1]=='*')
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="Pow";
                    }
                    else if(str[right]=='/' && str[right+1]=='/')
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="FloorDiv";
                    }
                    else if(str[right]=='>' && str[right+1]=='>')
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="RShift";
                    }
                    else if(str[right]=='<' && str[right+1]=='<')
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="LShift";
                    }
                    else if(str[right]=='+' && (str[right]=='+' || str[right+1]=='='))
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="Incerement";
                    }
                    else if(str[right]=='-' && (str[right]=='-' || str[right+1]=='='))
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="Decrement";
                    }
                    Cnt++;
                }
                if (isOperator(str[right]) == true && isOperator(str[right+1]) == false)
                {
                    cnt=1;
                    if(str[right]=='>')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="Gt";
                    }
                    else if(str[right]=='<')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="Lt";
                    }
                    else if(str[right]=='=')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="Assignment";
                    }
                    else if(str[right]=='+')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="Add";
                    }
                    else if(str[right]=='-')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="Sub";
                    }
                    else if(str[right]=='*')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="Mult";
                    }
                    else if(str[right]=='/')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="Div";
                    }
                    else if(str[right]=='%')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="Mod";
                    }
                    else if(str[right]=='&')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="BitAnd";
                    }
                    else if(str[right]=='|')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="BitOr";
                    }
                    else if(str[right]=='^')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="BitXor";
                    }
                    else if(str[right]=='\t')
                    {
                        keep[Cnt].line =ln;
                        keep[Cnt].expression ="->";
                        keep[Cnt].dataType ="Indentation";
                    }
                    Cnt++;
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
                if(str[left-1]=='"')
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
                    keep[Cnt].line =ln;
                    keep[Cnt].expression =temp;
                    keep[Cnt].dataType ="String_Literal";
                }
            
            else
            {
                char* sub = subString(str, left, right - 1);
                string st= convertToString(sub,strlen(sub));
                if (isKeyword(sub) == true)
                {
                    keep[Cnt].line =ln;
                    keep[Cnt].expression =st;
                    keep[Cnt].dataType ="Keyword";
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
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =st;
                        keep[Cnt].dataType ="Double";
                    }
                    else
                    {
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =st;
                        keep[Cnt].dataType ="Integer";
                    }
                }
                else if (isboolOprtr(sub) == true)
                {
                    if(strcmp(sub,"and")==0)
                    {
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =st;
                        keep[Cnt].dataType ="And";
                    }
                    else if(strcmp(sub,"or")==0)
                    {
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =st;
                        keep[Cnt].dataType ="Or";
                    }
                    else
                    {
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =st;
                        keep[Cnt].dataType ="Not";
                    }
                }
                else if (isSpcOprtr1(sub) == true)
                {
                    if(strcmp(sub,"is")==0)
                    {
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =st;
                        keep[Cnt].dataType ="Is";
                    }
                    else
                    {
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =st;
                        keep[Cnt].dataType ="IsNot";
                    }
                }
                else if (isSpcOprtr2(sub) == true)
                {
                    if(strcmp(sub,"in")==0)
                    {
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =st;
                        keep[Cnt].dataType ="In";
                    }
                    else
                    {
                        keep[Cnt].line =ln;
                        keep[Cnt].expression =st;
                        keep[Cnt].dataType ="NotIn";
                    }
                }
                else if (validId(sub) == true
                && isPunc(str[right - 1]) == false)
                {
                    keep[Cnt].line =ln;
                    keep[Cnt].expression =st;
                    keep[Cnt].dataType ="Valid Identifier";
                }
                else if (validId(sub) == false
                && isPunc(str[right - 1]) == false)
                {
                    keep[Cnt].line =ln;
                    keep[Cnt].expression =st;
                    keep[Cnt].dataType ="Non Valid Identifier";
                }
            }
            left = right;
            Cnt++;
        }
            
    }
    ofstream out_file("tokens.txt");
    
	if (!out_file) {
		cout << "File not created!";
	}
	else
    {
        for(int i=0;i<Cnt;i++)
        {
            out_file<<keep[i].line<<"\t"<<keep[i].expression<<"\t\t"<<keep[i].dataType<<endl;
        }
		out_file.close();
	}
    return;
}