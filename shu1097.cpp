#include<iostream>
#include<string>

using namespace std;

int main()

{
    string s;
    while(getline(cin,s))
    {
        int tom = 0;
        for(char x :s)
        {
            tom+=x-'0';
        }
        cout<<tom<<endl;
    }
}
