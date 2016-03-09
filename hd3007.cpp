#include<stdio.h>
int main(void){
	int n,m,a,sum;
	bool printb=false;
	scanf("%d",&n);
	while(n){
		n--;
		scanf("%d",&m);
		sum=0;
		while(m){
			m--;
			scanf("%d",&a);
			sum=sum+a;
			}
		if(printb) printf("\n"); else
		printb=true;
		printf("%d\n",sum);
		}
}
