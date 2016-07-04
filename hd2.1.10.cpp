#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cmath>
double I(double x1, double y1, double x2, double y2, double x3, double y3, double a, double b);
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			double x1, x2, x3, y1, y2, y3;
			scanf("%f%f%f%f%f%f", &x1, &x2, &x3, &y1, &y2, &y3);
			double a = (y2 - y1) / (x2 - x1) / (x2 - x1);
			double b = (y3 - y2) / (x3 - x2);
			printf("%.2lf\n", abs(I(x1, y1, x2, y2, x3, y3, a, b)));
		}
	}
}
double I(double x1, double y1, double x2, double y2, double x3, double y3, double a, double b)
{
	return (a / 3)*(pow(x3 - x1, 3) - pow(x2 - x1, 3)) + (y1 - y2)*(x3 - x2) + b / 2 * (x3 - x2);
}