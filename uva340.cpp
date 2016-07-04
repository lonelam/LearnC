#include<cstdio> 
#include<vector>

using namespace std;

vector<char> code(1001),guess(1001);
int main()
{
			int n,No = 1,temp;
	while(scanf("%d",&n)&&n!=0)
	{

	vector<int> ocnt(10,0);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		code[i] = temp;
		ocnt[temp] ++;
	}
	printf("Game %d:\n",No++);
		
		while(true)
		{
		vector<int> cnt(ocnt),weak(10,0);
		int strong = 0;
		bool zeros = true;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&temp);
			guess[i] = temp;
			if(temp != 0)
			{
				zeros = false;
				if(temp ==code[i])
				{
					strong++;
					if(weak[temp]!=0&&cnt[temp]==0)
					{
						weak[temp]--;
					}
					else
					{
						cnt[temp]--;
					}
				}
				else if(cnt[temp]!=0)
				{
					weak[temp]++;
					cnt[temp]--;
				}
			}
		
		
		}
		if(zeros)
			{
				break;
			}
			int wksum = 0;
			for(int i=1;i<10;i++)
			{
				wksum+=weak[i];
			}
			printf("    (%d,%d)\n",strong,wksum);
	}
	}
}
