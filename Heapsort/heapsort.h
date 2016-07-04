#pragma once
#include<algorithm>
template <typename T>
void maxheapify(T a[], int ances)//exchange with the bigger child.
{
	ances--;
	if ((ances * 2 ) >= 100)
	{
		return;
	}
	if ((ances * 2 + 1) >= 100)
	{
		if (a[ances] < a[ances * 2])
		{
			std::swap(a[ances],a[ ances * 2 + 1]);
		}
		return;
	}
	if (a[ances] < a[ances * 2])
	{
		if (a[ances * 2 + 1]>a[ances*2])
		{
			std::swap(a[ances], a[ances * 2 + 1]);
			maxheapify(a, ances * 2 + 2);
		}
		else
		{
			std::swap(a[ ances],a[ ances * 2]);
			maxheapify(a, ances * 2+1);
		}
	
	}
	else
	{
		if (a[ances] < a[ances * 2 + 1])
		{
			std::swap(a[ ances],a[ ances * 2 + 1]);
			maxheapify(a, ances * 2 + 2);
		}
	}
}
template<typename T>
void build_maxheap(T a[])
{
	int n = sizeof(a);
	for (int i = n / 2; i>=0; i--)
	{
		maxheapify(a, i+1);
	}
	
}