#include <bits/stdc++.h>
using namespace std;
vector<pair<string,string>> keep;
vector<string> keywords;
void keywordList()
{
    keywords.push_back("if");
    keywords.push_back("else");
    keywords.push_back("while");
    keywords.push_back("do");
    keywords.push_back("break");
    keywords.push_back("continue");
    keywords.push_back("return");
    keywords.push_back("input");
    keywords.push_back("print");
    keywords.push_back("True");
    keywords.push_back("False");
}
string convertToString(char* a, int size);
string commentDel(string code);
bool isPunc(char ch);
bool validId(char* str);
bool isOperator(char ch);
bool isOperatorduplicate(char ch);
bool isKeyword(char *str);
bool isNumber(char* str);
char* subString(char* realStr, int l, int r);
void parse(char* str);

string convertToString(char* charArray, int size)
{
    int i;
    string convStr = "";
    for (i = 0; i < size; i++) {
        convStr = convStr + charArray[i];
    }
    return convStr;
}

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
    int n = code.length();
    string temp;

    bool multiple = false;
 
    for (int i=0; i<n-2; i++)
    {
        if (multiple == false && code[i] == '"' && code[i+1] == '"' && code[i+2] == '"')
        {
            multiple = true,  i=i+3;
        }

        else if (multiple == true && code[i] == '"' && code[i+1] == '"' && code[i+2] == '"')
        {
            multiple = false;
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
    return temp;
}

bool isPunc(char ch)
{		
    switch (ch)
    {
        case '+':
        return true;

        case '-':
        return true;

        case '*':
        return true;
        
        case '/':
        return true;

        case ',':
        return true;
        
        case ';':
        return true;

        case '>':
        return true;
        
        case '<':
        return true;

        case '=':
        return true;
        
        case '(':
        return true;

        case ')':
        return true;
        
        case '|':
        return true;

        case '&':
        return true;
        
        case '[':
        return true;

        case ']':
        return true;

        case '"':
        return true;
        
        case '\n':
        return true;
    
        default:
        return false;
    }
}

bool validId(char* str)
{
    char temp=str[0];
    switch (temp)
    {
        case '0':
        return false;

        case '1':
        return false;

        case '2':
        return false;
        
        case '3':
        return false;

        case '4':
        return false;
        
        case '5':
        return false;

        case '6':
        return false;
        
        case '7':
        return false;

        case '8':
        return false;
        
        case '9':
        return false;
        
    }
    if(ispunct(temp))
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
    switch (ch)
    {
        case '+':
        return true;

        case '-':
        return true;

        case '*':
        return true;
        
        case '/':
        return true;

        case '>':
        return true;
        
        case '<':
        return true;

        case '|':
        return true;

        case '&':
        return true;

        case '=':
        return true;

        default:
        return false;
    }
}

bool isOperatorduplicate(char ch)
{
    switch (ch)
    {
        case '+':
        return true;

        case '-':
        return true;

        case '|':
        return true;

        case '&':
        return true;

        case '=':
        return true;

        default:
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
    if(counter>0)
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
    for (i = 0 ; i < len ; i++)
    {
        char temp= str[i];
        if (numOfDecimal > 1 && str[i] == '.')
        {
            return false;
        } else if (numOfDecimal <= 1)
        {
            numOfDecimal++;
        }
     
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9' || (str[i] == '-' && i > 0))
            {
                return false;
            }
    }
    return true;
}

char* subString(char* realStr, int l, int r)				
{
    int i;

    char* str = (char*) malloc(sizeof(char) * (r - l + 2));

    for (i = l; i <= r; i++)
    {
        str[i - l] = realStr[i];
        str[r - l + 1] = '\0';
    }
    return str;
}

void parse(char* str)
{
    int left = 0, right = 0;
    int len = strlen(str);
    while (right <= len && left <= right) {
        if(str[right]=='\\' && str[right+1]=='n')
        {
            continue;
        }
        else
        {
        if (isPunc(str[right]) == false)
            {
                right++;
            }

        if (isPunc(str[right]) == true && left == right)
            {
            if (isOperator(str[right]) == true)
            {
                  char az=str[right];
                  string a;
                  a.push_back(az);
                keep.push_back(make_pair("OPERATOR",a));
            }
            right++;
            left = right;
            } else if (isPunc(str[right]) == true && left != right
                   || (right == len && left != right))
            {
            char* sub = subString(str, left, right - 1);
            string str(sub);

            if (isKeyword(sub) == true)
                        {
                              keep.push_back(make_pair("KEYWORD",str));
                        }
            else if (isNumber(sub) == true)
                        {
                            keep.push_back(make_pair("NUMBER",str));
                        }
            else if (validId(sub) == true
                     && isPunc(str[right - 1]) == false)
                     {
                         keep.push_back(make_pair("Valid Identifier",str));
                     }
            else if (validId(sub) == false
                     && isPunc(str[right - 1]) == false)
                     {
                         keep.push_back(make_pair("Non-Valid Identifier",str));
                     }

            left = right;
            }
    }
    }
    return;
}

int main()
{
    char input[5000];
    int j=0;
    freopen("spl_democode.txt","r",stdin);
    scanf("%[^\0]s",&input);
    string instring = convertToString(input, strlen(input));
    string temp =commentDel(instring);
    string string_wthoutCom =commentDelmulti(temp);
    char c[string_wthoutCom.size()+1];
    strcpy(c, string_wthoutCom.c_str());
    parse(c);
    for(int i=0;i<keep.size();i++)
    {
          cout<<keep[i].first<<": "<<keep[i].second<<endl;
    }
    return 0;
}