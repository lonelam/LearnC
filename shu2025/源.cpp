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
bool hep[101];
int main()
{
	int t, temp, ans;
	while (cin >> t)
	{
		cin.get();
		while (t--)
		{
			int len = 0;
			ans = 0;
			
			while ((temp = cin.get()) != '\n')
			{
				if (temp == '-')
				{
					hep[len] = false;
				}
				else
				{
					hep[len] = true;
				}
				len++;
			}
			len--;
			while (len >= 0)
			{		

				while (hep[len]&&len>0)
				{
					len--;
				}
				if (hep[len] == true)
				{
					break;
				}
				ans++;
				for (int i = 0; i < len; i++)
				{
					hep[i] = !hep[i];
				}
				len--;
			
			}
			cout << ans << endl;
		}
	}
}