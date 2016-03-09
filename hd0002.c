#include<stdio.h>
int main(void)
{
	const float pi=3.1415927;
	const float kdis=12.0*5280.0;
	const float ktime=3600;
	float diameter,time,distance,mph;
	int rev;
	int n=0;
	while(1)
	{
		scanf("%f %d %f",&diameter,&rev,&time);
		if (rev==0) return 0;
		n++;
		distance=pi*diameter*rev/kdis;
		mph=pi*diameter*rev/kdis/time*ktime;
		printf("Trip #%d: %1.2f %1.2f\n",n,distance,mph);
			}		
}
