#define _CRT_SECURE_NO_WARNINGS
#include<cmath>
#include<cstdio>
const double PI = 3.14159265359;
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		double f1, f2, a;
		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf%lf", &f1, &f2, &a);
			printf("%.2lf\n", sqrt(f1*f1 + f2*f2 - 2 * f1*f2*cos((180 - a)*PI/180)));
		}
	}
}