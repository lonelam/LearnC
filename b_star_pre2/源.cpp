#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int main()
{
	unsigned char s[100000];
	int t,n,cnt =0;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		cnt++;
		cin.get();
		cin.getline(s, 100000);
		cout << "Case #" << cnt<<":\n";
		int len = strlen(s);
		scanf("%d", &n);
		int index = 0;
		int lines = len / n +1;
		int morechar = len % n;
		for (int j = 0; j < lines; j++)
		{
			for (int k = 0; k < n; k++)
			{
				cout<<s[index + k * lines];
			    
			}

			index++;
			
		}
		for (int j = 0; j < morechar; j++)
		{
			cout<<s[index + j * lines];
		}
		cout << endl;
	}
	return 0;
}
