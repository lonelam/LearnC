#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
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
typedef long long ll;
ll fact1(ll a)
{
	if (a == 0)
	{
		return 1;
	}
	ll ans = a;
	while (--a)
	{
		ans *= a;
	}
	return ans;
}
ll solve(ll m, ll n)
{
	ll ans = fact1(n);
	ans *= fact1(n - 1);
	ans /= fact1(n - m);
	return ans;
}
int main()
{
	int t;
	ll m, n, ans;
	while (cin >> t)
	{
		while (t--)
		{
			cin >> m >> n;
			cout << solve(m, n) << endl;
		}
	}
}