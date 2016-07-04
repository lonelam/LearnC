
#include<cstdio>
int main()
{
    long long CC[50]={0,1,1};
    for(int i=3;i<50;i++)
    {
        CC[i]=CC[i-1]+CC[i-2];
    }
    int a,b,n,c;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0 ; i< n; i++)
        {
            scanf("%d%d",&a,&b);
            printf("%lld\n",CC[b-a+1]);
        }
    }
}
