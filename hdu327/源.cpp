//×î¶ÌÂ·¼ò»¯£¡

#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int level[1001];
bool par[1001];
const int INF = 0x7fff7fff;
int main()
{
	int n, m, c,from,to;
	while (cin >> n >> m >> c)
	{
		memset(level, 0, sizeof(level));
		memset(par, 0, sizeof(par));
		vector<int> *nodes = new vector<int>[n+1];
		for (int i = 0; i < m; i++)
		{
			cin >> from >> to;
			nodes[from].push_back(to);
			nodes[to].push_back(from);
		}
		vector<int> bfs,next;
		bfs.push_back(c);
		par[c] = true;
		int llv = 0;
		while (!bfs.empty())
		{
			for (int x : bfs)
			{
				level[x] = llv;
				for (int y : nodes[x])
				{
					if (!par[y])
					{
						par[y] = true;
						next.push_back(y);
					}
				}
			}
			bfs = next;
			next.clear();
			llv++;
		}
		for (int j = 1; j <= n; j++)
		{
			cout << level[j] << endl;
		}
	}
}