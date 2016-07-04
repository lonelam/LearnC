//hd218
#include<cstdio>
#include<cmath>
#include<cstring>
int main()
{
	int n,chief;
	double lim;
	int members[32769];
	int prime[32769]={0};
	prime[1]=1;
	for(int i=2;i<16386;i++)
	{
		if(!prime[i])
			for(int j=i+i;j<32769;j+=i)
			{
				prime[j]=1;
			}
	}
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			int cnt=0;
			scanf("%d",&chief);
			lim=sqrt(chief);
			memset(members,0,sizeof(members));
			for(int j=2;j<=chief;j++)
			{
				if(!prime[j])
				if(!(chief%j))
				{
					for(int k=j;k<chief;k+=j)
					{
						members[k]=1;
					}
				}
			}
			for(int j=1;j<chief;j++)
			{
				if(!members[j])
				{
					cnt++;
				}
			}
			printf("%d\n",cnt);
		}
	}
}
