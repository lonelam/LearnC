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
int v[1000], p[1000];
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
		{
			return 0;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		for (int i = 0; i < m; i++)
		{
			cin >> p[i];
		}
		sort(v, v + n);
		sort(p, p + m);
		int i = 0, j = 0,cost  =0;
		while (i < n&&j<m)
		{
			if (v[i] > p[j])
			{
				j++;
			}
			else
			{
				cost += p[j];
				i++;
				j++;
			}
		}
		if (i == n)
		{
			cout << cost << endl;
		}
		else
		{
			cout << "Demon Fish!!!\n";
		}
	}
}