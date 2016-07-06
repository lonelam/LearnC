#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>


/*
-----------Answered by Lonelam---------
*
*          ┌─┐       ┌─┐
*       ┌──┘ ┴───────┘ ┴──┐
*       │                 │
*       │       ───       │
*       │  ─┬┘       └┬─  │
*       │                 │
*       │       ─┴─       │
*       │                 │
*       └───┐         ┌───┘
*           │         │
*           │         │
*           │         │
*           │         └──────────────┐
*           │                        │
*           │                        ├─┐
*           │                        ┌─┘
*           │                        │
*           └─┐  ┐  ┌───────┬──┐  ┌──┘
*             │ ─┤ ─┤       │ ─┤ ─┤
*             └──┴──┘       └──┴──┘
*                 神兽保佑
*                 代码无BUG!

W
L
M35
L
Q
WWWWB---
WWWB----
WWB-----
WB------
--------
--------
--------
--------
B
L
M25
L
Q
*/

using namespace std;

enum color {black,white,none};
const int N = 8;
color d[N][N];
color cur;
vector<pair<int, int> > mvv = { {1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,-1},{-1,0},{-1,1} };

bool search(color c, pair<int, int> to, pair<int, int> dir)
{
	if ((to.first<0||to.second<0)||(to.first>=N||to.second>=N)||d[to.first][to.second] == none)
	{
		return false;
	}
	if (d[to.first][to.second] != c)
	{
		return search(c, { to.first + dir.first,to.second + dir.second }, dir);
	}
	return true;
}

bool search1(color c, pair<int, int> to, pair<int, int> dir)
{
	if ((to.first<0 || to.second<0) || (to.first >= N || to.second >= N) || d[to.first][to.second] == none||d[to.first][to.second] == c)
	{
		return false;
	}
	if (d[to.first][to.second] != c)
	{
		return search(c, { to.first + dir.first,to.second + dir.second }, dir);
	}
}
bool transbar(color c, pair<int, int> to, pair<int, int> dir)
{
	if ((to.first<0 || to.second<0) || (to.first >= N || to.second >= N) || d[to.first][to.second] == none)
	{
		return false;
	}

	if (d[to.first][to.second] != c)
	{
		if (transbar(c, { to.first + dir.first,to.second + dir.second }, dir))
		{
			if (c == white)
			{
				d[to.first][to.second] = white;
			}
			else
			{
				d[to.first][to.second] = black;
			}
			return true;
		}
		else return false;
	}
	return true;
}
bool transbar1(color c, pair<int, int> to, pair<int, int> dir)
{
	if ((to.first<0 || to.second<0) || (to.first >= N || to.second >= N) || d[to.first][to.second] == none||d[to.first][to.second] == c)
	{
		return false;
	}
	if (d[to.first][to.second] != c)
	{
		if (transbar(c, { to.first + dir.first,to.second + dir.second }, dir))
		{
			if (c == white)
			{
				d[to.first][to.second] = white;
			}
			else
			{
				d[to.first][to.second] = black;
			}
			return true;
		}
		else return false;
	}
}
bool is_val(int x, int y)
{
	for (int i = 0; i < 8; i++)
	{
		if (search1(cur, { x + mvv[i].first,y + mvv[i].second }, mvv[i]))
		{
			return true;
		}
	}
	return false;
}

bool lout(color c)
{
	int cnt = 0;
	bool fst = true;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (d[i][j] == none&&is_val(i,j))
			{
				if (!fst)
				{
					cout << ' ';
				}
				else
				{
					fst = false;
				}
				cout << '(' << i + 1 << ',' << j + 1 << ")";
				cnt++;
			}
		}
	}
	if (cnt == 0)
	{
		cout << "No legal move."<<endl;
		return false;
	}
	cout << endl;
	return true;
}

bool is_no_legal(color c)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (d[i][j] == none && is_val(i, j))
			{
				return false;
			}
		}
	}
	return true;
}
int count_color(color c)
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (d[i][j] == c)
			{
				cnt++;
			}
		}
	}
	return cnt;
}
void set(int x, int y)
{
	if (is_no_legal(cur))
	{
		if (cur == white)
		{
			cur = black;
		}
		else
		{
			cur = white;
		}
	}
	for (int i = 0; i < 8; i++)
	{
		transbar1(cur, { x + mvv[i].first,y + mvv[i].second }, mvv[i]);
	}
	d[x][y] = cur;

	if (cur == white)
	{
		cur = black;
	}
	else
	{
		cur = white;
	}
	cout << "Black - " << count_color(black) << " White - " << count_color(white) << endl;
}
void display()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (d[i][j] == none)
			{
				cout << '-';
			}
			else if (d[i][j] == black)
			{
				cout << 'B';
			}
			else
			{
				cout << 'W';
			}
		}
		cout << endl;
	}
}
int main()
{
	cin.sync_with_stdio(false);
	int t;
	char tmp;
	while (cin >> t)
	{
		while (t--)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					cin >> tmp;
					if (tmp == '-')
					{
						d[i][j] = none;
					}
					else if (tmp == 'W')
					{
						d[i][j] = white;
					}
					else
					{
						d[i][j] = black;
					}
				}
			}
			cin >> tmp;
			if (tmp == 'W')
			{
				cur = white;
			}
			else
			{
				cur = black;
			}
			while (true)
			{
				cin >> tmp;
				if (tmp == 'L')
				{
					lout(cur);
				}
				else if (tmp == 'M')
				{
					int x, y;
					cin >> tmp;
					x = tmp - '1';
					cin >> tmp;
					y = tmp - '1';
					set(x, y);
					//display();
				}
				else
				{
					display();
					if (t > 0)
					{
						cout << endl;
					}
					break;
				}
			}

		}
	}
}