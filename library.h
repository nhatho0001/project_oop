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
protected:
	int memory;
	
public:
	UintN(){};
	UintN(const string d) : arr_number(d) {};
	UintN(const int& number);
	UintN(const Uint1& a);
	UintN(const Uint2& a);
	~UintN(){}
	virtual void enter_memory();
	virtual void setup();
	string get_value() const { return arr_number; }
	void input();
	void output()const;
	int Length() const;
	bool prime()const;
	bool test() const;
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
public:
	Uint1() { enter_memory(); };
	Uint1(const string d) :arr_number(d) { enter_memory();setup(); };
	Uint1(const int&n);
	void enter_memory() { memory = 1; }
	void setup();
};

class Uint2 :public UintN {
private:
	string arr_number;
public:
	Uint2() {};
	Uint2(const string d) :arr_number(d) { enter_memory(); setup(); };
	Uint2(const int& n);
	void enter_memory() { memory = 2; };
	void setup();
};
UintN prime_nearst(const UintN& a, const UintN& b);

#endif // !library.h
