// - bignum.h
#pragma once
#include<iostream>
#include<string>
#include<algorithm>

class Bignum
{
private:
	static const int UNIT_NUM = 500;
	static const int DLEN = 4;
	int unit[UNIT_NUM];
	int len;
protected:
	Bignum & operator =(const int);
	Bignum & operator = (const char*);
	Bignum & operator = (const std::string &);
public:
	Bignum() { len = 1; memset(unit, 0, sizeof(unit)); }
	Bignum(const int);
	Bignum(const char *);
	Bignum(const std::string &);
	Bignum(const Bignum &);
	Bignum & operator=(Bignum &);
	
	friend std::istream & operator>>(std::istream&, Bignum &);
	friend std::ostream & operator<<(std::ostream &, const Bignum &);
	
	Bignum operator+(const Bignum &) const;
	Bignum operator-(const Bignum &) const;
	Bignum operator*(const Bignum &) const;
	Bignum operator/(const int ) const;

	Bignum operator^(const int) const;
	int operator%(const int) const;
	
	bool operator>(const Bignum &) const;
	bool operator<(const Bignum &) const;
	bool operator<(const int) const;
	bool operator>(const int) const;

	void output();
	void output(Bignum &);
};

