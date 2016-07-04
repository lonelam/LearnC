#include<iostream>
int main()
{
	using namespace std;
	char c;
	while (cin.get(c),c!='#')
	{
		if (c == ' ')
			cout << "%20";
		else if (c == '!')
			cout << "%21";
		else if (c == '$')
			cout << "%24";
		else if (c == '%')
			cout << "%25";
		else if (c == '(')
			cout << "%28";
		else if (c == ')')
			cout << "%29";
		else if (c == '*')
			cout << "%2a";
		else cout << c;
	}
}
