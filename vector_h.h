//vect.h
#ifndef VECTOR_H_
#define VECTOR_H_
#include<iostream>
#include<fstream>
namespace VECT
{
	int fwalk();
	class vector
	{
		public:
			enum Mode{RECT,POL
			};//RECT for rectangular,POL for polar modes!
		private:
			double x;
			double y;
			double mag;
			double ang;
			Mode mode;
			void set_mag();
			void set_ang();
			void set_x();
			void set_y();
		public:
			vector();
			vector(double n1,double n2,Mode form=RECT);
			void reset(double n1,double n2,Mode form =RECT);
			~vector();
			double xval() const {return x;}
			double yval() const {return y;}
			double magval() const {return mag;}
			double angval() const {return ang;}
			void polar_mode();
			void rect_mode();
			vector operator+(const vector & v2) const;
			vector operator-(const vector & v2) const;
			vector operator-()const;
			double operator*(const vector & v2) const;
			vector operator*(double n) const;
			
			friend vector operator*(double n,const vector & v2);
			friend std::ostream & operator<<(std::ostream & os,const vector & v);
			
	};
}
#endif
