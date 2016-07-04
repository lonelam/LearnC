//hdu3.2.2

#include<iostream>
#include<vector>
#include<string> 
#include<algorithm>
#include<cstring> 
#include<array>
#include<memory>
using namespace std;


int dp[1000][1000];
int main()
{
	
	string s1,s2;
	while(cin>>s1>>s2)
	{
		memset(dp,0,sizeof(dp));
		for(int i=0;i<s1.length();i++)
		{
			for(int j=0;j<s2.length();j++)
			{
				if (s1[i]==s2[j])
				{
					dp[i+1][j+1] = dp[i][j]+1;
				}
				else
				{
					dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
					
				}
			}
		}
		cout<<dp[s1.length()][s2.length()]<<endl;
	}
}
