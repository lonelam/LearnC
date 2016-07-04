#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int I[51];
	int dp[51][10000];
	int n;
	while (scanf("%d", &n) && n != -1)
	{
		memset(I, 0, sizeof(I));
		int summ;
		int v, m;
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &v, &m);
			I[v] = m;
			summ += (v*m);
		}
		int sum = summ / 2;
		for (int i = 0; i < 51; i++)
		{
			for (int j = 1; j < sum; j++)
			{
				int mmk = 0;
				for (int k = 1; k <= I[i]&& j-i*k>=0; k++)
				{
					if (mmk < dp[i][j - i*k] + i*k)
					{
						mmk = dp[i][j - i*k] + i*k;
					}
				}
				dp[i][j] = max(dp[i - 1][j], mmk);
			}
		}
		while (dp[50][sum] != sum)
		{
			sum--;
		}
		printf("%d%d\n", summ - sum, sum);
		
	}
}
