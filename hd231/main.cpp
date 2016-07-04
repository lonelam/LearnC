#include<iostream>
#include<string>
#include<algorithm>
unsigned int unit1[500],unit2[500];
const int MAX_UNIT = 99999999;
const int UNIT_DIGITS = 8;
int readnum (unsigned int * unit, std::string & s);
int main()
{
    int n;
    std::cin>>n;
    std::string s1,s2;
    int len1,len2;
    for(int i = 0; i < n ; i ++ )
    {
        std::cin>>s1>>s2;
        len1=readnum(unit1,s1);
        len2=readnum(unit2,s2);
        int out =0;
        if(len1>=len2)
        {
            for(int j=0;j<len2;j++)
            {
                unit1[j]+=unit2[j];
                if(unit1[j]>MAX_UNIT)
                {
                    unit1[j+1]++;
                    unit1[j]-=MAX_UNIT+1;
                }
            }
            if(unit1[len1]>0)
                len1++;
            out=len1;
            for(int j=len1-1;j>=0;j--)
            {
                std::cout.width(UNIT_DIGITS);
                std::cout.fill('0');
                if(j==0)
                {
                    std::cout.width(0);
                }
                std::cout<<unit1[j];
            }

        }

        else
        {
            for(int j=0;j<len1;j++)
            {
                unit2[j]+=unit1[j];
                if(unit2[j]>MAX_UNIT)
                {
                    unit2[j+1]++;
                    unit2[j]-=MAX_UNIT+1;
                }
            }
            if(unit2[len2]>0)
                len2++;
            for(int j=len2-1;j>=0;j--)
            {
                std::cout.width(UNIT_DIGITS);
                std::cout.fill('0');
                if(j==0)
                {
                    std::cout.width(0);
                }
                std::cout<<unit2[j];
            }
        }
        std::cout<<std::endl;
    }
    return 0;
}

int readnum (unsigned int * unit, std::string & s)
{
    int temp;
    std::string ts;
    int len=0;
    while(s.size()>UNIT_DIGITS)
    {
        temp=0;
        ts.clear();
        std::copy(s.end()-UNIT_DIGITS,s.end(),ts.begin());
        for(int x=0;x<UNIT_DIGITS;x++)
        {
            s.pop_back();
        }
        int ti=1;
        while(ts.size())
        {

            temp+= ti*(ts.back()-'0');
            ts.pop_back();
            ti*=10;

        }
        unit[len]=temp;
        len++;

    }
    int tti=1;
    while(s.size()!=0)
    {
        temp=0;
        temp+= tti * (s.back()-'0');
        tti*=10;
        s.pop_back();
    }
    unit[len] = temp;
    len++;
    return len;

}
