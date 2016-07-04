//shu1112-1
#include<cstdio>
#include<cstring>
int t[101]={0};
int main()
{
	int n,m,cnt;
	int temp;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			cnt=0;
			memset(t,0,101*sizeof(int));
			scanf("%d",&m);
			for(int j=0;j<m;j++)
			{
				scanf("%d",&temp);
				t[temp]=1;
			}
			for(int j=1;j<101;j++)
			{
				if(t[j])
				{
					if(t[j+j])
					{
						cnt++;
					}
				}
			}
			printf("%d\n",cnt);
			
			
		}
	}
}
