#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b)
{
	return *(int *)a -*(int *)b;
}
int res[1000];

void Solve(const int num, int p, int &k)
{
	int a,b,c;
	c=num/p/11;
	b=num/p-11*c;
	if(b<10)
	{
		a=(num-b*p-11*c*p)/2;
		if((c!=0||b!=0)&&(num==a*2+b*p+11*c*p))
		{
			res[k++] = a+b*p+c*p*10;
		}
	}
	b--;
	if(b>=0)
	{
		a=(num-b*p-11*c*p)/2;
		if((c!=0||b!=0)&&(num==2*a+b*p+11*c*p))
		    res[k++]=a+b*p+c*p*10;
	}
}
int main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		int k=0;
		for(int i=1;i<=n;i*=10)
		{
			Solve(n,i,k);
		}
		qsort(res,k,sizeof(res[0]),cmp);
		if(k==0)
		{
			printf("No solution.\n");
		}
		else
		{
			int tmp = -1;
			bool first = false;
			for(int i=0;i<k;++i)
			{
				if(tmp!=res[i])
				{
					if(first)
					    printf(" ");
					first=true;
					tmp=res[i];
					printf("%d",res[i]);
				}
			}
			printf("\n");
		}
		
	}
	return 0;
}
