#include<cstdio>
#include<cmath>
int main()
{
	long double k;
	const long double a = log10((1 + sqrt(5)) / 2);
	const long double b = log10(5) / 2;
	int n;
	int fibo21[22] = { 0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,1094 };
	while (scanf("%d", &n) != EOF)
	{
		if (n < 22)
		{
			printf("%d\n", fibo21[n]);
		}
		else
		{
			k = n*a - b;
			k = pow(10, (k - floor(k)));
			while (k < 1000)
			{
				k *= 10;
			}
			printf("%d\n",int(k));
		}
	}
	return 0;
}