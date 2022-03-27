#include<bits/stdc++.h>
#include"tokenizer.h"
#include"stringManipulate.h"
using namespace std;

string commentDel(string code)
{
    int n = code.length();
    string temp;
 
    bool single = false;
 
    for (int i=0; i<n; i++)
    {
        if (single == true && code[i] == '\n')
        {
            single = false;
        }
 
        else if (single)
        {
            continue;
        }
 
        else if (code[i] == '#')
        {
            single = true, i++;
        }
        else 
        {
            temp += code[i];
        }
    }
    return temp;
}

string commentDelmulti(string code)
{
    int n = code.length(),i;
    string temp;

    bool multiple = false;
 
    for (i=0; i<n-2; i++)
    {
        if (multiple == false && code[i] == '"' && code[i+1] == '"' && code[i+2] == '"')
        {
            multiple = true;  i=i+2;
        }

        else if (multiple == true && code[i] == '"' && code[i+1] == '"' && code[i+2] == '"')
        {
            multiple = false; i=i+2;
        }
 
        else if (multiple)
        {
            continue;
        }
 
        else 
        {
            temp += code[i];
        }
    }
    temp += code[i];
    temp += code[i+1];
    temp += code[i+2];
    return temp;
}

string replaceTab(string code)
{
    int n = code.length(),i;
    string temp;
 
    for (i=0; i<n-3; i++)
    {
        if(code[i]==' ' && code[i+1]==' ' && code[i+2]==' ' && code[i+3]==' ')
        {
            temp +='\t';
            i=i+3;
        }
        else
        {
            temp += code[i];
        }
    }
    temp += code[i];
    temp += code[i+1];
    temp += code[i+2];
    temp += code[i+3];
    return temp;

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
    temp= replaceTab(string_wthoutCom);
    char c[temp.size()+1];
    strcpy(c, temp.c_str());
    token_making_andParse(c);
    return 0;
}