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
	*/
	using namespace std;
	bool ispyl(string & h)
	{
		int i = 0, j = h.size() - 1;
		while (i < j)
		{
			if (h[i] != h[j])
			{
				return false;
			}
			i++;
			j--;
		}
		if (i == j)
		{
			return false;
		}
		return true;
	}
	void nextnum(string & h)
	{
		int i = h.size() - 1;
		while (h[i] == '9'&& i>=0)
		{
			h[i] = '0';
			i--;
		}

		if (i <= 0  )
		{
			h.insert(0, "1");
			return;
		}
		else
		{
			h[i] += 1;
		}
		return;
	}
	int main()
	{

		string temp;
		cin >> temp;
		cout << temp;

		for (auto i = temp.rbegin(); i != temp.rend(); i++)
		{
			cout.put(*i);
		}
		cout << endl;
	}