#include<iostream>
#include<string>
int main()
{
	int n;
	using namespace std;
	string s;
	while(scanf("%d",&n)!=EOF)
	{
		for(int x=0;x<n;x++)
		{
		int drop=2;
		cin>>s;
		int i=s.length();
		cout<<i<<endl;
		for(int j=i-1;j>=0;j--)
		{
			if(s[j]!=s[i-j-1])
			{
				i++;
				drop--;
			}
		}
		if(drop>0)
		{
			cout<<"YES";
		}
		else
		{
			cout<<"NO";
		}
	}
	}
}
