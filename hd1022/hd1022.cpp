#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<stack>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	int n;
	bool  train[10];
	while (scanf("%d", &n) != EOF)
	{
		memset(train, 0, 10 * sizeof(bool));
		bool flag = true;
		string res;
		int o1, o2,out,r_o1,r_o2;
		stack<int> st;
		scanf("%d%d", &r_o1, &r_o2);
		o1 = o2 = 0;
		while (r_o1)
		{
			o1 = o1 * 10 + r_o1 % 10;
			o2 = o2 * 10 + r_o2 % 10;
			r_o1 /= 10;
			r_o2 /= 10;
		}
		for (int i = 0; i < n; i++)
		{
			out = o2 % 10;
			while (!train[out])
			{
				train[o1 % 10] = 1;
				st.push(o1 % 10);
				o1 /= 10;
				res += "in\n";
			}
			if (st.top() != out)
			{
				flag = false;
			}
			else
			{
				res += "out\n";
				st.pop();
				o2 /= 10;
			}
			
		}
		if (flag&&st.empty())
		{
			printf("Yes.\n");
			cout << res;
		}
		else
		{
			printf("No.\n");
		}
		printf("FINISH\n");
	}
}