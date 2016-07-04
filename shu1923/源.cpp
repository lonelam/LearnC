#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<utility>
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
char maze[20][20];
bool used[20][20];
int n, m, k;
struct step
{
	bool is_flipping;
	int left_skill;
	int x, y;
};

int bfs(int x,int y)
{
	vector<step> cur, next;
	int level = 0;
	cur.push_back({false,k,x,y});
	while (!cur.empty())
	{
		for (step x : cur)
		{
			if (used[x.x][x.y])
			{
				continue;
			}
			used[x.x][x.y] = true;
			if (maze[x.x][x.y] == 'T')
			{
				return level;
			}
			if (!x.is_flipping && maze[x.x][x.y] == 'x')
			{
				if (x.left_skill == 0)
				{
					continue;
				}
				if (x.x + 1 < n)
				{
					next.push_back({ true,x.left_skill - 1,x.x + 1,x.y });
				}
				if (x.x > 0)
				{
					next.push_back({ true,x.left_skill - 1,x.x - 1,x.y });
				}
				if (x.y + 1 < m)
				{
					next.push_back({ true,x.left_skill - 1,x.x,x.y + 1 });
				}
				if (x.y > 0)
				{
					next.push_back({ true,x.left_skill - 1,x.x,x.y - 1 });
				}
			}
			else if (maze[x.x][x.y] == '.')
			{
				if (x.x + 1 < n)
				{
					next.push_back({ false,x.left_skill,x.x + 1,x.y });
				}
				if (x.x > 0)
				{
					next.push_back({ false,x.left_skill,x.x - 1,x.y });
				}
				if (x.y + 1 < m)
				{
					next.push_back({ false,x.left_skill,x.x,x.y + 1 });
				}
				if (x.y > 0)
				{
					next.push_back({ false,x.left_skill,x.x,x.y - 1 });
				}
			}

		}
		cur = next;
		next.clear();
		level++;
	}
	return -1;
}
int main()
{
	int t;
	while (cin >> t)
	{
		while (t--)
		{
			memset(used, 0, sizeof(used));
			int s_x, s_y;
			cin >> n >> m >> k;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					cin >> maze[i][j];
					if (maze[i][j] == 'S')
					{
						s_x = i;
						s_y = j;
						maze[i][j] = '.';
					}
				}
			}
			cout << bfs(s_x, s_y) << endl;
		}
	}
}