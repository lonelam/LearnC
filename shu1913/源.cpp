#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
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

int main()
{
	double bx, by, jx, jy, wx1, wy1, wx2, wy2;
	int t;
	while (scanf("%d", &t) != EOF)
	{
		for (int i = 0; i < t; i++)
		{
			scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &bx, &by, &jx, &jy, &wx1, &wy1, &wx2, &wy2);
			double temp1 = (by - jy) / (bx - jx)*(wx1 - bx) + by - wy1;
			double temp2 = (by - jy) / (bx - jx)*(wx2 - bx) + by - wy2;
			if (temp1*temp2 < 0)
			{
				temp1 = sqrt((bx - wx1)*(bx - wx1) + (by - wy1)*(by - wy1)) + sqrt((jx - wx1)*(jx - wx1) + (jy - wy1)*(jy - wy1));
				temp2 = sqrt((bx - wx2)*(bx - wx2) + (by - wy2)*(by - wy2)) + sqrt((jx - wx2)*(jx - wx2) + (jy - wy2)*(jy - wy2));
				printf("%.3f\n", min(temp1, temp2));
			}
			else
			{
				printf("%.3f\n", sqrt((bx - jx)*(bx - jx) + (by - jy)*(by - jy)));
			}
		}
	}
	return 0;
}