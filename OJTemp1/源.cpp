#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
/*
-----------Answered by Lonelam---------
*
*          ┌─┐       ┌─┐
*       ┌──┘ ┴───────┘ ┴──┐
*       │                 │
*       │       ───       │
*       │  ─┬┘       └┬─  │
*       │                 │
*       │       ─┴─       │
*       │                 │
*       └───┐         ┌───┘
*           │         │
*           │         │
*           │         │
*           │         └──────────────┐
*           │                        │
*           │                        ├─┐
*           │                        ┌─┘
*           │                        │
*           └─┐  ┐  ┌───────┬──┐  ┌──┘
*             │ ─┤ ─┤       │ ─┤ ─┤
*             └──┴──┘       └──┴──┘
*                 神兽保佑
*                 代码无BUG!
*/
using namespace std;
typedef vector<char> bint;
int k;
bint str2bint(string & ss)
{
	bint ans;
	if (ss.size() < k)
	{
		for (string::reverse_iterator p = ss.rbegin(); p != ss.rend(); p++)
		{
			ans.push_back(*p - '0');
		}
		int n = k - ss.size();
		while (n--)
		{
			ans.push_back(0);
		}
		
	}
	else
	{
		string::reverse_iterator p = ss.rbegin();
		for (int i = 0; i < k; i++)
		{
			ans.push_back(*p++ - '0');
		}
	}
	return ans;
}

bool cmplast(bint & a, bint & b,int n)
{
	
	for (int i = 0; i < n;i++)
	{
		if (a[i] != b[i])
		{
			return false;
		}
	}
	return true;
	
}
bint operator*(bint &a, bint &b)
{
	bint ans(a.size() + b.size(), 0);
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			ans[i+j] += a[i] * b[j];
		}
		for (int j = 0; j < i + a.size(); j++)
		{
			ans[j + 1] += ans[j] / 10;
			ans[j] %= 10;
		}
	}
	while (ans.back() == 0)
	{
		ans.pop_back();
	}
	return ans;
}
bint operator+(bint & a, bint & b)
{
	if (a.size() < b.size())//assume a>=b
		return b + a;
	bint ans( a.size() + 2,0);
	for (int i = 0; i < b.size(); i++)
	{
		ans[i] += a[i] + b[i];
		ans[i + 1] = ans[i] / 10;
		ans[i] %= 10;
	}
	for (int i = b.size(); i < a.size(); i++)
	{
		ans[i] += a[i];
		ans[i + 1] = ans[i] / 10;
		ans[i] %= 10;
	}
	while (ans.back() == 0)
	{
		ans.pop_back();
	}
	return ans;
}
bint multik(bint &a, bint &b)
{
	bint ans(k + 1, 0);
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k - i; j++)
		{
			ans[i + j] += a[i] * b[j];
		}
		for (int j = 0; j < k; j++)
		{
			ans[j + 1] += ans[j] / 10;
			ans[j] %= 10;
		}
	}
	ans.pop_back();
	return ans;
}


int main()
{
	string in;
	while (cin >> in >> k)
	{
		bool is_loop = true;
		bint fact(str2bint(in)), ans(fact),orig(fact), loop(1,1),prev_loop(1,1);
		for (int i = 1; i <= k; i++)
		{
			ans = multik(ans, fact);
			while (!cmplast(fact, ans, i))
			{
				loop = loop + prev_loop;
				ans = multik(ans, fact);
			} 
		/*	if (!cmplast(orig, ans, i))
			{
				is_loop = false;
				cout << -1 << endl;
				
			}*/
			while (i < k&&cmplast(fact, ans, i + 1))
			{
				i++;
			}
			fact = ans;//此时fact是使长度为i循环的因子
			prev_loop = loop;
		}
		if (is_loop)
		{
			for (bint::reverse_iterator i = loop.rbegin(); i != loop.rend(); i++)
			{
				cout << +*i;
			}
			cout << endl;
		}
	}
}