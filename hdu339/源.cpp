#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAX_N = 101;
int A[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];
int main()
{
	int n, m;
	memset(A, 0, sizeof(A));
	memset(dp, 0, sizeof(dp));
	while (scanf("%d%d", &n, &m) != EOF&&n&&m)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				scanf("%d", A[i] + j);
				int mi = 0;
				for (int k = 0; k <= j; k++)
				{
					if (mi < dp[i][j - k] + A[i][k])
					{
						mi = dp[i][j - k] + A[i][k];
					}
				}
				dp[i + 1][j] = mi;
			}
		}
		printf("%d\n", dp[n][m]);
	}
	return 0;
}