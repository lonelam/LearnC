#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
map<char,int> proj {{'A',0},{'C',1},{'G',2},{'T',3}};
map<int,char> rpro {{0,'A'},{1,'C'},{2,'G'},{3,'T'}};
int main()
{
	int t;
	ios::sync_with_stdio(false);
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int m,n;
		cin>>m>>n;
		vector<vector<int>> cons(n,vector<int>(4,0));
		string temp;
		for(int j=0;j<m;j++)
		{
			cin>>temp;
			for(int k = 0;k < n;k++)
			{
				cons[k][proj[temp[k]]]++;
			}
		}
		int sum = 0;
		for(int j=0;j<n;j++)
		{
			int m_ = 0;
			for(int k=0;k<4;k++)
			{
				if(cons[j][k]>m_)
				{
					m_ = cons[j][k];
					temp[j] = rpro[k];
				}
			}
			int ham = 0;
			for(int k=0;k<4;k++)
			{
				if(temp[k]!=rpro[k])
				{
					ham+=cons[j][k];
				}
			}
			sum+=ham;
			cout<<"**ham: "<<ham<<endl;
		}
		cout<<temp<<endl;
		cout<<sum<<endl;
	}
	return 0;
 } 
