#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int s1,s2,e1,e2;
int tu[8][8];
int xx[8]={1,2,1,2,-1,-2,-1,-2};
int yy[8]={2,1,-2,-1,2,1,-2,-1};
int bfs()
{
    memset(tu,0,sizeof(tu));
    queue<int> q;
    int x1,y1,x2,y2;
    q.push(s1);
    q.push(s2);
    while(!q.empty())
    {
        x1=q.front();
        q.pop();
        y1=q.front();
        q.pop();
        if(x1==e1&&y1==e2)
            return tu[x1][y1];
        for(int i=0;i<8;i++)
        {
            x2=x1+xx[i];
            y2=y1+yy[i];
            if(x2<0||x2>7||y2<0||y2>7||tu[x2][y2]>0)
                continue;
            tu[x2][y2]=tu[x1][y1]+1;
            q.push(x2);
            q.push(y2);
        }
    }
    return 0;
}
int main()
{
    char a[3],b[3];
    int total;
    while(scanf("%s",a)!=EOF)
    {
        scanf("%s",b);
        s1=a[0]-'a';
        s2=a[1]-'1';
        e1=b[0]-'a';
        e2=b[1]-'1';
        total=bfs();
        printf("To get from %s to %s takes %d knight moves.\n",a,b,total);

    }
}
