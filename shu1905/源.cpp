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
	string jar;
	while (cin >> jar)
	{
		int zero = 0, one = 0, die = 0, surv = 0;
		for (int i = 0; i < jar.size() - 1; i++)
		{
			if (jar[i] == '0')
			{
				zero++;
				if (jar[i + 1] == '0')
				{
					surv++;
				}
				else
				{
					die++;
				}
			}
			else
			{
				one++;
			}
		}
		if (jar.back() == '0')
		{
			zero++;
			if (jar.front() == '1')
			{
				die++;
			}
			else
			{
				surv++;
			}
		}
		else
		{
			one++;
		}
		double rotate = 1.*zero / one;
		double shoot = 1. * surv / die;
		if (rotate > shoot)
		{
			cout << "ROTATE\n";
		}
		else if (rotate < shoot)
		{
			cout << "SHOOT\n";
		}
		else
		{
			cout << "EQUAL\n";
		}
	}
}