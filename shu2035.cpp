#include<iostream>
#include<cstring>
using namespace std;

char proj[26];//ASCII saved
char code[26];//ASCII saved
bool dfs(char from, char to)//from and to are ASCII
{
    from = from - 'A';
    if(proj[from]==0)
    {
        proj[from] = to;
        if(dfs(to,code[from]))
        {
            return true;
        }
        proj[from] = 0;
        return false;
    }
    if(proj[from]==to)
    {
        return true;
    }
    return false;
}
bool solve()
{
    memset(proj,0,sizeof(proj));
    for(int i=0;i<26;i++)
    {
        if(proj[i]==0)
        {
            for(int j=0;j<26;j++)
            {
                if(dfs(i+'A',j+'A'))
                {
                    break;
                }
            }
        }
    }
    for(int i=0;i<26;i++)
    {
        if(proj[i] == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        for(int i = 0;i<26;i++)
        {
            cin>>code[i];
        }
        if(solve())
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"No\n";
        }
    }
}
