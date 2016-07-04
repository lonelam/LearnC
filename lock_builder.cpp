#include<iostream>
#include"lock.cxx"
using namespace std;
int main(void)
{
	using namespace main_lai_lock;
	lock mylock(2,1,2);
	mylock.rotate(true,42);
	mylock.rotate(false,1);
	mylock.rotate(true,1);
	if(mylock.try_unlock())
	{
		cout<<"Unlocked successfully"<<endl;
		mylock.set(20,40,10);
	}
	cout<<mylock.getnum();
	cin.get();
	return 0;
}
