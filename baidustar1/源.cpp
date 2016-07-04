#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int last_hash ;
void modd(unsigned char c)
{
	last_hash = (last_hash * (c - 28)) % 9973;
}
int hash_(string & s)
{
	last_hash = 1;
	for_each(s.begin(), s.end(), modd);
	return last_hash;
}

class Solution {
public:
	bool dfs(vector<vector<char>>& grid, int x, int y)
	{
		if (grid[x][y] == '0')
		{
			return false;
		}
		else
		{
			grid[x][y] = '0';
			if (x>0 && grid[x - 1][y] == '1')
			{
				dfs(grid, x - 1, y);
			}

			if (y>0 && grid[x][y - 1] == '1')
			{
				dfs(grid, x, y - 1);
			}
			if (y<grid[0].size() && grid[x][y + 1] == '1')
			{
				dfs(grid, x, y + 1);
			}
			if (x<grid.size() && grid[x + 1][y] == '1')
			{
				dfs(grid, x + 1, y);
			}
		}
		return true;
	}
	int numIslands(vector<vector<char>>& gg) {
		int islands = 0;
		for (int i = 0; i<gg.size(); i++)
		{
			for (int j = 0; j<gg[0].size(); j++)
			{
				if (dfs(gg, i, j))
				{
					islands++;
				}
			}
		}
		return islands;
	}
};

int main()
{

	vector<vector<char>> gg;
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			 gg[i][j]=cin.get();
		}
		while (cin.get() == '\n')
			continue;
	}
}