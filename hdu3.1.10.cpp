#include <iostream>
#include <vector>
#include<string>

using namespace std;

class bigint
{
private:
    typedef long long ll;
    vector<ll> data;
    static const int RADIX_WIDTH = 9;
    static const int RADIX_MAX = 1000000000;

    void update()
    {

        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] >= RADIX_MAX)
            {
                data[i + 1] += data[i] / RADIX_MAX;
                data[i] %= RADIX_MAX;
            }
        }

    }

    void cut()
    {
        while (data.back() == 0 && data.size() != 1)
        {
            data.pop_back();
        }
    }

    void expand(size_t d)
    {
        for (int i = 0; i < d; i++)
        {
            data.push_back(0);
        }
    }

    void expand2(size_t n)
    {
        while (data.size() < n)
        {
            data.push_back(0);
        }
    }

public:
    explicit bigint() { }

    bigint(int x) : data(1, x) { }

    bigint(ll x) : data(1, x) { }

    bigint(string &s)
    {
        int i;
        while(s[0]=='0')
        {
            s.erase(0,1);
        }

        for (i = s.size() ; i >= RADIX_WIDTH ; i -= RADIX_WIDTH)
        {
            ll temp = 0;
            for (int j = i-RADIX_WIDTH; j < i ; j++)
            {
                temp *= 10;
                temp += s[j] - '0';
            }
            data.push_back(temp);
        }
        ll temp = 0;
        for (int j = 0; j < i; j++)
        {
            temp *= 10;
            temp += s[j] - '0';
        }
        data.push_back(temp);
    }

    bigint operator+(bigint &b)
    {
        if (data.size() > b.data.size())
        {
            return b + (*this);
        }
        bigint ans;
        int i;
        for (i = 0; i < data.size(); i++)
        {
            ans.data.push_back(data[i] + b.data[i]);

        }
        for (; i < b.data.size(); i++)
        {
            ans.data.push_back(b.data[i]);
        }
        ans.expand(1);
        ans.update();
        ans.cut();
        return ans;
    }

    bigint operator*(bigint &b)
    {
        if (data.size() > b.data.size())
        {
            return b * (*this);
        }
        bigint ans;
        ans.expand2(data.size() + b.data.size());
        for (int i = 0; i < data.size(); i++)
        {
            for (int j = 0; j < b.data.size(); j++)
            {
                ans.data[i + j] = data[i] * b.data[j];
            }
            ans.update();
        }
        ans.cut();
        return ans;
    }

    string str()
    {
        string ss;
        bool started =false;
        for (auto i = data.rbegin(); i != data.rend(); i++)
        {

            string block=to_string(*i);
            if(!started)
            {
                started = true;
                ss.append(block);
            }
            else
            {
                if(block.size()<RADIX_WIDTH)
                {
                    string zeros;
                    int cnt = RADIX_WIDTH-block.size();
                    for(int i = 0;i<cnt;i++)
                    {
                        zeros.push_back('0');
                    }
                    block.insert(0,zeros);
                }
                ss.append(block);
            }

        }
        return ss;
    }
};
int main()
{
	vector<bigint> f(1001) ;
	f[0] =1;
	 f[1] = 1;
	f[2] = 2;
	f[3] = 4;
	
	for(int i=4;i<1001;i++)
	{
		f[i] = f[i-1]+f[i-2]+f[i-4];
		
	}
	int n;
	while(scanf("%d",&n)!=-1)
	{
		cout<<f[n].str()<<endl;
	}
}
