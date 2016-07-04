#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<functional>
#include<queue>
#include<utility>
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
//first is time,second is node
const int INF = 0x3f3f3f3f;
using namespace std;
typedef pair<int, int> P;
bool baned[1001][1001];

int main()
{
	int n, m, q;
	while (scanf("%d%d%d", &n, &m, &q) != EOF)
	{
		int x, y, t;
		vector<vector<int> > node(1001,vector<int>(1001,INF));
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &x, &y, &t);
			node[x][y] = t;
			node[y][x] = t;
		}
		memset(baned, 0, sizeof(baned));
		for (int i = 0; i < q; i++)
		{
			scanf("%d%d%d", &t, &x, &y);
			if (t == 1)
			{
				vector<int> dp(1001, INF);
				queue<P> que;
				que.push(P(0, y));
				while (!que.empty())
				{
					P p = que.front();
					que.pop();
					if (dp[p.second] > p.first)
					{
						dp[p.second] = p.first;
						for (int ci = 1; ci <= n;ci++)
						{
							if (node[p.second][ci] < INF)
							{
								que.push(P(max(p.first, node[p.second][ci]), ci));
							}
						}
					}
				}
				printf("%d\n", dp[x]);
			}
			if (t == 2)
			{
				node[x][y] = INF;
				node[y][x] = INF;
			}
		}
	}
}