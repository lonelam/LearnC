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
	int t;
	while (cin >> t)
	{
		while (t--)
		{
			string s;
			int i, j;
			cin >> s;
			bool chance = true, isrot = true;
			for (i = 0, j = s.size() - 1; i < j; i++, j--)
			{
				if (s[i] != s[j])
				{
					chance = false;
					break;
				}
			}
			if (!chance)
			{
				chance = true;
				for (int ii = i+1, jj = j; ii < jj; ii++, jj--)
				{
					if (s[ii] != s[jj])
					{
						chance = false;
						break;
					}
				}
				for (j--; i < j; i++, j--)
				{
					if (s[i] != s[j])
					{
						if (!chance)
						{
							isrot = false;
						}
						break;
					}
				}
			}
			if (isrot)
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
	}
}