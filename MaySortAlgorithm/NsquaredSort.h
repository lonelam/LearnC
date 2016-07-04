#pragma once
#include<algorithm>
template<typename E,typename Comp>
void inssort(E a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j < n&&Comp::prior(a[j], a[j - 1]); j--)
		{
			std::swap(a[j - 1], a[j]);
		}
	}
}

template<typename E,typename Comp>
void bubsort(E a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (Comp::prior(a[j], a[j - 1]))
			{
				std::swap(a[j], a[j - 1]);
			}
		}
	}
}
template<typename E, typename Comp>
void inssort2(E A[], int n, int incr)
{
	for (int i = incr; i < n; i += incr)
	{
		for (int j = i; (j >= incr) && (Comp::prior(a[j], a[j - incr])); j -= incr)
		{
			std::swap(A, j, j - incr);
		}
	}
}