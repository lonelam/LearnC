#include<stdio.h>
int main(void)
{
	int sum,n,operatr,i;
	while(scanf("%d",&n)!=EOF){
	    
		sum=0;
		for(i=0;i<n;i++){
			scanf("%d",&operatr);
			sum+=operatr;
		}
		printf("%d\n",sum);
	}
}
