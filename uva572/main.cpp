#include<cstdio>
#include<cstring>
int total,m,n,cnt;
bool grid[100][100];
void dfs(int x,int y);
int main()
{
	char t;
	while (scanf("%d%d", &m, &n), m)
	{
		getchar();
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				t = getchar();
				if (t == '\n')
					t = getchar();
				if (t == '*')
					grid[i][j] = false;
				else
					grid[i][j] = true;
			}
		}
		cnt = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j])
				{
					dfs(i, j);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
}
void dfs(int x,int y)
{
	if (grid[x][y])
	{
		grid[x][y] = false;
		if (x > 0)
		{
			if (y > 0)
			{
				dfs(x - 1, y - 1);
			}
			if (y < n - 1)
			{
				dfs(x - 1, y + 1);
			}
			dfs(x - 1, y);
		}
		if (y > 0)
		{
			dfs(x, y - 1);
		}
		if (y < n - 1)
		{
			dfs(x, y + 1);
		}
		if (x < m - 1)
		{
			if (y > 0)
			{
				dfs(x + 1, y - 1);
			}
			if (y < n - 1)
				dfs(x + 1, y + 1);
			dfs(x + 1, y);
		}
		
	}
}