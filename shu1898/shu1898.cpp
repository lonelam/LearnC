#include<iostream>
#include<cstring>
class unit 
{
public:
	char u[4] = { 0 };
	char source[3] = { 0 };
	unit();
	unit(char * p);
	~unit() {}
	void manip(char * p);
	void manip();
	void out(char * p);
};
unit::unit()
{
}
unit::unit(char *p)
{
	for (int i = 0; i < 4; i++)
	{
		if (p[i] >= 'A'&&p[i] <= 'Z')
		{
			u[i] = p[i] - 'A';
		}
		else if (p[i] >= 'a'&&p[i] <= 'z')
		{
			u[i] = p[i] - 'a'+26;
		}
		else if (p[i] >= '0'&& p[i] <= '9')
		{
			u[i] = p[i] - '0'+52;
		}
		else if (p[i] == '+')
		{
			u[i] = 62;
		}
		else if (p[i] == '/')
		{
			u[i] = 63;
		}
		else if (p[i] == '=')
		{
			u[i] = 0;
		}
	}
	manip();
}
void unit::manip()
{
	source[0] = (u[0] << 2) + (u[1] >> 4 );
	source[1] = (u[1] << 4) + (u[2] >> 2);
	source[2] = (u[2] << 6) + u[3];
}
void unit::manip(char *p)
{
	for (int i = 0; i < 4; i++)
	{
		if (p[i] >= 'A'&&p[i] <= 'Z')
		{
			u[i] = p[i] - 'A';
		}
		else if (p[i] >= 'a'&&p[i] <= 'z')
		{
			u[i] = p[i] - 'a' + 26;
		}
		else if (p[i] >= '0'&&p[i] <='9')
		{
			u[i] = p[i] - '0' + 52;
		}
		else if (p[i] == '+')
		{
			u[i] = 62;
		}
		else if (p[i] == '/')
		{
			u[i] = 63;
		}
		else if (p[i] == '=')
		{
			u[i] = 0;
		}
	}
	this ->manip();
}
void unit::out(char *p)
{
	for (int i = 0; i < 3; i++)
	{
		p[i] = source[i];
	}
}
int main()
{
	unit x;
	char in[10000];
	char out[7500];
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%s", in);
			int j = 0;
			int k = 0;
			while (in[j]!='\0')
			{
				x.manip(in + j);
				x.out(out + k);
				j+=4;
				k += 3;
			}
			out[k] = '\0';
			printf("%s\n", out);
		}
	}
}