#include<stdio.h>
int main(void){
	int input,a,b,c;
	while(scanf("%d",&input)!=EOF){
		if (input==0) return 0;
		a=input/100;
		b=input/10-a*10;
		c=input-b*10-a*100;
		if (b!=0 && c>b) c=b;
		if (a!=0) c=a;
		printf("%d\n",c);
	}
}
