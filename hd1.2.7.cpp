#include<cstdio>
int main(void)
{
	double sum=0;
	double l;
	while(scanf("%lf",&l)!=EOF)
	{
		sum+=l;
	}
	sum/=12;
	printf("$""%1.2lf",sum);
}
