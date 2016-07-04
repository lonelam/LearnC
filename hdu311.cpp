//hdu311

#include<iostream>
#include<array>

using namespace std;

array<long long,41> f;
int main()
{
	f[1] = 1;
	f[2] = 1;
	for(int i=3;i<41;i++)
	{
		f[i] = f[i-1] + f[i-2];
	}
	int t,n;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		printf("%lld\n",f[n]);
	}
}
