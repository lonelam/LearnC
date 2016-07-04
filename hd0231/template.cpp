#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
#include<sstream>
#include<iomanip>
namespace laisint
{
    using namespace std;
class BigInt
{
private:
    typedef long long ll;
    const static int BIGINT_RADIX = 1000000000;
    const static int RADIX_LEN = 9;

    vector<ll> elems;
    BigInt(const vector<ll> num ):elems(num) {}
public:
    BigInt(string &s)
    {
        vector<ll> result;
        result.reserve(s.size()/RADIX_LEN + 1);

        for (int i=s.size(); i>0 ;i-=RADIX_LEN)
        {

            int temp = 0;
            const int low = max(i-RADIX_LEN,0);
            for(int j=low; j < i ; j++)
            {
                temp = temp*10 + s[j] - '0';
            }
            result.push_back(temp);

        }
        elems = result;
    }

    string toString()
    {
        stringstream result;
        bool started = false;
        for (auto i = elems.rbegin();i!=elems.rend();i++)
        {
            if(started)
            {
                result<<setw(RADIX_LEN)<<setfill('0')<<*i;
            }
            else
            {

                result<<*i;
                started = true;
            }
        }
        if (!started) return "0";
        else
        {
            return result.str();
        }
    }
};

}
