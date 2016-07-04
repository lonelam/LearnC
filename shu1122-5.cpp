#include<cstdio>
#include<cmath>
int main()
{
	double i=1;
	double ans=0;
	double temp = 1;
	while(temp>0.0000000000005)
	{
		temp=1.0/(i*i);
		i++;
		ans +=temp;
	}
	ans=sqrt(6*ans);
	printf("%lf",ans);
}
