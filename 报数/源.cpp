#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int search(vector<int> &vv,int x,int l,int r)
{
	if (l == r)
	{
		if (vv[l]>x&&l!=0)
		{
			return l-1;
		}
			return l;

	}
	int mid = (l + r) / 2;
	if (vv[mid] == x)
		return mid;
	if (vv[mid] > x)
	{
		return search(vv, x, l, mid);
	}
	else
	{
		return search(vv, x, mid + 1, r);
	}
}
int bs(vector<int>&vv, int x)
{
	return vv[search(vv, x, 0, vv.size() - 1)];
}
int main()
{
	int n, m,temp;
	scanf("%d%d", &n, &m);
	vector<int> l;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		l.push_back(temp);
	}
	sort(l.begin(), l.end());
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &temp);
		if(i!=m-1)
		printf("%d ", bs(l, temp));
		else
		{
			printf("%d", bs(l, temp));
		}
	}
}