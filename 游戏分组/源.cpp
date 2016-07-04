#include<iostream>
#include<memory>
#include<algorithm>
using namespace std;
class joinset
{
private:
	int * rank, *parent;
	int size;
public:
	joinset(int s)
	{
		rank = new int[s];
		parent = new int[s];
		for (int i = 0; i < s; i++)
		{
			parent[i] = i;
			rank[i] = 0;
		}
	}
	~joinset()
	{
		delete[] rank;
		delete[] parent;
	}
	int set(int x)
	{
		if (parent[x] != x)
		{
			int grand = set(parent[x]);
			rank[grand] = max(rank[x] + 1, rank[grand]);
			parent[x] = grand;
		}
		return parent[x];
	}
	bool join(int x, int y)
	{
		int grand1 = set(x);
		int grand2 = set(y);
		if (grand1 != grand2)
		{
			if (rank[grand1] < rank[grand2])
			{
				parent[grand1] = grand2;
			}
			else
			{
				parent[grand2] = grand1;
				rank[grand1] = max(rank[grand1], rank[grand2] + 1);
			}
			return true;
		}
		return false;
	}
};

int main()
{
	int n, m, a, b;
	cin >> n >> m;
	joinset j(n);
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		if (j.join(a, b))
		{
			n--;
		}
	}
	cout << n;
	
}