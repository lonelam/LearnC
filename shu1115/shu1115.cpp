#include<cstdio>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int temp;
        int last;
        int cnt =0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            if(cnt==0)
            {
                last=temp;
                cnt++;
            }
            else
            {
                if(last!=temp)
                {
                    cnt--;
                }
                else
                {
                    cnt++;
                }
            }
        }
        printf("%d\n",last);
    }
}
