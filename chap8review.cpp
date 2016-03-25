//chap7pe2
#include<iostream>
#include<string>
void song(const char * name,int times=1);
void iquote(int);
void iquote(double);
void iquote(std::string);
struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volumn;
};
void show_box(box & );
void set_vol(box &);
float mass(float ,float volumn=1);
template <typename T>
T larger(const T&,const T&);
template <>
box larger<box>(const box&,const box&);

int main()
{
	
}
