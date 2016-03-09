#include<iostream>
using namespace std;
int main(void)
{
	void arrow(int len,int amount);
	int t,n,a,b,i,j;
	int addup[30]={0}; 
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n;
		for (j=0;j<n;j++)
		{
			cin>>a>>b;
			addup[a]=addup[a]+b;
		}
		for (j=0;j<30;j++)
	    {
		    arrow(j,addup[j]);
		    if (addup[j]>0) cout<<endl;
	    }
	    for (j=0;j<30;j++)
	    {
	    	addup[j]=0;
		}
	}
	
 } 
 void arrow(int len,int amount)
	{
		int i;
		len=len-2;
		while(amount)
		{
			cout<<">+";
			for(i=0;i<len;i++)
			{
				cout<<"-";
			}
			cout<<"+>"<<endl;
			amount--;
		}
	}
