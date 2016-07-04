#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
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
typedef long long ll;
const int MAX_N = 30001;
int par[MAX_N];
int _root(int val)
{
	if (par[val] == val)
	{
		return val;
	}
	return par[val] = par[par[val]];
}
int main_()
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
		char cmd[3];
		int x, y;
		for (int i = 0; i < p; i++)
		{
			scanf("%s", cmd);
			if (cmd[0] == 'M')
			{
				scanf("%d%d", &x, &y);
				int tree = _root(x);
				int leaf = _root(y);
				if (tree != leaf)
				{
					par[leaf] = tree;
					pile[tree].splice(pile[tree].end(), pile[leaf]);
				}
			}
			else if (cmd[0] == 'C')
			{
				scanf("%d", &x);
				int npie = _root(x);
				ll pos = distance(find(pile[npie].begin(), pile[npie].end(), x),pile[npie].end())-1;
				printf("%lld\n", pos);
			}
			else
			{
				i--;
			}
		}
	}
	return 0;
}