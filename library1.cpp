#include"library.h"
UintN::UintN(const Uint1& a) {
	arr_number = a.get_value();
	memory = a.get_memory();
}
UintN::UintN(const Uint2& a) {
	arr_number = a.get_value();
	memory = a.get_memory();
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

void UintN::enter_memory(){
	cout << "enter memory area : ";
	cin >> memory;
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
void UintN::setup_value() {
	UintN T("1");
	for (int i = 0; i < get_memory() * 4;i++) {
		T *= 256;
	}
	if (*this > T)arr_number.erase(T.Length(), Length());
	if (*this > T)arr_number.erase(Length() - 1, Length());
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
	if (Miller(*this, 5))return true;
	return false;
}

UintN prime_nearst(const UintN& a, const UintN& b) {
	UintN max = a;
	if (b > max) max = b;
	max += 1;
	if (max % 2 == 0)max += 1;
	while (!max.prime())max += 2;
	return max;
}
Uint1::Uint1(const string d) {
	arr_number = d;
	setup();
	setup_value();
}
Uint1::Uint1(const int& N) {
	enter_memory();
	int a = N;
	arr_number;
	while (a > 0) {
		arr_number = char(a % 10 + '0') + arr_number;
		a /= 10;
	}
	if (arr_number == "")arr_number = "0";
	setup();
	setup_value();
}

Uint2::Uint2(const string d) {
	arr_number = d;
	setup();
	setup_value();
}
Uint2::Uint2(const int& N) {
	enter_memory();
	int a = N;
	arr_number;
	while (a > 0) {
		arr_number = char(a % 10 + '0') + arr_number;
		a /= 10;
	}
	if (arr_number == "")arr_number = "0";
	setup();
	setup_value();
}
UintN mulmod(UintN a,UintN b, UintN mod)
{
	UintN x = 0, y = a % mod;
	while (b > 0)
	{
		if (b % 2 == 1)
		{
			x = (x + y) % mod;
		}
		y = (y * 2) % mod;
		b /= 2;
	}
	return x % mod;
}
/*
 * modular exponentiation
 */
UintN modulo(UintN base,UintN exponent, UintN mod)
{
	UintN x = 1;
	UintN y = base;
	while (exponent > 0)
	{
		if (exponent % 2 == 1)
			x = (x * y) % mod;
		y = (y * y) % mod;
		exponent = exponent / 2;
	}
	return x % mod;
}

/*
 * Miller-Rabin primality test, iteration signifies the accuracy
 */
bool Miller(UintN p, UintN iteration)
{
	if (p < 2)
	{
		return false;
	}
	if (p != 2 && p % 2 == 0)
	{
		return false;
	}
	UintN s = p - 1;
	while (s % 2 == 0)
	{
		s /= 2;
	}
	for (int i = 0; i < iteration; i++)
	{
		UintN a = rand() % (p - 1) + 1, temp = s;
		UintN mod = modulo(a, temp, p);
		while (temp != p - 1 && mod != 1 && mod != p - 1)
		{
			mod = mulmod(mod, mod, p);
			temp *= 2;
		}
		if (mod != p - 1 && temp % 2 == 0)
		{
			return false;
		}
	}
	return true;
}