#include<iostream>
#include<algorithm>

using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000005;
int rec[MAXN],nex[MAXN],b[MAXN];
void init()
{
    rec[1] = 1;
    rec[2] = 2;
    for(int i = 1;i<MAXN;i++)
    {
        nex[i] = i;
    }
    for(int i=2;i<MAXN;i++)
    {
        if(b[i] == 0)
        {
            for(int j = 1;i*j<MAXN;j++)
            {
                if(b[i*j]==0)
                {
                    b[i*j] = i;
                }
            }
            
        }
    }
    int cur = 2;
    for(int i=2;i<MAXN;i++)
    {
        int k = cur;
        cur = MAXN;
        for(int p = b[k]; p!=1 ;)
        {
            while(rec[nex[p]] && nex[p]+p<MAXN)
            {
                nex[p] += p;
            }
            cur = min(cur,nex[p]);
            while(k%p == 0)
            {
                k = k/p;
            }
            p = b[k];
        }
        rec[cur] = i+1;
      
    }
}
int main()
{
    int t,n;
    init();
    while(cin>>t)
    {
        while(t--)
        {
            cin>>n;
            cout<<"The number "<<n<<" appears in location "<<rec[n]<<"."<<endl;
        }
    }
}
