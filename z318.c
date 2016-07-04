//zuoye 3.1.8
#include<stdio.h>
#include<math.h>
int main(void)
{
	double rate,salary,result;
	scanf("%lf",&salary);
	if(salary<=850) rate=0;
	else if(salary>850&&salary<=1350) rate=0.05;
	else if(salary>1350&&salary<=2850) rate=0.1;
	else if (salary>2850&&salary<=5850) rate=0.15; 
	else rate=0.2;
	result=rate*(salary-850.0);
	if (result<0.0000000001) result=0;
	printf("Enter the salary: tax=%1.2f",result);
	
	return 0;
}
