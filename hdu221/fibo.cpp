#include<stdio.h>
int fibo(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return fibo(n - 1) + fibo(n - 2);
	}
}
int main_()
{
	for (int i = 27; i < 40; i++)
	{
		printf("%d,", fibo(i));
	}
	getchar();
	return 0;
}