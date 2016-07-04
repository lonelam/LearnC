#include<iostream>
#include<string>
void printstr(char*,int=0);
struct CandyBar{
	std::string brand;
	double weight;
	int calories;
};
void set_candy(CandyBar &,const char * ="MM",const double=2.85,const int=350);
void show_candy(const CandyBar &);
int main(void)
{
	CandyBar laiscandy;
	char  bran[] = "Oilai";
	double wei=2.333;
	int energy=250;
	set_candy(laiscandy,bran,wei,energy);
	show_candy(laiscandy);
	set_candy(laiscandy);
	show_candy(laiscandy);
}
void set_candy(CandyBar & sugar,const char* bra,const double w,const int c)
{
	sugar.brand = bra;
	sugar.weight = w;
	sugar.calories = c;
}
void show_candy(const CandyBar & sugar)
{
	using namespace std;
	cout<<"Candy  "<<sugar.brand<<endl;
	cout<<"It weighs "<<sugar.weight<<" g"<<endl;
	cout<<"You will intake "<<sugar.calories<<" calories!!"<<endl;
}
