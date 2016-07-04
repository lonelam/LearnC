//file:Chap7PE
#include<iostream>
using namespace std;
double h_mean(double,double);
int main(void)
{
	double x,y;
	while(true)
	{
		cout<<"Enter a pair of number:";
		cin>>x>>y;
		if(!x&&!y) return 0;
		cout<<"the so-called harmonic mean is:"<<h_mean(x,y)<<endl;
	}
}
double h_mean(double a,double b)
{
	return 2*a*b/(a+b);
}
