// shu1112-0.cpp
#include<cstdio>
int main()
{
	int n,a,b,c;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(a+b>c&&a+c>b&&b+c>a)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
	}
}
