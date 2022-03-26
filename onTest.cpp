#include<bits/stdc++.h>
using namespace std;

int Cnt=0,ln=1;

struct keepData
{
    int line;
    int indentation;
    string expression;
    string dataType;
};

vector<keepData>keep;

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

string convertToString(char* charArray, int size)
{
    int i;
    string convStr = "";
    for (i = 0; i < size; i++) {
        convStr = convStr + charArray[i];
    }
    return convStr;
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

vector<string>keywords;
vector<char>digit;
vector<char>punc;
vector<char>oprtr;
vector<string>boolOprtr;
vector<string>spcOprtr1;
vector<string>spcOprtr2;

void keywordList()
{
    keywords.push_back("If");
    keywords.push_back("print");
    keywords.push_back("For");
    keywords.push_back("AsyncFor");
    keywords.push_back("While");
    keywords.push_back("With");
    keywords.push_back("AsyncWith");
    keywords.push_back("Raise");
    keywords.push_back("Match");
    keywords.push_back("Try");
    keywords.push_back("Assert");
    keywords.push_back("Import");
    keywords.push_back("Global");
    keywords.push_back("Nonlocal");
    keywords.push_back("Pass");
    keywords.push_back("Break");
    keywords.push_back("Continue");
    keywords.push_back("Return");
    keywords.push_back("Delete");
    keywords.push_back("Assign");
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

void token_making_andParse(char* str)
{
    callFunc();
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
                    if(str[right]=='>' && str[right+1]=='=' )
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="GtE";
                    }
                    else if(str[right]=='>' && str[right+1]=='=' )
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="LtE";
                    }
                    else if(str[right]=='!' && str[right+1]=='=')
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="NotEq";
                    }
                    else if(str[right]=='=' && str[right+1]=='=')
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="Eq";
                    }
                    else if(str[right]=='*' && str[right+1]=='*')
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="Pow";
                    }
                    else if(str[right]=='/' && str[right+1]=='/')
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="FloorDiv";
                    }
                    else if(str[right]=='>' && str[right+1]=='>')
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="RShift";
                    }
                    else if(str[right]=='<' && str[right+1]=='<')
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="LShift";
                    }
                    else if(str[right]=='+' && (str[right]=='+' || str[right+1]=='='))
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="Incerement";
                    }
                    else if(str[right]=='-' && (str[right]=='-' || str[right+1]=='='))
                    {
                        string a;
                        a.push_back(str[right]);
                        a.push_back(str[right+1]);
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
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
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="Gt";
                    }
                    else if(str[right]=='<')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="Lt";
                    }
                    else if(str[right]=='=')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="Assignment";
                    }
                    else if(str[right]=='+')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="Add";
                    }
                    else if(str[right]=='-')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="Sub";
                    }
                    else if(str[right]=='*')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="Mult";
                    }
                    else if(str[right]=='/')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="Div";
                    }
                    else if(str[right]=='%')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="Mod";
                    }
                    else if(str[right]=='&')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="BitAnd";
                    }
                    else if(str[right]=='|')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="BitOr";
                    }
                    else if(str[right]=='^')
                    {
                        string a;
                        a.push_back(str[right]);
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =a;
                        keep[Cnt].dataType ="BitXor";
                    }
                    else if(str[right]=='\t')
                    {
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
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

                else if (isboolOprtr(sub) == true)
                {
                    if(strcmp(sub,"and")==0)
                    {
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =st;
                        keep[Cnt].dataType ="And";
                    }
                    else if(strcmp(sub,"or")==0)
                    {
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =st;
                        keep[Cnt].dataType ="Or";
                    }
                    else
                    {
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =st;
                        keep[Cnt].dataType ="Not";
                    }
                }
                else if (isSpcOprtr1(sub) == true)
                {
                    if(strcmp(sub,"is")==0)
                    {
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =st;
                        keep[Cnt].dataType ="Is";
                    }
                    else
                    {
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =st;
                        keep[Cnt].dataType ="IsNot";
                    }
                }
                else if (isSpcOprtr2(sub) == true)
                {
                    if(strcmp(sub,"in")==0)
                    {
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =st;
                        keep[Cnt].dataType ="In";
                    }
                    else
                    {
                        keep[Cnt].line =ln;
                        keep[Cnt].indentation =indent;
                        keep[Cnt].expression =st;
                        keep[Cnt].dataType ="NotIn";
                    }
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
    return 0;
}
