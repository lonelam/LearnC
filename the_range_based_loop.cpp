//The range based for loop
#include<iostream>
int main(void)
{
	using namespace std;
	double price[5]={1.23,34.32,43.23,435.21};
	for(double i : price)
	{
		cout<<i<<endl;
	}
}
