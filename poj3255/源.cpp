#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<list>
#include<queue>
#include<functional>
#include<algorithm>

using namespace std;

typedef pair<int, int> P;
const int MAX_V = 5001;
const int INF = 0x3f3f3f3f;
int V;
//first is distance second is node

priority_queue<P, vector<P>, greater<P> > que;
int d1[MAX_V];
int d2[MAX_V];
int main()
{
	int n, r;
	while (scanf("%d%d", &n, &r) != EOF)
	{
		if (n == 0)
		{
			continue;
		}
		vector<P> G[MAX_V];
		int from, to, dis;
		for (int i = 0; i < r; i++)
		{
			scanf("%d%d%d", &from, &to, &dis);
			G[from].push_back(P(dis,to));
			G[to].push_back(P(dis,from));
		}
		memset(d1, INF, sizeof(d1));
		memset(d2, INF, sizeof(d2));
		que.push(P(0, 1));
		while (!que.empty())
		{
			int d = que.top().first;
			int cur = que.top().second;
			que.pop();
			if (d < d1[cur])
			{
				swap(d, d1[cur]);
				for (int i = 0; i < G[cur].size();i++)
				{
					P x = G[cur][i];
					que.push(P(d1[cur] + x.first, x.second));
				}
			}

			if (d < d2[cur] && d!=d1[cur])
			{
				d2[cur] = d;
				for (int i = 0; i < G[cur].size(); i++)
				{
					P x = G[cur][i];
				    que.push(P(d + x.first, x.second));
				}
			}
		}
		printf("%d\n", d2[n]);
	}
}

