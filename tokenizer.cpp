#include <bits/stdc++.h>
using namespace std;
vector<pair<string,string>> keep;

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

string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

string commentDel(string code)
{
    int n = code.length();
    string temp;
 
    bool single = false;
    bool multiple = false;
 
    for (int i=0; i<n; i++)
    {
        if (single == true && code[i] == '\n')
        {
            single = false;
        }
        // else if (multiple == false && code[i-1] == '"' && code[i] == '"' && code[i+1] == '"')
        // {
        //     multiple = true,  i=i+2;
        // }
        // else if (multiple == true && code[i-1] == '"' && code[i] == '"' && code[i+1] == '"')
        // {
        //         multiple = false;
        // }
 
        else if (single)// || multiple)
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

// bool onlyQuote(string line)
// {
//     string s="print";
//     for(int i=0; i<5; i++)
//         if(s[i]!=line[i])
//             return 0;
//     return 1;
// }

bool isPunc(char ch)
{		
   if ( ch == ' ' || ch == '+' || ch == '-' ||
        ch == '*' || ch == '/' || ch == ',' ||
        ch == ';' || ch == '>' || ch == '<' ||
        ch == '=' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' ||
        ch == '}' || ch == '&' || ch == '|' ||
        ch=='\n')//"\n" is counted as one character
        {
            return true;
        }
    return false;
}

bool validId(char* str)
{
    if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
        str[0] == '3' || str[0] == '4' || str[0] == '5' ||
        str[0] == '6' || str[0] == '7' || str[0] == '8' ||
        str[0] == '9' || isPunc(str[0]) == true)
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
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '>' || ch == '<' ||
        ch == '=' || ch == '|' || ch == '&')
    {
       return true;
    }
    return false;
}

bool isOperatorduplicate(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '>' || ch == '<' ||
        ch == '=' || ch == '|' || ch == '&')
    {
       return true;
    }
    return false;
}

bool isKeyword(char *str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") ||
        !strcmp(str, "break") ||  !strcmp(str, "continue")
        || !strcmp(str, "return") || !strcmp(str,"input")
        || !strcmp(str, "switch")|| !strcmp(str, "True")
        || !strcmp(str, "print") || !strcmp(str, "False")
        )
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
    char d[5000];
    int j=0;
    freopen("spl_democode.txt","r",stdin);
    scanf("%[^\0]s",&d);
    string sd = convertToString(d, strlen(d));
    string s =commentDel(d);
    char c[s.size()+1];
    strcpy(c, s.c_str());
    parse(c);
    for(int i=0;i<keep.size();i++)
    {
          cout<<keep[i].first<<": "<<keep[i].second<<endl;
    }
    return 0;
}
