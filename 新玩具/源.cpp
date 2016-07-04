#include<queue>
#include<iostream>

using namespace std;
int main()
{
	int n;
	double value,t1,t2;
	priority_queue<double> q;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		q.push(value);
	}
	while (q.size() > 1)
	{
		t1 = q.top();
		q.pop();
		t2 = q.top();
		q.pop();
		value = pow(t1*t2*t2, 1. / 3);
		q.push(value);
	}
	cout << value;
}