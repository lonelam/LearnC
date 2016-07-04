#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<functional>
#include<queue>
#include<utility>
#include<algorithm>
/*
-----------Answered by Lonelam---------
*
*          +-+       +-+
*       +--+ --------+ ---+
*       ¦                 ¦
*       ¦       ---       ¦
*       ¦  --+       +--  ¦
*       ¦                 ¦
*       ¦       ---       ¦
*       ¦                 ¦
*       +---+         +---+
*           ¦         ¦
*           ¦         ¦
*           ¦         ¦
*           ¦         +--------------+
*           ¦                        ¦
*           ¦                        +-+
*           ¦                        +-+
*           ¦                        ¦
*           +-+  +  +----------+  +--+
*             ¦ -¦ -¦       ¦ -¦ -¦
*             +-----+       +-----+
*                 ????
*                 ???BUG!
*/
//first is time,second is node
const int INF = 0x3f3f3f3f;
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
int main()
{
	int n, m, q;
	while (scanf("%d%d%d", &n, &m, &q) != EOF)
	{
		int x, y, t;
		vector<vector<P> > node(1000);
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &x, &y, &t);
			node[x].push_back(P(t, y));
			node[y].push_back(P(t, x));
		}
		for (int i = 0; i < q; i++)
		{
			scanf("%d%d%d", &t, &x, &y);
			if (t == 1)
			{
				priority_queue<P,vector<P>,less<P>> hp;
				vector<int> dp(n+1,INF);
				hp.push(P(0,x));
				while (!hp.empty())
				{
					P p = hp.top();
					hp.pop();
					if (dp[p.second]>p.first)
					{
						dp[p.second] = p.first;
						for (P j : node[p.second])
						{
							hp.push(P(max(j.first, p.first), j.second));
						}
					}
				}
				printf("%d\n", dp[y]);
			}
			if (t == 2)
			{
				node[x].erase(find_if(node[x].begin(), node[x].end(), [&y](P p) {return y == p.second; }));
				node[y].erase(find_if(node[y].begin(), node[y].end(), [&x](P p) {return x == p.second; }));
			}
		}
	}
}
