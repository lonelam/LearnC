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
const int MAXN = 1000, MAXM = 1000,modnum = 1000000007;
ll dp[MAXN + 2][MAXM + 2];
int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	for (int i = 0; i < MAXN + 1; i++)
	{
		dp[i][0] = 1;
	}
	dp[1][1] = 1;
	for (int i = 2; i < MAXN + 1; i++)
	{
		for (int j = 1; j < MAXM + 1; j++)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] )%modnum;
		}
	}
	int t;
	while (scanf("%d",&t)!=EOF)
	{
		while (t--)
		{
			int m, n;
			scanf("%d%d", &n, &m);
			printf("%lld\n", dp[n][m]);		}
	}
}