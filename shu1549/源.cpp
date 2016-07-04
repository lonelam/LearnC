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
	string s[100], temp;
	int n, t,q;
	while (scanf("%d", &t) != EOF)
	{
		for (int i = 0; i < t; i++)
		{
			int trans = 0;
			scanf("%d", &n);
			vector<bool> v(n,0);
			int vcnt = 0;
			for (int j = 0; j < n; j++)
			{
				cin.get();
				getline(cin, s[j]);
			}

			scanf("%d", &q);
			int k;
			for (int j = 0; j < q; j++)
			{
				cin.get();
				getline(cin, temp);
				for (k = 0; k < n; k++)
				{
					if (temp == s[k])
					{
						if (v[k] == false)
						{
							vcnt++;
							v[k] = true;
						}
						break;
					}
				}
				if (vcnt == n)
				{
					trans++;
					fill(v.begin(), v.end(), false);
					v[k] = true;
					vcnt = 1;
				}
			}
			printf("Case #%d: %d\n", i + 1, trans);
		}
	}
}