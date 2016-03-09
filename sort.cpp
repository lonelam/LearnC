#include<stdio.h>
int main(void)
{
	int cow[10005];
	int n,i,j,temp;
	while(scanf("%d",&n)!=EOF){
	for(i=0;i<n;i++)
	{
		scanf("%d",&cow[i]);
	}
		for (i = 1; i < n; i++) {
		temp = cow[i]; 
		for (j = i - 1; j >= 0 && cow[j] > temp; j--)
		cow[j + 1] = cow[j];
		    cow[j + 1] = temp; 
	}
	printf("%d\n",cow[(n-1)/2]);
}
	return 0;
}
