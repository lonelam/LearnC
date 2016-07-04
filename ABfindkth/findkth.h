#ifndef findkth
#define findkth
#include<algorithm>
using namespace std;
class Solution
{
public:
	static int findk(int A[], int an, int B[], int bn, int k)
	{
		if (k == 1)
		{
			return min(A[0], B[0]);
		}
		if (an > bn)
		{
			return findk(B, bn, A, an, k);
		}
		if (k & 1)
		{
			if (A[k / 2 - 1] == B[k / 2])
			{
				return A[k / 2 - 1];
			}
			else if (A[k / 2 - 1] < B[k / 2])
			{
				return findk(A + k / 2, an - k / 2, B, bn, k / 2 + 1);
			}
			else
			{
				return findk(B + k / 2 + 1, bn - k / 2 - 1, A, an, k / 2);
			}
		}
		else
		{
			if (A[k / 2 - 1] == B[k / 2 - 1])
			{
				return A[k / 2 - 1];
			}
			else if (A[k / 2 - 1] < B[k / 2 - 1])
			{
				return findk(A + k / 2, an - k / 2, B, bn, k / 2);
			}
			else
			{
				return findk(B + k / 2, bn - k / 2, A, an, k / 2);
			}
		}
	}
};
#endif // !findkth
