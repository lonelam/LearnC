//file simulationbank
#include"lqueue.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
bool new_customer(double interval);
int main()
{
	using namespace std;
	srand(time(0));
	cout<<"Enter queue size : ";
	int size;
	cin>>size;
	lqueue line(size);
	int hours;
	cout<<"How many hours : ";
	cin>>hours;
	double gap;
	cout<<"Enter the interval between two average costomers : ";
	cin>>gap;
	Item temp;
	long turnaway = 0;
	long customers = 0;
	long served =0;
	long sum_line = 0;
	int wait_time = 0;
	long line_wait = 0;
	for(int cycle = 0;cycle<hours;cycle++)
	{
		if(new_customer(gap))
		{
			if(line.isfull())
			    turnaway++;
			else
			{
				customers++;
				temp.set(cycle);
				line.enqueue(temp);
			}
		}
		if(wait_time<=0 && !line.isempty())
		{
			line.dequeue(temp);
			wait_time = temp.ptime();
			line_wait += (cycle-temp.when());
			served++; 
		}
		if(wait_time>0)
		    wait_time--;
		sum_line += line.qcount();
	}
	if(customers>0)
	{
		cout<<"customers accepted: "<<customers<<endl;
		cout<<"  customers served: "<<served<<endl;
		cout<<"          turnaway: "<<turnaway<<endl;
		cout<<"average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed,ios_base::floatfield);
		cout<<(double) sum_line/hours<<endl;
		cout<<"  average wait time:"<<(double)line_wait/served<<"hours\n";
	}
	else
		cout<<"No customers!"<<endl;
	cout<<"Done!\n";
	cin.get();
	return 0;
}
bool new_customer(double interval)
{
	return double(rand())/RAND_MAX < (1/interval);
}
