#define _CRT_SECURE_NO_WARNINGS
#include<algorithm>
#include<cstdio>
#include<cstring>
const int MAXN = 30001;
int son[MAXN];
int rank[MAXN];
int num[MAXN];
int root(int x)
{
	if (son[x] == x)
	{
		return x;
	}
	int next = son[x];
	son[x] = root(son[x]);
	rank[x] += rank[next];
	return son[x];
}

int main()
{
	int m;
	while (scanf("%d", &m) != EOF)
	{
		for (int i = 0; i < MAXN; i++)
		{
			son[i] = i;
			num[i] = 1;
		}
		memset(rank, 0, sizeof(rank));
		char ss[3];
		int x, y;
		for (int i = 0; i < m; i++)
		{
			scanf("%s", ss);
			if (ss[0] == 'M')
			{
				scanf("%d%d", &x, &y);
				int a = root(x), b = root(y);
				if (a!=b)
				{
					son[a] = b;
					rank[a] = num[b];

					num[b] += num[a];
					
				}

			}
			else
			{
				scanf("%d", &x);
				root(x);
				printf("%d\n", rank[x]);
			}
		}
	}
}