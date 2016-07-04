#include<fstream>
#include<iostream>
#include<cmath>
const int LOO[8] ={4,2,4,2,4,6,2,6};
using namespace std;
bool isprim(int p);
bool isprime(int p,int b);
int powermod(int a,int b,int c);
int main()
{
	ofstream fout;
	fout<<endl;
	fout.open("prime.txt");
	int cnt =0;
	for(int i=0;i<1000000;i++)
	{
		if(isprim(i))
		{
			fout<<i<<",";
			cnt++;
		}
	}
	fout<<endl<<"Total : "<<cnt;
	fout.close();
}
bool isprim(int p)
{
//	int FOO[8]={4,2,4,2,4,6,2,6};
	if (p<2) return false;
	if(p==2||p==3||p==5) return true;
	if(!(p%2&&p%3&&p%5)) {return false;}
	int sole = 7;
	double lim=sqrt(p);
	while(sole<=lim)
	{
		for(int k =0;k<8;k++)
		{
			if(!(p%sole)) return false;
			sole += LOO[k];
		}
	}
	return true;
}
bool isprime(int p,int b)
{
	if(p==b) return true;
	int i=0;
	int pbak=p;
	p--;
	while(!p&1)
	{
		p/=2;
		i++;
	}
	if(powermod(b,p,pbak)==1)
	{
		return true;
	}
	else
	{
		for(int j=0;j<i;j++)
		{
			p=p*2;
			if(powermod(b,p,pbak)==p-1)
			{
				return true;
			}
		}
	}
	return false;
}

int powermod(int a,int b,int n)
{
	int ans=1;
	while(b)
	{
		if(b&1)
		{
			ans *= (a%n);
		}
		b=b/2;
		a = (a*a) %n;
	}
	return ans%n;
	
}
