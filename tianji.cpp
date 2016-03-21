#include<cstdio>
#include<algorithm>
int main(void)
{
	int n;
	int * k;
	int * t;
	int kl,kh,tl,th,win;
	using namespace std;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) return 0;
		k = new int[n];
		t= new int[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",t+i);
		}
		for(int i=0;i<n;i++)
		{ 
			scanf("%d",k+i);
		}
		sort(k,k+n);
		sort(t,t+n);
		kl=0;
		kh=n-1;
		tl=0;
		th=n-1;
		win=0;
		while(tl<=th)
		{
			if(t[tl]>k[kl])
			{
				tl++;
				kl++;
				win++;
			}
			else if(t[tl]<k[kl])
			{
				tl++;
				kh--;
				win--;
			}
			else if(t[th]>k[kh])
			{
				th--;
				kh--;
				win++;
			}
			else if(t[tl]==k[kh])
				{
					break;
				}
			else if(t[tl]<k[kh])
				{
					tl++;
					kh--;
					win--;
				}
		}
		delete k;
		delete t;
		printf("%d\n", win*200);
	}
	return 0;
}
