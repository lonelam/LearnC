#include<cstdio>
enum posi {A,B,C};
posi pans[65];
bool sear(posi orig,posi mid, posi dest,int bottom);
int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        int n,a,tem;
        for(int j=0; j<t; j++)
        {
            scanf("%d",&n);
            scanf("%d",&a);
            for(int i=0; i<a; i++)
            {
                scanf("%d",&tem);
                pans[tem]=A;
            }
            scanf("%d",&a);
            for(int i=0; i<a; i++)
            {
                scanf("%d",&tem);
                pans[tem]=B;
            }
            scanf("%d",&a);
            for(int i=0; i<a; i++)
            {
                scanf("%d",&tem);
                pans[tem]=C;
            }
            if(sear(A,B,C,n))
            {
                printf("true\n");
            }
            else
                printf("false\n");
        }
    }
}
bool sear(posi orig,posi mid, posi dest,int bottom)
{
    if(bottom==0)
        return true;
    if(pans[bottom]==mid)
        return false;
    else
    {
        if(pans[bottom]==orig)
            return sear(orig,dest,mid,bottom-1);
        else
            return sear(mid,orig,dest,bottom-1);
    }
}
