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
int dp[1001][1001];

int main()
{
	cin.sync_with_stdio(false);
	int l, w, a, b;
	while (cin >> l >> w)
	{
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> dp[i][j];
			}
		}
		cin >> a >> b;
		for (int i = 0; i <= l - a; i++)
		{
			for (int j = 0; j < w; j++)
			{
				for (int k = i + 1; k < i + a; k++)
				{
					dp[i][j] += dp[k][j];
				}
			}
		}
		for (int i = 0; i <= l - a; i++)
		{
			for (int j = 0; j <= w - b; j++)
			{
				for (int k = j + 1; k < j + b; k++)
				{
					dp[i][j] += dp[i][k];
				}
			}
		}
		int ans = 0;
		for (int i = 0; i <= l - a; i++)
		{
			for (int j = 0; j <= w - b; j++)
			{
				ans = max(ans, dp[i][j]);
			}
		}
		cout << ans << endl;
	}
}