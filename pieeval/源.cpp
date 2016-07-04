#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const double PI = 3.1415926;
int main()`
{
	double l1, l2, theta;
	while (scanf("%lf%lf%lf", &l1, &l2, &theta) != EOF)
	{
		double r1 = l1 / 2, r2 = l2 / 2, rm = sqrt(r1*r1 + r2*r2 + r1*l2*cos(theta*PI/180));
		r1 = (r1 + r2 + rm) / 2;
		printf("%lf\n", PI*r1*r1);
	}
	return 0;
}