//hdu314

#include<iostream>
#include<array>

using namespace std;

array<long long,21> f;
int main()
{
	f[0] = 1;
	f[1] = 3;
	for(int i=2;i<21;i++)
	{
		f[i] = 2 * f[i-1] + f[i-2] ;
	}
	int t,n,m;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		printf("%lld\n",f[n]);
	}
	return 0;
}
