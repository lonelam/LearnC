#include<cstdio>
#include<string>
#include<iostream>
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			std::string x;
			std::cin >> x;
			x = "z" + x;
			bool flag = true;
			int cnt=0;
			while (x.size()-1)
			{
				if (x.back() == 'z')
				{
					x.pop_back();
					if (x.back()=='z')
					{
						cnt ++;
					}
						if (flag)
						{
							cnt ++;
						}
					
					flag = true;
				}
				else
				{
					x.pop_back();
					flag = 0;
				}

			}
			printf("%d\n", (cnt) / 2);


		}
	}
}