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
	int t, n, m, k;
	while (cin >> t)
	{
		while (t--)
		{
			cin >> n >> m >> k;
			int a = 0, b = k + 2;
			if (n + m < k + 2)
			{
				cout << -1 << endl;
			}
			else
			{
				int ans = 0;
				while (a < k + 1)
				{
					a++;
					b--;
					ans = max(ans,(n / a) * (m / b));
				}
				cout << ans << endl;
			}
		}
	}
}