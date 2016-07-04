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
enum crib { none, raw, cooked, burned};
int n;
vector<vector<crib>> cookpad(6, vector<crib>(6));
bool isdone()
{
	bool ans = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (cookpad[i][j] == raw)
			{
				return false;
			}
		}
	}
	return true;
}

bool beam(vector<bool> vv)
{
	
}

int main()
{
	int tmp;
	int t;
	while (cin >> t)
	{
		while (t--)
		{

			cin >> n;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cin >> tmp;
					if (tmp == 0)
					{
						cookpad[i][j] = none;
					}
					else
					{
						cookpad[i][j] = raw;
					}
				}
			}

		}
	}
	
}