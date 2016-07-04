//hd213v2
#include<cstdio>
int filter[1000000]={0};
int main()
{
	int lv=0;
	int i,j,n;
	for(i = 2; i<1000000;i++)
	{
		if(!filter[i])
		{
			lv++;
			for(j=i;j<1000000;j+=i)
			{
				filter[j]=lv;
			}
		}
	}
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",filter[n]);
	}
}
