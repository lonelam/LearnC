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
int n, m;
char mp[12][12];
char temp;
bool used[12][12];
int cnt_half, cnt_whole;
void dfs(int x, int y)
{
	if (mp[x][y] == '\\' || mp[x][y] == '/'||used[x][y])
	{
		return;
	}

	used[x][y] = true;
	mp[x][y] = 0;
	if (x > 0)
	{
		dfs(x - 1, y);
	}
	if (y > 0)
	{
		dfs(x, y - 1);
	}
	if (x < n + 1)
	{
		dfs(x + 1, y);
	}
	if (y < m + 1)
	{
		dfs(x, y + 1);
	}
}
int main()
{
	int t;
	while (cin >> n>>m)
	{
		memset(mp, 0, sizeof(mp));
		memset(used, 0, sizeof(used));
		cnt_half = cnt_whole = 0;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					cin >> mp[i][j];
				}
			}
			dfs(0, 0);
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					if (mp[i][j] == '\\' || mp[i][j] == '/')
					{
						cnt_half++;
					}
					else if (mp[i][j] == '.')
					{
						cnt_whole++;
					}
				}
			}
			cout << cnt_half + cnt_whole * 2 << endl;
	}
}