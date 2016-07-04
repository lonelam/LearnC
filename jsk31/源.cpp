#include<cstdio>
#include<set>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
std::set<int> pos;
bool visit[400];
int la, lb, lc;
void output(int oo)
{
	if (oo != *pos.rbegin())
		printf("%d ", oo);
	else
		printf("%d", oo);
}
int dfs(int a, int b, int c)
{
	if (visit[a * 20 + b])
	{
		return -1;
	}
	else
	{
		visit[a * 20 + b] = true;
		if (a)
		{
			if (a + b > lb)
			{
				pos.insert(dfs(a - lb + b, lb, c));
			}
			else
			{
				pos.insert(dfs(0, a + b, c));
			}
			pos.insert(dfs(0, b, a + c));

		}
		if (b)
		{
			if (a + b > la)
			{
				pos.insert(dfs(la, a + b - la, c));
			}
			else
			{
				pos.insert(dfs(a + b, 0, c));
			}
			pos.insert(dfs(a, 0, b + c));

		}
		if (c)
		{
			if (c + a > la)
				pos.insert(dfs(la, b, c + a - la));
			else
			{
				dfs(a + c, b, 0);
			}
			if (b + c > lb)
				dfs(a, lb, b + c - lb);
			else
				dfs(a, b + c, 0);

		}


	}
	if (a == 0)
	{
		pos.insert(c);
		return c;
	}
	return -1;
}
int main()
{
	while (scanf("%d%d%d", &la, &lb, &lc) != EOF)
	{
		pos.clear();
		memset(visit, 0, sizeof(visit));
		pos.insert(dfs(0, 0, lc));
		pos.erase(-1);
		std::for_each(pos.begin(), pos.end(), output);
	}
	return 0;
}