#include<stdio.h>
int main(void)
{
	int cow[10005];
	int n,i,j,a;
	while(scanf("%d",&n)!=EOF){
	for(i=0;i<n;i++)
	{
		scanf("%d",&cow[i]);
	}
	for(j=0;j<n-1;j++)
	{
		for(i=0;i<n-1;i++)
		{
			if (cow[i]>cow[i+1])
			{
				a=cow[i];
				cow[i]=cow[i+1];
				cow[i+1]=a;
			}
		}
	}
	printf("%d\n",cow[n/2]);
	}
	return 0;
}
