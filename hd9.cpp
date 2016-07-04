//hd0009
#include<cstdio>
int main()
{
	int n;
	int a,b,c;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			b=b-a-c;
			if(b)
			{
				if(b>0) printf("advertise\n");
				else printf("do not advertise\n");
			}
			else printf("does not matter\n");
		}
	}
	return 0;
}
