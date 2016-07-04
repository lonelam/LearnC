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
*           │                        │20有2种，50有50，2个20（4种），1个10，共5种
*           └─┐  ┐  ┌───────┬──┐  ┌──┘
*             │ ─┤ ─┤       │ ─┤ ─┤100的话，有100，2*50，11种
*             └──┴──┘       └──┴──┘
*                 神兽保佑
*                 代码无BUG!
*/
using namespace std;
int dp[1001];//
int main()
{
	int n;
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 51; j++)
		{
			for (int k = 0; k < 21; k++)
			{
				for (int l = 0; l < 11; l++)
				{
					
					if ((n=i + j * 2 + k * 5 + l * 10 )< 101)
					{
						dp[n] ++;
					}
				}
			}
		}
	}
	while (scanf("%d", &n) != EOF)
	{
		printf("%d\n", dp[n / 10]);
	}
}