//randwalk
//file:exec.cpp
#include"vector_h.h"
#include<ctime>
const double PACE=1.00;
const double RADIUS=10.00;
int randwalk()
{
	using std::cout;
	using std::endl;
	using namespace VECT;
	srand(time(0));
	vector step;
	vector position;
	int cnt=0;
	while(position.magval()<RADIUS)
	{
		step.reset(PACE,rand()%360,vector::POL);
		cnt++;
		position=position+step;
	}
	cout<<"After "<<cnt<<" Steps, we have reached the cornor of dark."<<endl;
}
int main()
{
	VECT::fwalk();
	return 0;
}
