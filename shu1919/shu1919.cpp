#include<cstdio>
#include<cstring>
long long stepin(int level, int step,int turn,bool up);
int main___TimeE()
{
	int t;
	while (scanf("%d", &t) != EOF)
	{
		for (int i = 0; i < t; i++)
		{
			int n, k;
			scanf("%d%d", &n, &k);
			long long res;
			res = stepin(0, 2*n, 2*k - 1,true);
			printf("%lld\n", res);
		}

	}
	return 0;
}
long long stepin(int level, int step, int turn,bool up)
{
	if (step == 0)
	{
		if (level == 0&&turn ==0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if (level < 0)
		{
			return 0;
		}
		if (turn)
		{
			if (up)
			{
				return stepin(level + 1, step - 1, turn, true) + stepin(level - 1, step - 1, turn - 1, false);
			}
			else
			{
				return stepin(level + 1, step - 1, turn - 1, true) + stepin(level - 1, step - 1, turn, false);
			}
		}
		else
		{
			if (level > step)
			{
				return 0;
			}
			return stepin(level - 1, step - 1, turn, false);
		}
	}

}