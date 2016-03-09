#include<stdio.h>
int main(void)
{
	int n,u,d,height,time;
	while(1){
		scanf("%d%d%d",&n,&u,&d);
		if (u==0) return 0;
		height=0;
		time=0;
		while (height<n-u){
			height=height+u-d;
			time+=2;
		}
		printf("%d\n",time+1);
	}
}
