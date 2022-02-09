#include <bits/stdc++.h>
using namespace std;

vector<string>tokenList;

int main()
{
    string inString;
    int i;
    //freopen("spl_democode.txt","r",stdin);
    getline(cin,inString);             //for input from file
    //cout<<inString;
    string temp = "";
	for(int i=0;i<inString.length();i++){
		
		if(inString[i]==' '){
			tokenList.push_back(temp);
			temp = "";
		}
		else{
			temp.push_back(inString[i]);
		}
		
	}
	tokenList.push_back(temp);
   for(i=0;i<tokenList.size();i++)
   {
           cout << tokenList[i]<<endl;
   }
    return 0;
}