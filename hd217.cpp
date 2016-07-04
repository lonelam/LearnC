#include<cstdio>
#include<cstring>
int filter[500001];
int main()
{
	int i,j,n;
	for(i=2;i<250001;i++)
	{
			for(j=i+i;j<500001;j+=i)
			{
				filter[j]+=i;
			}
	}
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&j);
			printf("%d\n",filter[j]+1);
		}
	}
}
