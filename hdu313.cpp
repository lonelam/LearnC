//hdu313

#include<iostream>
#include<array>

using namespace std;

array<long long,51> f;
int main()
{
	f[1] = 1;
	f[2] = 2;
	for(int i=3;i<51;i++)
	{
		f[i] = f[i-1] + f[i-2];
	}
	int t,n,m;
	while(scanf("%d",&n)!=EOF)
	{
		
		printf("%lld\n",f[n]);
	}
}
