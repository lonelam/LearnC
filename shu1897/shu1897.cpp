#include<cstdio>
#include<algorithm>
int main()
{
	int * a;
	int n,m;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &m);
			a = new int[2 * m];
			for (int j = 0; j < 2 * m; j++)
			{
				scanf("%d", a+j);
			}
			std::sort(a, a + 2 * m);
			int sum = 0;
			int top = 0;
			int bottom = m * 2-1;
			for (; top<bottom; top++,bottom--)
			{
				sum += ((a[top] - a[bottom])*(a[top] - a[bottom]));
			}
			printf("%d\n", sum);
			delete a;

		}
	}
}