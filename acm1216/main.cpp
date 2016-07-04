#include<cstdio>
#include<cmath>

int main()
{
	int n;
	scanf("%d", &n);
	double a, b, c;
	for (int i = 0; i < n; i++)
	{
		scanf("%lf%lf%lf", &a, &b, &c);
		printf("Scenario #%d:\n", i + 1);
		if (a > b&&a > c)
		{
			if (a*a == b*b + c*c)
			{
				printf("yes");
			}
			else
			{
				printf("no");
			}
		}
		else if (b > c)
		{
			if (b*b == a*a + c*c)
			{
				printf("yes");
			}
			else
			{
				printf("no");
			}
		}
		else
		{
			if (c*c == a*a + b*b)
			{
				printf("yes");
			}
			else
			{
				printf("no");
			}
		}
		printf("\n\n");
	}
}