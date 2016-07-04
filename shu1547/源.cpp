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

int main()
{
	int t, n;
	while (scanf("%d", &t) != EOF)
	{
		for (int i = 0; i < t; i++)
		{
			scanf("%d", &n);
			int check = 0;
			for (int j = 0; j < n; j++)
			{
				int a, b, c;
				char oper;
				scanf("%d%c%d=%d", &a, &oper, &b, &c);
				if (oper == '+'&&a + b == c) check++;
				else if (oper == '-' && a - b == c) check++;
				
			}
			printf("%d/%d\n", check, n);
		}
	}
}