#include<cstdio>
using namespace std;
int main(void)
{
	int n,i,j,temp;
	int *p;
	while(scanf("%d",&n)!=EOF)
	{
		p=new int[n];
		for(i=0;i<n;i++)
		{
			scanf("%d",&p[i]);
		}
		for (i=0;i<n;i++)
		{
			for(j=i;j>0;j--)
			{
				if(p[j]<p[j-1])
				{
					temp=p[j];
					p[j]=p[j-1];
					p[j-1]=temp;
				}
				else break;
			}
		}
		for (i=0,j=n-1;i<j-1;i++,j--)
		{
			printf("%d %d ",p[j],p[i]);
		}
		if(i<j){
			printf("%d %d",p[j],p[i]);
		}
		if (i==j)
		{
			printf("%d",p[i]);
		}
		delete p;
		printf("\n");
	}
	return 0;
}
