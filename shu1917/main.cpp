#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

#include<algorithm>
char map[100][100];
int n, m;
bool go(int x, int y);
bool search(int x, int y);
int main()
{
	int t;
	char temp;
	int cnt;
	while (scanf("%d", &t) != EOF)
	{
		
		for (int l = 0; l < t; l++)
		{
			cnt = 0;
			scanf("%d%d", &n, &m);
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					temp = getchar();
					if (temp == '\n')
						temp = getchar();
					if (temp == '.')
						map[i][j] = 0;
					else
					{
						map[i][j] = temp;
					}
				}
			}
			bool flag = false;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (map[i][j])
					{
						if (go(i, j))
							continue;
						else
						{
							if (search(i, j))
							{
								flag = true;
								break;
							}
							cnt++;
						}
					}
				}
				if (flag)
					break;
			}
			if (flag)
			{
				printf("Sad Bobby!\n");
			}
			else
			{
				printf("%d\n", cnt);
			}
		}
	}
}
bool go(int x, int y)
{
	if (map[x][y] == '>')
	{
		for (int i = y+1; i < m; i++)
		{
			if (map[x][i])
			{
				return true;
			}
		}
		return false;
	}
	if (map[x][y]=='<')
	{
		for (int i = y-1; i >= 0; i--)
		{
			if (map[x][i])
			{
				return true;
			}
		}
		return false;
	}
	if (map[x][y] == 'v')
	{
		for (int i = x + 1; i < n; i++)
		{
			if (map[i][y])
			{
				return true;
			}
		}
		return false;
	}
	if (map[x][y] == '^')
	{
		for (int i = x - 1; i >= 0; i--)
		{
			if (map[i][y])
			{
				return true;
			}
		}
		return false;
	}
}
bool search(int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		if (map[i][y])
			return false;
	}
	for (int i = x + 1; i < n; i++)
	{
		if (map[i][y])
			return false;
	}
	for (int i = 0; i < y; i++)
	{
		if (map[x][i])
		{
			return false;
		}
	}
	for (int i = y + 1; i < m; i++)
	{
		if (map[x][i])
			return false;
	}
	return true;
}