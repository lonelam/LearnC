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
typedef long long ll;
const int MAXN = 100001;
ll dpc[2][MAXN];
int main()
{
	ll t,m,n,k;
	while (cin >> t)
	{
		while (t--)
		{
			cin >> n >> m >> k;
			memset(dpc, 0, sizeof(dpc));
			bool flip = false;
			dpc[0][0] = 1;
			dpc[1][0] = 1;
			for (int i = 1; i <= n; i++)
			{
				if (flip)
				{
					for (int j = 1; j <= min(i,(int)m); j++)
					{
						dpc[0][j] = (dpc[1][j - 1]+dpc[1][j])%k;
					}
				}
				else
				{
					for (int j = 1; j <= min(i,(int)m); j++)
					{
						dpc[1][j] = (dpc[0][j - 1]+dpc[0][j])%k;
					}
				}
				flip = !flip;
			}
			if (flip)
			{
				cout << dpc[1][m] << endl;
			}
			else
			{
				cout << dpc[0][m] << endl;
			}
		}
	}
}