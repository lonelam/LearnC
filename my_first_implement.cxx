//FILE:my_first_implement.cxx
#include "my_first_header.h"
namespace main_lai_2a
{
	point::point(double initial_x,double initial_y)
	{
		x=initial_x;
		y=initial_y;
	}
	void point::rotate90()
	{
		double x1=y;
		double y1=-x;
		x=x1;
		y=y1;
	}
	void point::shift(double delta_x,double delta_y)
	{
		x=x+delta_x;
		y=y+delta_y;
	}
}
