#include<iostream>
const int MAXMIN = 60;
struct time 
{
	int hours;
	int minutes;
};
time addup(const time a,const time b);
int main()
{
	using namespace std;
	time T1={1,50};
	time T2={2,20};
	time result;
	result = addup(T1,T2);
	cout<<"hours:"<<result.hours<<endl;
	cout<<"minutes:"<<result.minutes<<endl;
}
time addup(const time a,const time b)
{
	time total;
	total.hours=a.hours+b.hours+(a.minutes+b.minutes)/MAXMIN;
	total.minutes=(a.minutes+b.minutes)%MAXMIN;
	return total;
}
