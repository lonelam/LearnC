//hd1.2.7
#include<cstdio>
int main(void)
{
	double s=0;
	double t;
	for(int i=0;i<12;i++)
	{
		scanf("%lf",&t);
		s+=t;
	}
	printf("$%1.2f\n",s/12);
}
