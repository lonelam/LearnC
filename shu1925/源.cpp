#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<map>
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
struct pixel
{
	int r, g, b;
};
int cnt[256][256][256];
bool used[1000000000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, q,i = 1;
	while (cin >> t)
	{
		while (t--)
		{
			cout << "Case #" << i++ << ":\n";
			memset(cnt, 0, sizeof(cnt));
			memset(used, 0, sizeof(used));
			map<int, pixel>g;
			pixel tmp;
			int No,cls = 1;
			cin >> n >> q;
			cnt[0][0][0] = n;
			while (q--)
			{
				cin >> No >> tmp.r >> tmp.g >> tmp.b;
				if (used[No])
				{
					
					if (--cnt[g[No].r][g[No].g][g[No].b] == 0)
					{
						cls--;
					}
					if (cnt[tmp.r][tmp.g][tmp.b]++ == 0)
					{
						cls++;
					}
					g[No] = tmp;
				}
				else
				{
					used[No] = true;
					if (--cnt[0][0][0] == 0)
					{
						cls--;
					}
					if (cnt[tmp.r][tmp.g][tmp.b]++ == 0)
					{
						cls++;
					}
					g[No] = tmp;
				}
				cout << cls << endl;
			}
		}
	}
}