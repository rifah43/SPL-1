#include<bits/stdc++.h>
using namespace std;

vector<int> Line;
vector<vector<string>> hold;
int j=0;

void binOp(string left,string op, string right);
void assign(string left, string right);
void priPrnt(string left,vector<string> right);
void check(vector<string> tok);

template<typename T>
vector<T> subVec(vector<T> const &vc, int m, int n)
{
    auto first = vc.cbegin() + m;
    auto last = vc.cbegin() + n + 1;
 
    vector<T> vec(first, last);
    return vec;
}

int t=0,ln;

void tab()
{
    t++;
    for(int k=0;k<=t;k++)
    {
        cout;
    }
}

void check(vector<string> tok)
{
    int i=0;
    while(i<tok.size())
    {
        if(isOperator(tok[i])==true || isOprtr2(tok[i])==true)
        {
            if(tok[i]=="=")
            {
                assign(tok[i-1],subVec(tok,i+1,tok.size()));
            }
            else if(tok[i]=="+" || tok[i]=="-" tok[i]=="*" || tok[i]=="/")
            {
                binOp(tok[i-1],tok[i], subVec(tok,i+1,tok.size()))
            }
            i++;
        }
        else if(isKeyword(tok[i])==true)
        {
            
            i++;
        }
        else
        {
            cout<<tok[i];
            i++;
        }
    }
}

void binOp(string left,string op, vector<string> right)
{
    t=1;
    tab();cout<<"BinOp:"<<endl;
    tab();cout<<"left: "<<left<<endl;
    t--;tab();cout<<"op: "<<op<<endl;
    t--;tab();cout<<"right: ";
    check(right);
    cout<<endl;
}

void assign(string left, vector<string> right)
{
    t=1;
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
    check(right);
    cout<<endl;

}

void priPrnt(string left,vector<string> right)
{
    tab();cout<<"Expr:"<<endl;
    tab();cout<<"\tValue:"<<endl;
    tab();cout<<"Call:"<<endl;
    tab();cout<<"args:"<<endl;
    tab();cout<<"0:"<<endl;
    if(isOperator(right[0])==true)
    {
        check(right);
    }

    else
    {
        tab();cout<<"Constant:"<<endl;
        tab();cout<<"kind: null"<<endl;
        t--;tab();cout<<"value: "<<right<<endl;
    }

    t=t-3;tab();cout<<"func: "<<endl;
    tab();cout<<"Name: "<<endl;
    tab();cout<<"ctx: Load"<<endl;
    t--;tab();cout<<"id: "<<left<<endl;
}

void makeTree()
{
    int i=0;j=0;

    while(i<=ln)
    {
        if(isKeyword(hold[i][j])==true)
        {
            if(hold[i][j]=="print")
            {
                j++;
                priPrint(hold[i][j-1],subVec(hold[i],j ,(hold[i].size()-1)));
            }
        }
        else if(isOperator(hold[i][j])==false || isOprtr2(hold[i][j])==false || isKeyword(hold[i][j])==false )
        {
            while ((isOperator(hold[i][j])==false || isOprtr2(hold[i][j])==false || isKeyword(hold[i][j])==false) && j<hold[i].size())
            {
                j++;
            }
        }
        else if(isOperator(hold[i][j])==true || isOprtr2(hold[i][j])==true)
        {
            if(hold[i][j]=="+" || hold[i][j]=="-" || hold[i][j]=="*" || hold[i][j]=="/")
            {
                binOp(hold[i][j-1], hold[i][j], subVec(hold[i], j, (hold[i].size()-1)));
            }
            else if(hold[i][j]=="=")
            {
                assign(hold[i][j-1], subVec(hold[i], j, (hold[i].size()-1)));
            }
        }
    }

}

void moduleM()
{
    tab();
    cout<<"body: "<<endl;
    makeTree();
    
    cout<<"\ttype_ignores: "<<endl;
}

void lineMaking()
{
    int i=0,j=0;
    hold[j].push_back(keep[i].expression);
    Line.push_back(keep[i].indentation);
    while(i<Cnt)
    {
        if(i>0 &&(keep[i].line)!=(keep[i-1].line))
        {
            j++;
            cout<<"\t"<<j<<":"<<endl<<"\t";
        }
        else
        {
            hold[j].push_back(keep[i].expression);
            Line.push_back(keep[i].indentation);
        }
        i++;
    }
    ln=j;
    moduleM();
}