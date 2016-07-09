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
int mm[100000];
int main()
{
	cin.sync_with_stdio(false);
	int t;
	while (cin >> t)
	{
		int  total = 0, avg,avg2, cnt = 0,cnt2 = 0;
		for (int i = 0; i < t; i++)
		{
			cin >> mm[i];
			total += mm[i];
		}
		avg = total / t;
		if (total%t)
		{
			avg2 = avg + 1;
		}
		else
		{
			avg2 = avg;
		}
		for (int i = 0; i < t; i++)
		{
			if (mm[i] < avg)
			{
				cnt += avg - mm[i];
			}
			
			if (mm[i] > avg2)
			{
				cnt2 += mm[i] - avg2;
			}
		}
		cout << max(cnt,cnt2) << endl;
	}
}