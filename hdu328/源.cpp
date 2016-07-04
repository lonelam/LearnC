#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[100001][11];
int pie[100001][11];

int main()
{
	int n,t,temp,pos;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			return 0;
		}
		int maxt = 0;
		memset(dp, 0, sizeof(dp));
		memset(pie, 0, sizeof(pie));
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &pos, &t);
				pie[t][pos] ++;
				if (t > maxt)
				{
					maxt = t;
				}
		}
		for (int i = 0; i < 11; i++)
		{
			dp[maxt][i] = pie[maxt][i];
		}
		for (int i = maxt-1; i >=0; i--)
		{
			dp[i][0] = max(dp[i+1 ][0], dp[i+1 ][1])+pie[i][0];
			dp[i][10] = max(dp[i+1 ][10], dp[i+1 ][9])+pie[i][10];
			for (int j = 1; j < 10; j++)
			{
				dp[i ][j] = max(max(dp[i+1][j], dp[i+1][j + 1]), dp[i+1][j - 1])+pie[i][j];
			}
		}
		printf("%d\n", dp[0][5]);
	}
}