#include<iostream>        //求图的色数,即使各相邻顶点的颜色不相同所需的最小色数.数据量小,直接枚举+DFS
#include<stdio.h>
#include<cmath>
#include<cstring>
using namespace std;
struct node
{
    double x,y;
}point[20];
int n,cnt[20][20],color[20],num,suc;
void dfs(int i)
{
    for(int c=1;c<=num;++c)
    {
        int flag=1;
        for(int j=0;j<n;++j)
            if(cnt[i][j]==1&&color[j]==c)
            {
                flag=0;
                break;
            }
        if(flag==1)
        {
            color[i]=c;
            if(i==n-1)
            {
                suc=1;
                break;
            }
            dfs(i+1);
            if(suc==1)
                break;
            color[i]=0;        //枚举色数num改变时要把所有顶点的颜色再次初始化
        }
    }
}
int main()
{
    int cases=1;
    while(cin>>n&&n)
    {
        for(int i=0;i<n;++i)
            cin>>point[i].x>>point[i].y;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;++i)
            for(int j=i+1;j<n;++j)
                if(pow(point[i].x-point[j].x,2.0)+pow(point[i].y-point[j].y,2.0)<=400)
                    cnt[i][j]=cnt[j][i]=1;
        memset(color,0,sizeof(color));
        suc=0;
        for(num=1;num<=4;++num)        //枚举色数, 根据四色定理,色数最大为4
        {
            dfs(0);
            if(suc==1)
            {
                printf("The towers in case %d can be covered in %d frequencies.\n",cases++,num);
                break;
            }
        }
    }
    return 0;
}
