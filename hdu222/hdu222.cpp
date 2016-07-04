#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int k, i, j, m, n, r[15], a[30];
	memset(r, 0, sizeof(r));
	for (i = 0; i < 14; i++)
	{
		memset(a, 0, sizeof(a));
		n = 2 * i;
		m = 1;
		for (j = 1; j <= i; j++)
		{
			a[j] = (a[j - 1] + m - 1) % (n - j + 1);
			if (a[j] < i)
			{
				j = 0;
				++m;
			}
		}
		r[i] = m;
	}
	while (scanf("%d", &k), k)
		printf("%d\n", r[k]);
	return 0;
}