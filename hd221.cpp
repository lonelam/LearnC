#include<cstdio>
int s(int a,int b);
int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		if(m>n)
		printf("%d\n",n*m/s(n,m));
		else
		printf("%d\n",n*m/s(m,n));
	}
}
int s(int a,int b)
{
	int temp=b-a;
	if(a==b)
	    return a;
	else if(a<temp)
	    return s(a,temp);
	else
	    return s(temp,a);
}
