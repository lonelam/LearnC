//hdu312

#include<iostream>
#include<array>

using namespace std;

array<long long,50> f;
int main()
{
	f[0] = 1;
	f[1] = 1;
	for(int i=2;i<50;i++)
	{
		f[i] = f[i-1] + f[i-2];
	}
	int t,n,m;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d%d",&n,&m);
		printf("%lld\n",f[m-n]);
	}
}
