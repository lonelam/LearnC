#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
int main()
{
	int n,a,b,c,lk;
	while(scanf("%d",&n)!=EOF)
	{
		std::vector<int> solve;
		if(!n)
		{
			break;
		}
		for(lk=1;lk<=n;lk*=10)
		{
			a=(n/lk)/11;
			b=(n/lk)%11;
			c=(n%lk)/2;
			if((a||b)&&b<10&&n==((11*a+b)*lk+2*c))
			{
				solve.push_back((10*a+b)*lk+c);
			}
			
			{
				c=(n%lk+lk)/2;
			    b=(n/lk-1)%11;
			    a=(n/lk-1)/11;
			}
			
			if((a||b)&&b<10&&n==((11*a+b)*lk+2*c))
			{
				solve.push_back((10*a+b)*lk+c);
			}
		}
		if(solve.empty())
		{
			printf("No solution.\n");
		}
		else
		{
			int tmp=-1;
			std::sort(solve.begin(),solve.end());
			bool flag=false;
			for(int i=0;i<solve.size();i++)
			{
				
				if(solve[i]!=tmp){
					
					if(flag)
					{
						printf(" ");
					}
					else flag=true;
					printf("%d",solve[i]);
				}
				    
				tmp=solve[i];
			}
			printf("\n");
		}
	}
}
