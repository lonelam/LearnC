#include"btree.h"
int main()
{
	int n;
	int temp;
	while (cin >> n)
	{
		binarytree btr;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			btr.insert(temp);
		}
		btr.printout();
	}
}