
#include<vector>
#include<iostream>
#include<string>
#include<iterator>
#include<algorithm>
using namespace std;
const int BASE = 10000;
class bigint
{
private:
	vector<int> digits;//every digit represent 4 10 based digit
	int chr2num(char c) { return c - '0'; }
	void update()
	{
		for (int i = 0; i<digits.size(); i++)
		{
			if (digits[i]>9999)
			{
				digits[i + 1] += (digits[i] / 10000);
				digits[i]%=10000;
			}
		}
		return;
	}
public:
	bigint() :digits(1, 0) {}
	bigint(size_t length) :digits(length) {}
	bigint(string & numstring)
	{

		int slen = numstring.size();
		auto numcur = numstring.rbegin();
		for (int i = 0; i<slen / 4; i++)
		{
			int temp = chr2num(*numcur++) + 10 * chr2num(*numcur++)\
				+ 100 * chr2num(*numcur++) + 1000 * chr2num(*numcur++);

			digits.push_back(temp);
		}
		int temp = 0;
		for (int i = 0; i< (numstring.rend() - numcur); i++)
		{

			temp *= 10;
			temp += chr2num(numstring[i]);
		}
		if(temp != 0)
		digits.push_back(temp);
	}
	bigint operator+(const bigint & b)const
	{
		if (digits.size()>b.digits.size())
		{
			return b + *this;
		}
		bigint ans(b.digits.size()+1);
		int i = 0;
		for (; i<digits.size(); i++)
		{
			ans.digits[i] = digits[i] + b.digits[i];
		}
		for (; i<b.digits.size(); i++)
		{
			ans.digits[i] = b.digits[i];
		}
		ans.update();
		if(ans.digits.back()==0)
        {

            ans.digits.pop_back();
        }
		return ans;
	}
	friend ostream& operator<<(ostream &os,const bigint & num);
};
ostream& operator<<(ostream& os,const bigint & num)
{

        bool started = false;
        for_each(num.digits.rbegin(), num.digits.rend(), [&os,&started](int x)
                 {
                     if(started)
                     {

                         os.width(4);
                         os.fill('0');
                         os<<x;
                     }
                     else
                     {
                         started = true;
                         os<<x;
                     } });
	return os;
}
int main()
{
	int n;
	cin >> n;
	string str1, str2;
	for (int i = 1; i<n; i++)
	{
		cin >> str1>>str2;
		cout <<"Case "<<i<<":\n"<< str1 << " + " << str2 << " = " ;
		cout << (bigint(str1)+bigint(str2)) << endl<<endl;

	}
	    cin >> str1>>str2;
		cout <<"Case "<<n<<":\n"<< str1 << " + " << str2 << " = " ;
		cout << (bigint(str1)+bigint(str2))<<endl;
	return 0;
}
