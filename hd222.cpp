//hd222-----Rabin-miller test
#include<cstdio>
#include<cmath>
const int PLUSN[8]={4,2,4,2,4,6,2,6};
bool isprime(int p);
int main()
{
	
	int cnt;
	int temp,total;
	while (scanf("%d",&total)!=EOF)
	{
		cnt=0;
		for(int i=0;i<total;i++)
		{
			scanf("%d",&temp);
			if(isprime(temp))
			    cnt++;
		}
		printf("%d\n",cnt);
	}
	
}
bool isprime(int p)
{
	if ( p < 2 ) return false;
	if(p==2) return true;
	if (!(p % 2 && p % 3 && p % 5)) return false;
	int oprt = 7;
	double maxr = sqrt(p);
	while(oprt<= maxr)
	{
		for(int i = 0; i < 8 ; i++)
		{
			if(!(p%oprt))
			{
				return false;
			}
			oprt += PLUSN[i];		
		}
	}
	return true;
	
}
