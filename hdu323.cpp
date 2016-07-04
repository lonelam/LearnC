//hdu3.2.3

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF = 0x3fff3fff;
int main()
{
	int n;
	int data[1001]; 
	int dp[1001];
	while(scanf("%d",&n)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		if(n==0)
		{
			return 0;
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",data+i);
			int mmax = 0;
			for(int j=0;j<i;j++)
			{
				if(data[i]>data[j]&&dp[j]+data[i]>mmax)
				{
					mmax = dp[j]+data[i];
				}
			}
			dp[i] = max(mmax,data[i]);
		}
		printf("%d\n",*max_element(dp,dp+n));
		
		
		
	}
 } 
