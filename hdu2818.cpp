#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<vector>
#include<list>
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
const int MAX_N = 30001;
int par[MAX_N];
int main()
{
	int p;
	while (scanf("%d", &p) != EOF)
	{
		
	    vector<list<int>> pile(MAX_N);
		for (int i = 1; i < MAX_N; i++)
		{
			par[i] = i;
			pile[i].push_back(i);
		}
		char cmd;
		int x, y;
		for (int i = 0; i < p; i++)
		{
			scanf("%c", &cmd);
			if (cmd == 'M')
			{
				scanf("%d%d", &x, &y);
				if (par[x] != par[y])
				{
					pile[par[x]].splice(pile[par[x]].end(), pile[par[y]]);
					par[y] = par[x];
				}
			}
			else if (cmd == 'C')
			{
				scanf("%d", &x);
				int pos = distance(find(pile[par[x]].begin(), pile[par[x]].end(), x),pile[par[x]].end());
				printf("%d\n", pos);
			}
			else
			{
				i--;
			}
		}
	}
}
