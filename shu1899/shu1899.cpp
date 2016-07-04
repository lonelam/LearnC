#include<iostream>
using namespace std;
const int UPBD = 2000000000;
int mem[100000]{ 0 };
bool odd(int n)
{
	int i = 0;
	while (n > mem[++i]);
	return i & 1;
}
int main()
{
	int i = 0, ans = 0;
	while (mem[i] < UPBD)
	{
		mem[++i] = i*i + (i << 1);
	}
	int t,n;
	while (cin >> t)
	{
		while (t--)
		{
			cin >> n;
			if (odd(n))
			{
				cout << 1 << endl;
			}
			else
			{
				cout << 0 << endl;
			}
		}
	}
}
