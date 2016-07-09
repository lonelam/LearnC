#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<sstream>
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
bool used[10];
vector<int> nodes[10];
int cnt;
int n;
bool dfs(int to)
{
	if (to == 0 && cnt == n)
	{
		return true;
	}
	if (used[to])
	{
		return false;
	}
	used[to] = true;
	cnt++;
	for (int x : nodes[to])
	{
		if (dfs(x))
		{
			return true;
		}
	}
	used[to] = false;
	cnt--;
	return false;
}
int main()
{
	string tos;
	int to;
	int i = 1;
	while (cin >> n&&n)
	{
		cin.get();
		memset(used, 0, sizeof(used));
		for (int i = 0; i <= n; i++)
		{
			nodes[i].clear();
		}
		for (int i = 1; i <= n; i++)
		{
			getline(cin, tos);
			stringstream to_ss(tos);
			while (to_ss >> to)
			{
				nodes[i].push_back(to);
				nodes[to].push_back(i);
			}
		}
		cnt = -1;
		if (dfs(0))
		{
			cout << "Case " << i++ << ": Granny can make the circuit.\n";
		}
		else
		{
			cout << "Case " << i++ << ": Granny can not make the circuit.\n";
		}
	}
}