
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<unsigned int> HNum;
const unsigned long long UPBD = 2000000000;
unsigned long long mat[32][20][14][12];//2,3,5,7
int main()
{
	typedef unsigned long long ll;
	ll fac2 = 1;
	ll fac3 = 1;
	ll fac5 = 1;
	ll fac7 = 1;
	for (int i = 0; i < 32; i++)
	{
		fac3 = 1;
		for (int j = 0; j < 20; j++)
		{
			fac5 = 1;
			for (int k = 0; k < 14; k++)
			{
				fac7 = 1;
				for (int r = 0; r < 12; r++)
				{
					ll temp = fac2*fac3*fac5*fac7;
					if (temp <= UPBD)
						HNum.push_back(temp);
					fac7 *= 7;
				}
				
				fac5 *= 5;
			}
			fac3 *= 3;
		}
		fac2 *= 2;
	}

	sort(HNum.begin(), HNum.end());
	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			return 0;
		}
		unsigned int output = HNum[n - 1];
		if (n % 10 == 1 && n%100!=11)
		{
			printf("The %dst humble number is %d.\n", n, output);
		}
		else if (n % 10 == 2 && n%100 != 12)
		{
			printf("The %dnd humble number is %d.\n", n, output);
		}
		else if (n % 10 == 3 && n%100 != 13)
		{
			printf("The %drd humble number is %d.\n", n, output);
		}
		else
		{
			printf("The %dth humble number is %d.\n", n, output);
		}
	}
	return 0;
}