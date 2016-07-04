#include<iostream>

using namespace std;


int main()
{
    int mon = 1,save = 0,balance = 0,budget;
    int first = 0;
    while(cin>>budget)
    {
        balance = balance +300 - budget;
        if(balance <0)
        {
            if(!first)
                first = mon;
        }
        save += balance/100 * 100;
        balance %= 100;
        if(mon++ ==12)
        {
            if(first)
            {
                cout<<-first<<endl;
            }
            else
            {
                cout<<balance + save/5 + save<<endl;
            }
            mon = 1;
            save = 0;
            balance =0;
            first = 0;
        }
    }
}
