#include<iostream>
#include"БъЭЗ.h"
int m[55], v[55];

int main_()
{
	int n;
	while (scanf("%d", &n) != EOF&&n > 0)
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", v + i, m + i);
			sum += v[i] * m[i];
		}
		int mi = sum, ans = v[0];
		for (int i = 0; i < n; i++)
		{
			for (int j = sum; j >= v[i]; j--)
			{
				for (int k = 0; k <= m[i]; k++)
				{
					if (j >= k*v[i])
					{
						if (k&&j % (k*v[i]) == 0 && j * 2 >= sum && 2 * j - sum < mi)
						{
							mi = 2 * j - sum;
							ans = j;
						}
					}
				}
			}
		}
		printf("%d %d\n", ans, sum - ans);
	}
	return 0;
}