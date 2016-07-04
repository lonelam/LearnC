
#include<cstdio>
int main()
{
	int n;
	while (scanf("%d", &n), n)
	{
		int k;
		{
			for (k = 0; !(n & 1); k++)
			{
				n >>= 1;
			}
		    printf("%d\n",1<<k);
		}
		
	}
}