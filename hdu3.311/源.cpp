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
const int MN = 101, ML = 1001;

int rate[MN];
int cost[MN];
int dp[MN + 1][ML];
int pic[MN + 1][ML];
int main()
{
	int t, n, m, l;
	while (scanf("%d", &t) != EOF)
	{
		scanf("%d%d%d", &n, &m, &l);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", cost + i, rate + i);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j < cost[i]; j++)
			{
				dp[i + 1][j] = dp[i][j];
				pic[i + 1][j] = pic[i][j];
			}
			for (int j = cost[i]; j < MN; j++)
			{
				int mi = i, mj = dp[i][j-cost[i]],mv = dp[i][j];
				for (int k = i; k > 0; k--)
				{
					
				}
			}
		}
	}
}