#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;

int main()
{
    string b("bob");
    string in;
    while(cin>>in)
    {
        int t;
        for_each(in.begin(),in.end(),[](char &c){c = tolower(c);});
        if((t = in.find(b))!=string::npos)
        {
            cout<<t<<endl;
        }
        else
            cout<<-1<<endl;
    }
}
