
/*************************************************************************
	> File Name: hd1316.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月18日 星期一 20时25分26秒
 ************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct stick
{
    int l;
    int w;
};
bool cmp(stick a,stick b);
int main_1316()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            int t,t1,t2;
            scanf("%d",&t);
            vector<stick> k;
            for(int j=0;j<t;j++)
            {
                scanf("%d%d",&t1,&t2);
                stick tmp={t1,t2};
                k.push_back(tmp);
            }
            sort(k.begin(),k.end(),cmp);
            int j=0;
            int ii=0;
            int cnt=0;
            while(k.size())
            {
				ii++;
                if(ii==k.size())
                {
                    k.erase(k.begin()+j);
                    j=0;
                    ii=0;
                    cnt++;
                }
				else if(k[j].l<=k[ii].l&&k[j].w<=k[ii].w)
                {
                    k.erase(k.begin()+j);
					j = --ii;
                }
            }
            printf("%d\n",cnt);
        }
    }
}
bool cmp(stick a,stick b)
{
	if (a.l < b.l)
	{
		return true;
	}
	else if (a.l>b.l)
	{
		return false;
	}
	else if (a.l == b.l)
	{
		return a.w < b.w;
	}
}
