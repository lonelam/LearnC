#include<cstdio>
#include<cmath>
#include<cstring>
int  circuit(long long  root, int len);
bool search(int cnt,long long p);
long long ms[100];
int main()
{
	int n, l;
	while (scanf("%lld%d", &n, &l) != EOF)
	{
		printf("%lld\n", circuit(n, l));
	}
}
int  circuit(long long root, int len)
{
	
	if (len == 1)
	{
		memset(ms, 0, sizeof(ms));
		int exp = 10;
		int cnt = 0;
		int lowbits = 1;
		while (search(cnt-1, lowbits))
		{
			
			lowbits = lowbits*root%exp;
			ms[cnt] = lowbits;
			cnt++;
			
		}
		return cnt-1;
	}
	else
	{
		memset(ms, 0, sizeof(ms));
		long long exp = pow(10, len);
		int cnt = 0;
		int lowbits = 1;
		int l_r = circuit(root, len - 1);
		if (l_r == -1)
			return -1;
		long long roll = pow(root, l_r);
		bool flag = false;
		while (search(cnt-1, lowbits)||flag)
		{
			lowbits = lowbits*roll%exp;
			ms[cnt] = lowbits;
			flag = l_r* cnt>100;
			cnt++;
		}
		if (flag)
			return -1;
		return (cnt-1) * l_r;
		
	}
}
bool search(int cnt, long long p)
{
	for (int i = 0; i < cnt; i++)
		if (ms[i] == p)
			return false;
	return true;
}