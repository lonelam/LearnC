#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;
class bint
{
private:
    typedef long long ll;
    vector<ll> ds;
    static const ll R_W = 9;
    static const ll R_M = 1000000000;
    void cut()
    {
        while(ds.back()==0)
        {
            ds.pop_back();
        }
    }
    void update()
    {
        for(int i=0;i<len();i++)
        {
            if(ds[i]>=R_M)
            {
                ds[i+1] = ds[i]/R_M;
                ds[i] %= R_M;
            }
        }
    }
public:
    bint() { }
    bint(ll x): ds(1,x) { }
    bint(string & s):ds(s.length()/R_W+1)
    {
        int slen = s.length();
        int i,first = slen%R_W;
        int bit = slen / R_W ;
        ll temp = 0;
        for(i=0;i<first;i++)
        {
            temp *= 10;
            temp += s[i] -'0';

        }
        ds[bit--] = temp;

        while(i<slen)
        {

            temp = 0;
            int j = i;
            i+=R_W;
            for(; j < i;j++)
            {
                temp *= 10;
                temp += s[j] - '0';
            }
            ds[bit--] = temp;
        }
        cut();
    }
    size_t len() { return ds.size();}

    string  str()
    {
        string str;
        bool star = false;
        for_each(ds.rbegin(),ds.rend(),[&str,&star](ll data)
        {
            if(!star)
            {
                str = to_string(data);
                star = true;
            }
            else
            {
                string temp = to_string(data);
                int zeros = 0;
                while(zeros + temp.length()!=R_W)
                {
                    zeros++;
                    str.push_back('0');
                }
                str.append(temp);
            }
        });
        return str;
    }
    bint operator + (bint & b)
    {

        if(len()>b.len())
        {
            return b + (*this);
        }
        bint ans(b);
        ans.ds.push_back(0);
        for (int i = 0;i<len();i++)
        {
            ans.ds[i] += ds[i];
        }
        update();
        cut();
        return ans;
    }
    friend istream &operator>>(istream & is, bint & bb);
};

istream &operator>>(istream & is,bint & bb)
{
    string temp;
    is>>temp;
    bb = bint(temp);
    return is;
}
int main()
{
    const int UPBOUND = 1001;
    array<bint,UPBOUND> dp {1,1,2,3};
    for(int i=4;i<UPBOUND;i++)
    {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-4];
    }
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        cout<<dp[n].str()<<endl;
    }

    return 0;
}