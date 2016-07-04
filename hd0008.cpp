#include<cstdio>
int main(void)
{
	struct exam
	{
		int rank = 1;
		int t;
		int p;
	};
	exam * pr;
	int amount[5];
	int n,th,tm,ts,i,j;
	while (scanf("%d", &n) != EOF) 
	{
		for (i=1;i<6;i++)
		{
			amount[i]=0;
		}
		if(n<0) return 0;
		pr = new exam[n];
		for (i = 0; i < n; i++)
		{
			scanf("%d %d:%d:%d", &((pr+i)->p), &th, &tm, &ts);
			(pr+i)->t = th * 3600 + tm * 60 + ts;
			amount[(pr+i)->p]++;
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if ((pr+i)->p == (pr+j)->p&&(pr+i)->t>(pr+j)->t)
				{
					(pr+i)->rank++;
				}
			}
			if ((pr+i)->rank>amount[(pr+i)->p]/2||(pr+i)->p == 5||(pr+i)->p==0)
			{
				printf("%d\n", (pr+i)->p * 10 + 50);
			}
			else
			{
				printf("%d\n", (pr+i)->p * 10 + 55);
			}
		}
		printf("\n");
		delete pr;
	}
}
