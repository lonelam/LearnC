//file test2253.cpp
#include<iostream>
#include<cstdlib>
#include<ctime>
int main()
{
	using namespace std;
	srand(time(0));
	for(int i=0;i<10;i++)
	{
		cout<<rand()%360<<endl;
	}
	srand(time(0));
	for(int i=0;i<10;i++)
	{
		cout<<rand()%360<<endl;
	}
}
