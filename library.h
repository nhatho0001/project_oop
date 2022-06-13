#pragma once

#ifndef library.h
#define library
#include<iostream>
#include<string>
using namespace std;
class Uint1;
class Uint2;
class UintN {
private:
	string arr_number;
public:
	UintN(){};
	UintN(const string d) : arr_number(d) {};
	UintN(const int& number);
	UintN(const Uint1& a);
	UintN(const Uint2& a);
	~UintN(){}
	string get_value() const { return arr_number; }
	void input();
	void output()const;
	virtual void setup();
	int Length() const;
	bool prime()const;
	virtual bool test() const;
	UintN& operator = (const UintN& a);
	friend UintN& operator += (UintN& a, const UintN& b);
	friend UintN operator + (const UintN& a , const UintN& b);
	friend UintN& operator -= (UintN & a, const UintN & b);
	friend UintN operator - (const UintN& a , const UintN& b);
	friend UintN& operator *=(UintN& a, const UintN & b);
	friend UintN operator * (const UintN& a , const UintN& b);
	friend UintN& operator /= (UintN& a, const UintN& b);
	friend UintN operator / (const UintN& a , const UintN& b);
	friend UintN& operator %= (UintN& a, const UintN& b);
	friend UintN operator % (const UintN& a , const UintN& b);
	friend bool operator == (const UintN& a, const UintN& b);
	friend bool operator > (const UintN& a, const UintN& b);
	friend bool operator < (const UintN& a , const UintN& b);
	friend bool operator >= (const UintN& a, const UintN& b);
	friend bool operator <= (const UintN& a, const UintN & b);
	friend ostream & operator << (ostream & o ,const UintN & a);
	friend istream& operator >> (istream& i,UintN& a);
};
class Uint1:public UintN {
private :
	string arr_number;
	const int max = 10;
public:
	Uint1() {};
	Uint1(const string d) :arr_number(d) {};
	Uint1(const int&n);
	void setup();

};

class Uint2 :public UintN {
private:
	string arr_number;
	const int max = 15;
public:
	Uint2() {};
	Uint2(const string d) :arr_number(d) {};
	Uint2(const int& n);
	void setup();
};
UintN prime_nearst(const UintN& a, const UintN& b);

#endif // !library.h
