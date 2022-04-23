#include<bits/stdc++.h>
#include"stringM.h"
#include"commentM.h"
#include"tabReplace.h"
#include"tokenMaker.h"
#include"ast.h"

using namespace std;

int Cnt=0,ln=1;

void token_making_andParse(char* str)
{
    int left = 0, right = 0;
    int len = strlen(str);
    int indent=0;
    while (right <= len && left <= right)
    {
        keep.push_back(keepData());
        if(str[right]=='\n')
        {
            ln++;
            indent=0;
        }
        if(str[right]=='\t')
        {
            indent++;
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
                    string a;
                    a.push_back(str[right]);
                    a.push_back(str[right+1]);
                    keep[Cnt].line =ln;
                    keep[Cnt].indentation =indent;
                    keep[Cnt].expression =a;
                    keep[Cnt].dataType ="Operator";
                    Cnt++;
                }
                if (isOperator(str[right]) == true && isOperator(str[right+1]) == false)
                {
                    cnt=1;
                    if(str[right]=='\t')
                    {
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression ="->";
                        keep[Cnt].dataType ="Indentation";
                        switch (str[right])
                        {
                            case '+':
                            keep[Cnt].value="Add";

                            case '-':
                            keep[Cnt].value="Sub";
                           
                            case '*':
                            keep[Cnt].value="Mult";
                           
                            case '/':
                            keep[Cnt].value="Div";
                           
                            case '=':
                            keep[Cnt].value="Assign";
                           
                            default:
                                break;
                        }
                    }
                    else
                    {
                        string a;
                        a.push_back(str[right]);
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="Operator";
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
                    keep[Cnt].indentation =indent;
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
                    keep[Cnt].indentation =indent;
                    keep[Cnt].expression =st;
                    keep[Cnt].dataType ="Keyword";
                }
                else if (isInt(sub) == true)
                {
                    int z=0;
                    keep[Cnt].line =ln;
                    keep[Cnt].indentation =indent;
                    keep[Cnt].expression =st;
                    keep[Cnt].dataType ="Integer";
                }

                else if (isDouble(sub) == true)
                {
                    int z=0;
                    keep[Cnt].line =ln;
                    keep[Cnt].indentation =indent;
                    keep[Cnt].expression =st;
                    keep[Cnt].dataType ="Double";
                }

                else if (isOprtr2(sub) == true)
                {
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =st;
                        keep[Cnt].dataType ="Operator";
                }
                else if (validId(sub) == true
                && isPunc(str[right - 1]) == false)
                {
                    keep[Cnt].line =ln;
                    keep[Cnt].indentation =indent;
                    keep[Cnt].expression =st;
                    keep[Cnt].dataType ="Valid Identifier";
                }
                else if (validId(sub) == false
                && isPunc(str[right - 1]) == false)
                {
                    keep[Cnt].line =ln;
                    keep[Cnt].indentation =indent;
                    keep[Cnt].expression =st;
                    keep[Cnt].dataType ="Non Valid Identifier";
                }
            }
            left = right;
            Cnt++;
        }
           
    }
   
}

int main()
{
    cout<<"Enter the name of the file: "<<endl;
    string fileName;
    cin>>fileName;
    char input[5000];
    int j=0;
    ifstream inFile(fileName.c_str());
    if(inFile.fail())
    {
        cout<<"File does not exist!"<<endl;
    }
    else
    {
        freopen(fileName.c_str(),"r",stdin);
        scanf("%[^\0]s",&input);
    }
    string instring= convertToString(input,strlen(input));
    string temp =commentDel(instring);
    string string_wthoutCom =commentDelmulti(temp);
    temp.clear();
    temp= replaceTab(string_wthoutCom);
    char c[temp.size()+1];
    strcpy(c, temp.c_str());
    token_making_andParse(c);
    ofstream out_file("t.txt");
    if (!out_file) {
        cout << "File not created!";
    }
    else
    {
        for(int i=0;i<Cnt;i++)
        {
            out_file<<keep[i].line<<"\t"<<keep[i].indentation<<"\t"<<keep[i].expression<<"\t\t"<<keep[i].dataType<<endl;
        }
        out_file.close();
    }
    lineMaking();
    return 0;
}