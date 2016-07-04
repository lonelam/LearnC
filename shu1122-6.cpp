//shu1122-6
#include<cstdio>
int main()
{
	int n;
	int a,b;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			int cnt=0;
			scanf("%d%d",&a,&b);
			while(a>b)
			{
				a/=2;
				a++;
				cnt++;
			}
			printf("%d\n",cnt);
		}
	}
}
