#include<iostream>        //��ͼ��ɫ��,��ʹ�����ڶ������ɫ����ͬ�������Сɫ��.������С,ֱ��ö��+DFS
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
            color[i]=0;        //ö��ɫ��num�ı�ʱҪ�����ж������ɫ�ٴγ�ʼ��
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
        for(num=1;num<=4;++num)        //ö��ɫ��, ������ɫ����,ɫ�����Ϊ4
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
