#include"library.h"
UintN::UintN(const Uint1& a) {
	arr_number = a.get_value();
}
UintN::UintN(const Uint2& a) {
	arr_number = a.get_value();
}

UintN::UintN(const int& number) {
	int a = number;
	arr_number;
	while (a > 0) {
		arr_number = char(a % 10 + '0') + arr_number;
		a /= 10;
	}
	if (arr_number == "")arr_number = "0";
	setup();
}
void UintN::output()const {
	cout << arr_number << endl;
}
bool UintN::test()const {
	int n = arr_number.length();
	for (int i = 0; i < n; i++) {
		if (arr_number[i] < '0' || arr_number[i]>'9')return false;
	}
	return true;
}

void UintN::setup() {
	int N = arr_number.length();
	int j = 0;
	for (int i = 0; arr_number[i] == '0' && i < N - 1;i++) {
		j++;
	}
	arr_number.erase(arr_number.begin(), arr_number.begin() + j);
}

int UintN::Length()const {
	return arr_number.length();
}

void UintN::input() {
	do {
		cout << "+ value : ";
		cin >> arr_number;
	} while (!test());
	setup();
}

bool UintN::prime() const {
	if (*this <= 3) {
		return *this > 1;
	}
	else {
		if (*this % 2 == 0 || *this % 3 == 0)return false;
	}
	UintN i("5");
	while (i * i <= *this) {
		if (*this % i == 0 || *this % (i+2)==0)return false;
		i += 6;
	}
	return true;
}

UintN prime_nearst(const UintN& a, const UintN& b) {
	UintN max = a;
	if (b > max) max = b;
	max += 1;
	if (max % 2 == 0)max += 1;
	while (!max.prime())max += 2;
	return max;
}

Uint1::Uint1(const int& N) {
	int a = N;
	arr_number;
	while (a > 0) {
		arr_number = char(a % 10 + '0') + arr_number;
		a /= 10;
	}
	if (arr_number == "")arr_number = "0";
	setup();
}
void Uint1::setup() {
	int N = arr_number.length();
	int j = 0;
	for (int i = 0; arr_number[i] == '0' && i < N - 1;i++) {
		j++;
	}
	arr_number.erase(arr_number.begin(), arr_number.begin() + j);
	if (arr_number.length() > max)arr_number.erase(max, arr_number.length());
}

Uint2::Uint2(const int& N) {
	int a = N;
	arr_number;
	while (a > 0) {
		arr_number = char(a % 10 + '0') + arr_number;
		a /= 10;
	}
	if (arr_number == "")arr_number = "0";
	setup();
}

void Uint2::setup() {
	int N = arr_number.length();
	int j = 0;
	for (int i = 0; arr_number[i] == '0' && i < N - 1;i++) {
		j++;
	}
	arr_number.erase(arr_number.begin(), arr_number.begin() + j);
	if (arr_number.length() > max)arr_number.erase(max, arr_number.length());
}
