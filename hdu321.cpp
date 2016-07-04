#include<iostream>
#include<vector>
#include<utility>
using namespace std;
vector<int> sum;
vector<int> bpos;
int main()
{
	int t,n,temp;
	scanf("%d",&t);
	string s;
	for(int i=1;i<=t;i++)
	{
	    scanf("%d",&n);
	    sum.push_back(0);
	    bpos.push_back(1);
	    for(int j=0;j<n;j++)
	    {
	    	scanf("%d",&temp);
	    	if(sum[j]+temp >= temp)
	    	{
	    		sum.push_back(sum[j]+temp);
	    		bpos.push_back(bpos[j]);
			}
			else
			{
				sum.push_back(temp);
				bpos.push_back(j+1);
			}
		}
		temp = 1;
		for(int j=1;j<=n;j++)
		{
			if(sum[j]>sum[temp])
			{
				temp = j;
			}
		}
		
		printf("Case %d:\n%d %d %d\n",i,sum[temp],bpos[temp],temp);
		sum.clear();
		bpos.clear();
		if(i!=t)
		{
			printf("\n");
		}
		
	}
}
