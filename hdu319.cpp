//hdu319


#include<iostream>
#include<array>

using namespace std;

array<long long,51> f;
int main()
{
	f[0] = 1;
	f[1] = 1;
	f[2] = 2;
	f[3] = 4;
	for(int i=4;i<51;i++)
	{
		f[i] = f[i-1] + f[i-2] + f[i-4];
	}
	int t,n,m;
	while(scanf("%d",&n)!=EOF)
	{
		
		printf("%lld\n",f[n]);
	}
	return 0;
}
