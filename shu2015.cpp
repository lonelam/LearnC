#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[101][1001];
int val[101];
int tt[101];
const int INF = 0x3fff3fff;
int main()
{
    int t,m;
    while(cin>>t>>m)
    {
        memset(dp,0,sizeof(dp));
        for(int i=0;i<m;i++)
        {
            cin>>tt[i]>>val[i];
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<tt[i];j++)
            {
                dp[i+1][j] = dp[i][j];
            }
            for(int j=tt[i];j<=t;j++)
            {
                dp[i+1][j] = max(dp[i][j-tt[i]]+val[i],dp[i][j]);
            }
        }
        cout<<dp[m][t]<<endl;
    }
 } 
