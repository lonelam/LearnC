#include<cstdio>
long long int clam(long long int n)
{
	if (n == 1)
	{
		return 1;
	}
	if (n == 2)
	{
		return 2;
	}
	return n * clam(n - 1);
}
long long int A(long long int m, long long int n)
{
	if (m == 1)
	{
		return n;
	}
	return (n - m + 1) * A(m - 1, n);
}
long long int C(long long int m, long long int n)
{
	return A(m, n) / clam(m);
}

long long int unit(long long int group, long long int n)
{
	long long int res = 1;
	for (int i = 0; i < group; i++)
	{
		res *= C(3 * (group - i), n - 3 * i);
	}
	res = res / clam(group);
	return res << group;
}
int main()
{
	int t;
	while (scanf("%d", &t) != -1)
	{
		for (int i = 0; i < t; i++)
		{
			long long int sum = 0,n;
			scanf("%I64d", &n);
			long long int grps = n / 3;
			for (int j = 1; j <= grps; j++)
			{
				sum += unit(j, n);
			}
			printf("%I64d", sum);
		}
	}
}
