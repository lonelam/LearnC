#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int map[30][1020];
int main()
{
	int t, n, m;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d%d", &n,&m);
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				scanf("%d", map[j] + k);
			}
		}
		for (int j = m - 2; j >= 0; j--)
		{

			int mmk = -200;
			for (int x = j + j + 1; x < m; x += (j + 1))
			{
				if (map[n - 1][x] > mmk)
				{
					mmk = map[n - 1][x];
				}
			}
			map[n - 1][j] += max(map[n - 1][j + 1], mmk);
		}
		for (int j = n - 2; j >= 0; j--)
		{
			map[j][m - 1] += map[j + 1][m - 1];
		}
		for (int j = n - 2; j >= 0; j--)
		{
			for (int k = m - 2; k >= 0; k--)
			{

				int mmk = -200;

				for (int x = k + k + 1; x < m; x += (k + 1))
				{
					if (map[j][x] > mmk)
					{
						mmk = map[j][x];
					}
				}

				map[j][k] += max(max(map[j + 1][k], map[j][k + 1]), mmk);
			}
		}

		printf("%d\n", map[0][0]);

	}
	
	return 0;
}