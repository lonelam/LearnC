#include<cstdio>
int main()
{
    int n;
    int i=1;
    int bank=0;
    int cash=0;
    int notsuff=0;
    while(scanf("%d",&n)!=EOF)
    {

            cash+=300;
            int temp = cash -n;
            if(temp<0)
            {
                if(!notsuff)
                    notsuff=i;
            }
            else
            {
                int depo=temp/100;
                    bank+=depo*100;
                    cash = temp %100;

            }
            i++;

        if(i==13)
        {
            i=1;
            if(notsuff)
                {
                    printf("%d\n",-notsuff);
                    notsuff=0;
                }
            else
            {
                printf("%.f\n",bank*1.2+cash);
            }
            bank=0;
            cash=0;
        }

    }
    return 0;
}
