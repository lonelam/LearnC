//Chapter 7 review
//three steps in using a function.
//construct function prototypes that match the following descriptions.
#include<string>
#include<iostream>
struct boss{
	int a,b;
};
struct map{
	int x;
	int y;
};
void igor(void);
float tofu(int);
double mpg(double,double);
long summation(long *,int);
double doctor(const std::string);
void ofcourse(boss);
std::string plot(map*);
void all_set(int [],int,int);
void all_set2(int[],int[],int);
struct applicant {
	char name[30];
	int credit_ratings[3];
};
typedef const char * (*type2)(const applicant * a1,const applicant *a2);
type2 p1;
type2 pa[10];
int main()
{
	
}
void all_set(int a[],int len,int val)
{
	for(int i=0;i<len;i++)
	{
		a[i]=val;
	}
}
