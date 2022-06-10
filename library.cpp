#include"library.h"

UintN & operator +=(UintN& a, const UintN& b) {
	int number1 = a.Length();
	int number2 = b.Length();
	int rd = 0;
	while (number1 > 0) {
		if (number2 > 0) {
			rd = int(a.arr_number[number1 - 1]) + int(b.arr_number[number2 - 1]) - 2 * int('0') + rd;
			a.arr_number[number1 - 1] = char(rd % 10 + int('0'));
		}
		else {
			rd = int(a.arr_number[number1 - 1])-int('0') + rd;
			a.arr_number[number1 - 1] = char(rd%10 + '0');
		}
		rd = rd / 10;
		number1--;
		number2--;
	}
	while (number2 > 0) {
		rd = int(b.arr_number[number2 - 1] - '0') + rd;
		a.arr_number = char(rd % 10 + '0') + a.arr_number;
		rd /= 10;
		number2--;
	}
	if (rd > 0)a.arr_number = '1' + a.arr_number;
	a.setup();
	return a;
}
UintN operator + (const UintN & a, const UintN & b) {
	UintN T = a;
	T += b;
	return T;
}
UintN& operator -= (UintN& a, const UintN& b) {
	if (a < b) {a.arr_number = '0' ; 
	return a;
	}
	int number1 = a.arr_number.length();
	int number2 = b.arr_number.length();
	int  t = 0;
	int rd = 0;
	while (number1 > 0) {
		if (number2 > 0) {
			rd = int(a.arr_number[number1 - 1] - b.arr_number[number2 - 1]) + t;
			t = 0;
			if (rd < 0) {
				rd += 10;
				t = -1;
			}
		}
		else {
			rd = int(a.arr_number[number1 - 1] - '0') + t;
			t = 0;
			if (rd < 0) {
				rd += 10;
				t = -1;
			}
		}
		a.arr_number[number1 - 1] = char(rd + '0');
		number1--;
		number2--;
	}
	a.setup();
	return a;
}
UintN  operator-(const UintN& a, const UintN& b) {
	UintN T = a;
	T -= b;
	return T;
}
UintN & operator *= ( UintN& a, const UintN& b) {
	int number1 = a.Length();
	int number2 = b.Length();
	int rd = 0;
	UintN T;
	UintN T1;
	T.arr_number = '0';
	for (int i = 0; i < number1; i++) {
		for (int j = 0; j < number2; j++) {
			rd = int(a.arr_number[number1 - i - 1] - '0') * int(b.arr_number[number2 - j - 1] - '0') + rd;
			T1.arr_number = char(rd % 10 + '0') + T1.arr_number;
			rd /= 10;
		}
		if (rd > 0) T1.arr_number = char(rd + '0') + T1.arr_number;
		for (int j = 0; j < i; j++) {
			T1.arr_number = T1.arr_number + '0';
		}
		T += T1;
		T1.arr_number = "";
		rd = 0;
	}
	a = T;
	a.setup();
	return a;
}
UintN operator * (const UintN& a, const UintN& b) {
	UintN T = a;
	T *= b;
	return T;
}
UintN & operator /= (UintN& a, const UintN& b) {
	if (b == 0) {
		cout << "sorry !" << endl;;
		return a;
	}
	if (a < b)return a = 0;
	int number1 = a.Length();
	int number2 = b.Length();
	int head = 1;
	int tail = 10;
	UintN T(0);
	UintN R(0);
	UintN rd=a;
	while (rd>=b) {
		while (T < b) {
			T = T*10 + char(a.arr_number[0] - '0');
			a.arr_number.erase(0, 1);
			R *= 10;
		}
		while (true) {
			if (b * int((head + tail) / 2) > T) { 
				tail = (tail + head) / 2;continue;
			}
			rd = T - b * (int((head + tail) / 2));
			if (rd < b) {
				R += int((head + tail) / 2);
				break;
			}
			else {
				head = (head + tail) / 2;
			}
		}
		T = rd;
		rd = rd*pow(10,a.Length())+a;
		head = 1;
		tail = 10;
	}
	a = R;
	a.setup();
	return a;
}
UintN operator / (const UintN& a, const UintN& b) {
	UintN T = a;
	T /= b;
	return T;
} 
UintN& operator %= (UintN& a, const UintN& b) {
	UintN T = a / b;
	a = a - b * T;
	a.setup();
	return a;
}
UintN operator % (const UintN& a, const UintN& b) {
	UintN T = a;
	T %= b;
	return T;
}

UintN& UintN::operator = (const UintN& a) {
	arr_number = a.arr_number;
	return *this;
}

bool  operator==(const UintN& a, const UintN& b) {
	if (a.arr_number.compare(b.arr_number) == 0) {
		return true;
	}return false;
}
bool operator > (const UintN& a, const UintN& b) {
	if (a.arr_number.length() > b.arr_number.length())return true;
	if (a.arr_number.length() < b.arr_number.length())return false;
	if (a.arr_number.compare(b.arr_number) > 0)return true;
	return false;
}
bool operator < (const UintN& a, const UintN& b) {
	if (a == b || a > b)return false;
	return true;
}

bool operator >= (const UintN& a, const UintN& b) {
	if (a < b)return false;
	return true;
}

bool operator <= (const UintN& a, const UintN& b) {
	if (a > b)return false;
	return true;
}

ostream& operator << (ostream&o, const UintN& a) {
	o << a.arr_number;
	return o;
}
istream& operator >> (istream& i, UintN & a) {
	do {
		i >> a.arr_number;
	} while (!a.test());
	return i;
}
