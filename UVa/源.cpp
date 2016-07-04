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
const int MOD = 200907;
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			int k;
			ll a, b, c, step;
			scanf("%lld%lld%lld%d", &a, &b, &c,&k);
			if (b - a == c - b)
			{
				ll res = a;
				step = (b - a)%MOD;
				k %= MOD;
				k--;
					res = (res + step*k) % MOD;
				
				printf("%lld\n", res);
			}
			else
			{
				ll res = a;
				ll x = step = b / a;
				k--;
				while (k > 0)
				{
					if (k & 1)
					{
						res = (res*x) % MOD;
					}
					x = x*x %MOD;
					k >>= 1;
				}
				printf("%lld\n", res);
			}

		}
	}
}
