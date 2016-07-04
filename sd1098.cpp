#include<iostream>
using namespace std;
int main(void)
{
  int a,b,c,inp;
  while(cin>>inp)
  {
    a=inp/100;
    b=(inp-a*100)/10;
    c=(inp-a*100-b*10);
    if ((a*a*a+b*b*b+c*c*c)==inp) cout<<1;
      else cout<<0;
  }
}
