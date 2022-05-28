#include<bits/stdc++.h>
#include"stringM.h"
#include"commentM.h"
#include"tabReplace.h"
#include"tokenMaker.h"

using namespace std;

int Cnt=0,ln=1;
vector<vector<int>> hold;

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
                    }
                    else
                    {
                        string a;
                        a.push_back(str[right]);
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="Operator";
                        if(str[right]=='+')
                        {
                            keep[Cnt].value="Add";
                        }
                        if(str[right]=='-')
                        {
                            keep[Cnt].value="Sub";
                        }   
                        if(str[right]=='*')
                        {
                            keep[Cnt].value="Mult";
                        }
                        if(str[right]=='/')
                        {
                            keep[Cnt].value="Div";
                        }
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

int t=0,line;

void getHold()
{
    int i=0,j=0;
    vector<int> temp;
    while(i<Cnt)
    {
        temp.push_back(i);
        i++;
        if((keep[i].line) != (keep[i-1].line))
        {
            hold.push_back(temp);
            temp.clear();
            j++;
        }
    }
    line=j;
}

void tab()
{
    t++;
    for(int k=0;k<=t;k++)
    {
        cout<<" ";
    }
}

void binOp(string left,int oper,vector<int>v, int start,int ending)
{
    bool var=false,op=false;
    if(start==0)
    {
        t=1;
    }
    tab();cout<<"BinOp:"<<endl;
    tab();cout<<"left: "<<left<<endl;
    t--;tab();cout<<"op: "<<keep[oper].value<<endl;
    t--;tab();cout<<"right: ";
    int a=start;
    while(a<=ending)
    {
        if(a==ending)
        {
            cout<<keep[a].expression<<endl;
        }
        else
        {
            if((keep[a].dataType=="Valid Identifier"|| keep[a].dataType=="Integer" || keep[a].dataType=="Double") && keep[a+1].dataType=="Operator" )
            {
                if(var==false)
                {
                    var=true;
                }
                if(var==true)
                {
                    cout<<endl;
                    binOp(keep[a].dataType,a+1,v,a+2,(a+v.size())-2);
                    var= false;
                    a=ending;
                }
            }
            
        }
        a++;
    }
    cout<<endl;
}

void assign(string left,vector<int>v, int start,int ending)
{
    if(start<1)
    {
        t=2;
    }
    tab();cout<<"Assign:"<<endl;
    tab();cout<<"targets: "<<endl;
    tab();cout<<"0: "<<endl;
    tab();cout<<"name: "<<endl;
    tab();cout<<"ctx: Store"<<endl;
    t--;tab();cout<<"id: "<<left<<endl;
    t=t-2;tab();cout<<"value: "<<endl;
    tab();cout<<"constant: "<<endl;
    t--;tab();cout<<"kind: null"<<endl;
    t--;tab();cout<<"value: ";
    int a=start;
    while(a<=ending)
    {
        if(a==ending)
        {
            cout<<keep[a].expression;
        }
        if(keep[a].dataType=="Valid Identifier" || keep[a].dataType=="Integer" || keep[a].dataType=="Double")
        {
            if(keep[a+1].dataType=="Operator" && keep[a+1].expression !="=")
            {
                cout<<endl;
                binOp(keep[a].expression,a+1,v,a+2,(a+v.size()-3));
                a=ending;
            }
        }
        a++;
    }
    cout<<endl;
}

void priPrnt(string left,vector<int>v, int start,int ending)
{
    t=2;
    int countt=0;
    bool var=false,op=false;
    tab();cout<<"Expr:"<<endl;
    tab();cout<<"Value:"<<endl;
    tab();cout<<"Call:"<<endl;
    tab();cout<<"args:"<<endl;
    int a= start;
    while(a<=ending)
    {
        int zz= v[a];
        
        if(keep[zz].dataType == "String_Literal")
        {
            if(countt>0)
            {
                t=t-2;
            }
            tab();cout<<countt<<":"<<endl;
            tab();cout<<"Constant:"<<endl;
            tab();cout<<"kind: null"<<endl;
            t--;tab();cout<<"value:\""<<keep[zz].expression<<"\""<<endl;
            countt++;
        }
        else if(keep[zz].dataType == "Valid Identifier"|| keep[zz].dataType=="Integer" || keep[zz].dataType=="Double")
        {
            if(countt>0)
            {
                t=t-2;
            }
            if(a==ending || (keep[zz-1].dataType!="Operator" && keep[zz+1].dataType!="Operator"))
            {
                tab();cout<<countt<<":"<<endl;
                tab();cout<<"Constant:"<<endl;
                tab();cout<<"kind: load"<<endl;
                t--;tab();cout<<"ctx:\""<<keep[zz].expression<<"\""<<endl;
            }
            else if(keep[zz+1].dataType=="Operator")
            {
                tab();cout<<countt<<":"<<endl;
                binOp(keep[zz].expression,zz+1,v,zz+2,(zz+v.size()-2));
                a=ending;
            }
            countt++;
        }
        a++;
    }
    t=t-3;tab();cout<<"func: "<<endl;
    tab();cout<<"Name: "<<endl;
    tab();cout<<"ctx: Load"<<endl;
    t--;tab();cout<<"id: "<<left<<endl;
    countt=0;
}

void makeTree()
{
    int i=0,j=0,tmp,x,counter=0;
    vector<int>v;
    bool op=false,var=false;
    while(j<line)
    {
        for(x=0;x<hold[j].size();x++)
        {
            v.push_back(hold[j][x]);
        }
        while(i<x)
        {
            tmp= hold[j][i];
            if(keep[tmp].dataType == "Keyword")
            {
                cout<<" "<<counter<<":"<<endl;
                counter++;
                t=1;
                if(keep[tmp].expression == "print")
                {
                    i++;
                    priPrnt(keep[tmp].expression,v,i,(i-1+v.size()-1));
                    i=x-1;
                }
            }
            if(keep[tmp].dataType == "Operator")
            {
                cout<<" "<<counter<<":"<<endl;
                counter++;
                t=1;
                if(keep[tmp].expression != "=")
                {
                    binOp(keep[tmp-1].expression,tmp,v,tmp+1,(tmp+1+v.size()));
                    i=x-1;
                    
                }
                else
                {
                    assign(keep[tmp-1].expression,v,tmp+1,(tmp+1+v.size()-3));
                    i=x-1;
                }
            }
            i++;
        }
        i=0;
        v.clear();
        j++;
    }
}

void moduleM()
{
    cout<<"Module:"<<endl;
    tab();cout<<"body: "<<endl;
    makeTree();
    
    cout<<"\ttype_ignores: "<<endl;
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
        return 0;
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
    getHold();
    moduleM();
    return 0;
}