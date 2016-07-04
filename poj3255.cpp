// POJ 3255

#include<cstdio>
#include<vector>
using namespace std;
int N,R;
vector<edge> G[MAX_N];
int dist[MAX_N];
int dist2[MAX_N];

void solve()
{
	priority_queue<P,vector<P>,greater<P>> que;
	fill(dist,dist+N,INF);
	fill(dist2,dist2+N,INF);
	dist[0] = 0;
	que.push(P(0,0));
	
	while(!que.empty())
	{
		P p = que.top();que.pop();
		int v = p.second, d = p.first;
		if(dist2[v]<d) continue;
		for(int )
	}
}
