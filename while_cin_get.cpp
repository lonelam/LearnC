#include<iostream>
int main(void)
{
	using namespace std;
	double Input;
	while(!(cin>>Input))
	{
		cin.clear();
		while(cin.get()!='\n')
		  ;
		cout<<"bad input plz send a number";
	}
 }
