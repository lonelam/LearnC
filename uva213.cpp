#include<iostream>
#include<string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	string code,doc;
	while(getline(cin,doc))
	{
		if(doc[0]!='0'&&doc[0]!='1')
		{
			code = doc;
			continue;
		}
		string decoded;
		int i=0,index =0;
		while(i<code.size()&&index<doc.size())
		{
			
			for(int j=0;j<(1<<i)&&index<doc.size();j++)
			{
			    int ab = 0;
				for(int k=0;k<=i;k++)
				{
				if(doc[index++] == '1')
				{
					ab = (ab<<1)+1;
				}
				else
				{
					ab <<=1;
				}
			    }
			    cout<<"\n**debug ab = "<<ab<<endl;
				decoded.push_back(code[i+ab]);
			}
			
			i++;
		}
		cout<<decoded;
	}
 } 
