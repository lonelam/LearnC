//shu1147
#include<iostream>
#include<string>
#include<cstdio>
int main()
{
	using namespace std;
	int n,len;
	string * s;
	string temp;
	char t[10];
	while(cin>>n)
	{
		s = new string[n];
		for(int i=0;i<n;i++)
		{
			scanf("%s",t);
			s[i]=t;
			for(int j=0;j<i;j++)
			{
				if(s[j]==s[i])
				{
					i--;
					n--;
					break;
				}else if(s[j]>s[i])
				{
					for(int k=i;k>j;k--)
					{
						temp=s[k];
						s[k]=s[k-1];
						s[k-1]=temp;
					}
					break;
				}
			}
		}
		cout<<n<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<s[i]<<endl;
		}
		delete[] s;
	}
	return 0;
}
