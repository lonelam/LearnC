#include<cstdio>
long long  choice[61]={0,3,6,6};
int main()
{
    for(int i=4;i<61;i++)
    {
        choice[i]=choice[i-1]+choice[i-2]*2;
    }
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%lld\n",choice[n]);
    }
}
