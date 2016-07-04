//FILE:my_first_header.h
#ifndef MAIN_LAI_POINT_H
#define MAIN_LAI_POINT_H

namespace main_lai_2a
{
	class point
	{
		public:
			point(double initial_x=0.0,double initial_y=0.0);
			void shift(double delta_x,double delta_y);
			void rotate90(void);
			double get_x() const {
				return x;
			}
			double get_y()const {return y;}
		private:
			double x;
			double y;
	}
}
