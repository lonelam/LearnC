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

void gd(int & a)
{
	if (a < 1700)
	{
		a += 233;
	}
	else
	{
		a += 123;
	}
}
void bd(int &a)
{
	if (a < 1700)
	{
		a -= 123;
	}
	else
	{
		a -= 233;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int t,n;
	cin >> t;
	{
		while (t--)
		{
			int rate1 = 1500, rate2 = 1500;
			string s;
			cin >> n;
			while (n--)
			{
				cin >> s;
				if (s[0] == 'g')
				{
					if (rate1 > rate2)
					{
						gd(rate2);
					}
					else
					{
						gd(rate1);
					}
				}
				else
				{
					if (rate1 > rate2)
					{
						bd(rate2);
					}
					else
					{
						bd(rate1);
					}
				}
			}
			cout << max(rate1, rate2) << endl;
		}
	}
}