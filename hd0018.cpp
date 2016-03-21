#include<iostream>
int main(void)
{
	using namespace std;
	int addup[100];
	int jsnum,jsmark,rank;
	int num,mark,i;
	while(cin>>jsnum)
	{
		rank=1;
		for(i=1;i<101;i++)
		{
			addup[i]=0;
		}
		while(cin>>num>>mark&&num!=0)
		{
			if(num==jsnum) jsmark=mark;
			addup[mark]++;
		}
		for(i=100;i>jsmark;i--)
		{
			rank+=addup[i];
		}
		cout<<rank<<endl;
	}
	return 0;
}
