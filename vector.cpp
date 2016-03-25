//file:vector.cpp
#include<cmath>
#include"vector_h.h"
#include<string>

namespace VECT
{
	using std::sqrt;
	using std::atan2;
	using std::sin;
	using std::cos;
	using std::cout;
	using std::endl;
	const double RAD2DEG = 180/3.1415926;
	void vector::set_mag()
	{
		mag = sqrt(x*x+y*y);
	}
	void vector::set_ang()
	{
		ang=atan2(y,x);
	}
	void vector::set_x()
	{
		x=mag*cos(ang);
	}
	void vector::set_y()
	{
		y=mag*sin(ang);
	}
	vector::vector()
	{
		mode=RECT;
		x=0;
		y=0;
		set_ang();
		set_mag();	
	}
	vector::vector(double n1,double n2,Mode form)
	{
		mode=form;
		if(form==RECT)
		{
			x=n1;
			y=n2;
			set_mag();
			set_ang();
		}
		else if(form==POL)
		{
			mag=n1;
			ang=n2/RAD2DEG;
			set_x();
			set_y();
		}
		else
		{
			cout<<"Incorrect 3rd argument."<<endl;
			cout<<"Set vector to zero-vector"<<endl;
			x=0;
			y=0;
			set_mag();
			set_ang();
			mode=RECT;
		}
	}
	void vector::reset(double n1,double n2,Mode form)
	{
		mode=form;
		if(form=RECT)
		{
			x=n1;
			y=n2;
			set_mag();
			set_ang();
		}
		else if(form=POL)
		{
			mag=n1;
			ang=n2;
			set_x();
			set_y();
		}
		else
		{
			cout<<"ERROR"<<endl;
		}
	}
	vector::~vector()
	{
		
	}
	void vector::polar_mode()
	{
		mode=POL;
	}
	void vector::rect_mode()
	{
		mode=RECT;
	}
	vector vector::operator+(const vector & v2) const
	{
		return vector(x+v2.x,y+v2.y);
	}
	vector vector::operator-(const vector & v2) const
	{
		return vector(x-v2.x,y-v2.y);
	}
	vector vector::operator-()const
	{
		return vector(-x,-y);
	}
	double vector::operator*(const vector & v2) const
	{
		return x*v2.x+y*v2.y;
	}
	vector vector::operator*(double n) const
	{
		return vector(n*x,n*y);
	}
	vector operator*(double n,const vector & v2)
	{
		return v2*n;
	}
	std::ostream & operator<<(std::ostream & os, const vector & v)
	{
		if (v.mode==vector::RECT)
		{
			os<<"RECT Mode ->  x= "<<v.x<<", y= "<<v.y<<endl;
		}
		else
		{
			os<<"POL Mode ->  mag= "<<v.mag<<", ang= "<<v.ang<<endl;
		}
	}
//	std::ofstream operator<<(std::ofstream & os, const vector & v)
//	{
//		if (v.mode==vector::RECT)
//		{
//			os<<"RECT Mode ->  x= "<<v.x<<", y= "<<v.y<<endl;
//		}
//		else
//		{
//			os<<"POL Mode ->  mag= "<<v.mag<<", ang= "<<v.ang<<endl;
//		}
//	}
}
