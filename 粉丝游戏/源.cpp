#include<iostream>
int mat[1000][1000];
int main()
{
	memset
	int rq[1000];
	int n, m,a,b;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &a, &b);
		if (mat[a][b] == 0)
		{
			rq[a]++;
			rq[b]--;
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", rq[i]);
	}
}