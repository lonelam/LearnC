#include<cstdio>
#include<cstring>
int main()
{
	int a[3];
	int t,n;
	int c,b;
	while(scanf("%d",&t)!=EOF)
	{
		for(int i=0;i<t;i++)
		{
			scanf("%d",&n);
			memset(a,0,3*sizeof(int));
			for(int j=0;j<n;j++)
			{
				scanf("%d%d",&c,&b);
				a[c]+=b;
			}
			if((a[1]+a[2]+a[0])>24)
			{
				printf("That's impossible!\n");
			}
			else if(a[2]<8)
			{
				printf("Bob feels guilty!\n");
			}
			else printf("It's a nice day!\n");
		}
	}
}
