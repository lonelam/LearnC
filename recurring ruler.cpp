//file:recurring ruler
#include<iostream>
const int LEN=66;
const int DIVS=6
void subdivide(char ar[],int head,int foot,int level);
int main(void)
{
	char ruler[LEN];
	int i;
	for(i=1;i<LEN-2;i++)
	{
		ruler[i]=' ';
	}
	ruler[0]=ruler[LEN-2]='!';
	ruler[LEN-1]='\0';
	for (i=0;i<=DIVS;i++)
	{
		subdivide(ruler,LEN-2,1,i);
		std::cout<<ruler<<std::endl;
	}
	return 0;
}
void subdivide(char ar[],int head,int foot,int level)
{
	int mid;
	if(level==0) return;
	mid=(head+foot)/2;
	ar[mid]='|';
	subdivide(ar,head,mid,level-1);
	subdivide(ar,mid,foot,level-1);
}
