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
int n, m;
int sc[1000];
bool solve()
{
	if (m >= 3 * n)
	{
		return false;
	}
	int i=1, j =n;
	while (i < j)
	{
		int c = m - i - j;
		if (c>0&&c <= n&&c != i&&c != j)
		{
			return true;
		}
		else
		{
			if (c > 1)
			{
				i++;
			}
			else
			{
				j--;
			}
		}
	}
	return false;
}
int main()
{

	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
		{
			return 0;
		}
		
		if (solve())
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
	}
}