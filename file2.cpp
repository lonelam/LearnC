//file2.cpp
#include<iostream>
#include<cmath>
#include"coordin.h"
polar trans_rect(const rect & ordin)
{
	using namespace std;
	polar ret;
	ret.angle=atan2(ordin.y,ordin.x);
	ret.distance=sqrt(ordin.x*ordin.x+ordin.y*ordin.y);
	return ret;
}
void show_pol(const polar & p)
{
	std::cout<<"The distance is "<<p.distance<<std::endl;
	std::cout<<"The angle is "<<p.angle<<std::endl;
}
