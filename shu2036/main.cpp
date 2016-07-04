#include <iostream>
#include <algorithm>
using namespace std;

int ascend[100];
int descend[100];
int height[100];
int solve(int n)
{
    int max_in = 0;
    for(int i=0;i<n;i++)
    {
        ascend[i] = 1;
        for(int j=0;j<i;j++)
        {
            if(height[j]<height[i])
            {
                ascend[i] = max(ascend[i],ascend[j]+1);
            }
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        descend[i] = 1;
        for (int j = n - 1; j > i; j--)
        {
            if (height[j] < height[i])
            {
                descend[i] = max(descend[i], descend[j] + 1);
            }
        }
        max_in = max(max_in,descend[i]+ascend[i]-1);
    }
    return max_in;
}
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>height[i];
        }
        cout<<n-solve(n)<<endl;
    }

    return 0;
}