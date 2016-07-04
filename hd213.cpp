//hd213
#include<cstdio>
#include<cmath>
int lpf(int n);
int PRIME[78498];
bool search(int l,int ini);
int main()
{
	PRIME[0]=2;
	for(int i=1;i<78498;i++)
	{
		
	    for(int j=PRIME[i-1]+1;;j++)
			{
			if(search(j,i))
			{
				PRIME[i]=j;
				break;
			}
			
		}
	}
	int inp;
	while(scanf("%d",&inp)!=EOF)
	{
		printf("%d\n",lpf(inp));
	}
}
int lpf(int n)
{
	if (n==1) return 0;
	int max = 0;
	for(int i = 0; PRIME[i]<=n;i++)
	{
		if (!(n%PRIME[i]))
		{
			max = i;
			n=n/PRIME[i];
		}
	}
	return max+1;
}
bool search(int l,int ini)
{
	double lim = sqrt(l);
	for(int k=0;PRIME[k]<=sqrt(l);k++)
	{
		if(!(l%PRIME[k]))
		{
			return false;
		}
		
	}
	return true;
}
