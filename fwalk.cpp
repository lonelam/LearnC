//file out of randwalk
//fwalk.cpp
#include"vector_h.h"
#include<ctime>
#include<fstream>
#include<cstdlib>
#include<iostream>
#include<string>//For unknown reason without this line the program will turn out to be error.
const double T_DISTANCE =100;
const double STEP_SIZE=20;
int VECT::fwalk()
{
	using namespace std;
	ofstream fout;
	using VECT::vector;
	
	fout.open("walkout.txt");
	if(fout.is_open()){
	vector position,step;
	int cnt=0;
	fout<<"Target Distance: "<<T_DISTANCE<<", Step Size: "<<STEP_SIZE<<endl;
	fout<<position.angval();
	fout<<"0: "<<position;
	srand(time(0));
	while(position.magval()<T_DISTANCE)
	{
		step.reset(STEP_SIZE,rand()%360,vector::POL);
		position=position+step;
		cnt++;
		fout<<cnt<<": "<<position;
		
	}
	
	fout<<"After "<<cnt<<" steps,the subject has the follow location:"<<endl;
	fout<<position;
	position.polar_mode();
	fout<<position;
	fout<<"Averge outward distance per step = "<<position.magval()/cnt<<endl;
	fout.close();
}
else cout<<"ERROR";
return 0;

}
