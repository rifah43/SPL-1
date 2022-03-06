#include<bits/stdc++.h>
using namespace std;

vector<pair<string,string>> keep;
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
     
        if (isDigit(str[i])==false || (str[i] == '-' && i > 0))
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
                    keep.push_back(make_pair("NUMBER",st));
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
int main()
{
    cout<<"Enter the name of the file: "<<endl;
    string fileName;
    cin>>fileName;
    char input[5000];
    callFunc();
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
    char c[string_wthoutCom.size()+1];
    strcpy(c, string_wthoutCom.c_str());
    parse(c);
    for(int i=0;i<keep.size();i++)
    {
          cout<<keep[i].first<<": "<<keep[i].second<<endl;
    }
    return 0;
}