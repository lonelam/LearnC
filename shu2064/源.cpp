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
int dp[2][100001];
int v[501];
int h[500];

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++)
		{
			cin >> v[i] >> h[i];
		}
		bool flip = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				if (!flip)
				{
					if (v[i] > j)
					{
						dp[1][j] = dp[0][j];
					}
					else
						dp[1][j] = max(dp[0][j], dp[0][j - v[i]] + h[i]);
				}
				else
				{
					if (v[i] > j)
					{
						dp[0][j] = dp[1][j];
					}
					else
					{
						dp[0][j] = max(dp[1][j], dp[1][j - v[i]] + h[i]);
					}
				}
			}
			flip = !flip;
		}
		if (flip)
		{
			cout << dp[1][m] << endl;
		}
		else
		{
			cout << dp[0][m] << endl;
		}
	}
}