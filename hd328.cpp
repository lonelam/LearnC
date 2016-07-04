#include <cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int map[100000][11];
int dp[100000][11];
int solve(int y)
{
	int i,j;
	for(i=0;i<11;i++)
		dp[y-1][i]=map[y-1][i];
	for(i=y-2;i>=0;i--)
	{
		for(j=1;j<10;j++)
			dp[i][j]=max(dp[i+1][j],max(dp[i+1][j-1],dp[i+1][j+1]))+map[i][j];
		dp[i][0]=max(dp[i+1][0],dp[i+1][1])+map[i][0];//?????0???????
		dp[i][10]=max(dp[i+1][9],dp[i+1][10])+map[i][10];//?10???????
	}
		return max(dp[0][4],max(dp[0][5],dp[0][6]));
}


int main()
{  
	int n,x,y,time;
	while(scanf("%d",&n)&&n)
	{
		time=0;
		memset(map,0,sizeof(map));
		while(n--)
		{
			scanf("%d%d",&x,&y);
			map[y-1][x]+=1;
			time=max(time,y);//??????
		}
		printf("%d\n",solve(time));
	}
	return 0;
}
