#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll dp[21][21];
int main()
{
	for (int i = 0; i < 21; i++)
	{
		fill(dp[i], dp[i] + 21, 0);
	}
	for (int i = 1; i < 21; i++)
	{
		dp[i][1] = 1;
	}
	for (int i = 2; i < 21; i++)
	{
		for (int j = 2; j < 21; j++)
		{
			
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]-dp[i-2][j-2];
		}
	}
	int t,k,n;
	while (scanf("%d", &t) != EOF)
	{
		for (int i = 0; i < t; i++)
		{
			scanf("%d%d", &n, &k);
			printf("%lld\n", dp[n][k]);
		}
	}
	
}