#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
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
const int MAX = 4;
bool visited[MAX][MAX];
bool xed[MAX][MAX];
bool av[MAX][MAX];
bool bv[MAX][MAX];
int n, m;
bool isdone()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j])
				return false;
		}
	}
	return true;
}
int bbfs(int x,int y)
{
	queue<pair<int, int>> a, b, anext, bnext;
	int level = 0;
	a.push({ x,y });
	b.push({ x,y });
	while (!isdone())
	{

	}
}
int main()
{
	int t;
	while (cin >> t)
	{

		char tmp;
		while (t--)
		{
			cin >> n >> m;
			int s_x, s_y;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					cin >> tmp;
					if (tmp == 'O')
					{
						xed[i][j] = false;
					}
					else if (tmp == 'S')
					{
						xed[i][j] = false;
						s_x = i;
						s_y = j;
					}
					else
					{
						xed[i][j] = true;
						visited[i][j] = true;
					}
				}
			}
			
		}

	}
}