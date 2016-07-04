#include"NsquaredSort.h"
#include<iostream>
template<typename T>
class cmp
{
public:
	bool prior(T &a, T &b)const
	{
		return a < b;
	}
};
template<typename T>
	void output(const T & x) 
	{
		std::cout << x << ' ';
	}

int main()
{
	cmp<int> Cmp;
	int arr[] = { 9,8,7,6,6,5,4,3,1,2 };
	int * pa = arr;
	int n = sizeof(arr);
	inssort<int, Cmp>(pa, n);
	std::for_each(arr, arr + n, output<int>);
}