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
const ll  modnum = 1000000007;
ll  fact[1002] = { 1,1 };

ll x, y;
ll extgcd(ll a, ll b, ll &x, ll &y)
{
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int gcd = extgcd(b, a % b, x, y);
	int tmp = x;
	x = y;
	y = tmp - (a / b) * y;
	return gcd;
}

int main()
{
	for (ll i = 2; i < 1002; i++)
	{
		fact[i] = i * fact[i - 1] % modnum;
	}

	ll t;
	while (cin >> t)
	{
	    ll cnt = 0,temp,ans = 1;
		for (int i = 0; i < t;i++)
		{
			cin >> temp;
			
			if (temp != 1)
			{
				ans = ans * fact[cnt +temp - 1] % modnum;
				extgcd(fact[cnt], modnum, x, y);
				while (x < 0)
				{
					x += modnum;
				}
				ans = ans * x %modnum;
				extgcd(fact[temp-1], modnum, x, y);
				while (x < 0)
				{
					x += modnum;
				}
				ans = ans * x% modnum;
			}
			cnt += temp;

		}
		cout << ans << endl;
	}
}