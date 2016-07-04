#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[105][105];
int main()
{
	int t, n,temp;
	
	while(cin >> t)
	{
		for (int k = 0; k < t; k++)
		{
			memset(dp, 0, sizeof(dp));
			cin >> n;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= i; j++)
				{
					cin >> temp;
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + temp;

				}
			}
			cout << *max_element(dp[n] + 1, dp[n] + n) << endl;
		}
	}
	return 0;
}
