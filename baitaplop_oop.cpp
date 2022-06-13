#include"library.h"
using namespace std;
int main() {
	UintN*a[2];
	int tp;
	for (int i = 0; i < 2; i++) {
		cout << "=========enter type data=======" << endl;
		cout << "1 : Uint1"<<endl;
		cout << "2 : Uint2"<<endl;
		cout << "3 : UintN"<<endl;
		cout << "enter : ";
		cin >> tp;
		switch (tp)
		{
		case 1: {
			a[i] = new Uint1();
			cout << "enter value : ";
			cin >> *a[i];
			break;
		}
		case 2: {
			a[i] = new Uint2();
			cout << "enter value : ";
			cin >> *a[i];
			break;
		}
		default: {
			a[i] = new UintN();
			cout << "enter value : ";
			cin >> *a[i];
			break;}
		}
	}
	cout << "number1 + number2 = " << *a[0] + *a[1] << endl;
	cout << "number1 - number2 = " << *a[0] - *a[1] << endl;
	cout << "number1 * number2 = " << *a[0] * (*a[1]) << endl;
	cout << "number1 / number2 = " << *a[0] / *a[1] << endl;
	cout << "number1 % number2 = " << *a[0] % *a[1] << endl;
	if (a[0]->prime())cout << "number1 is prime" << endl;
	else cout << "number1 is not prime" << endl;
	if (a[1]->prime())cout << "number2 is prime" << endl;
	else cout << "number2 is not prime" << endl;
	//cout << "Value prime > number1 and number2 : " << prime_nearst(*a[0], *a[1]) << endl;
	delete a[0];
	delete a[1];
	return 0;
 }