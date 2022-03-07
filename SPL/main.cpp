#include"header.h"

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