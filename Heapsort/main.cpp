#include<iostream>
#include"heapsort.h"
#include<random>
#include<ctime>
#include<algorithm>
void output(int x)
{
	std::cout << x << " ";
}
int main()
{
	std::srand(time(0));
	int arr[100];
	for (int i = 0; i < 100; i++)
	{
		arr[i] = std::rand();
	}
	std::cout << "original:\n";
	std::for_each(arr, arr + 100, output);
	build_maxheap<int>(arr);
	std::cout << "The maxheap:\n";
	int ll = 0;
	std::cout << arr[0];
	std::cin.get();
}