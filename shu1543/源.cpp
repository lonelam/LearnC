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

int main()
{
	int t;
	while (scanf("%d", &t) != EOF)
	{

		for (int i = 0; i < t; i++)
		{
			int n, temp;

			scanf("%d", &n);
			vector<int> v(n);

			for (int j = 0; j < n; j++)
			{
				scanf("%d", &temp);
				v[j] = temp;
			}
			sort(v.begin(), v.end());
			printf("%d", v[0]);
			for (int j = 1; j < n; j++)
			{
				printf(" %d", v[j]);
			}
			printf("\n");
		}
	}
}