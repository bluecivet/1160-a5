/*
  this file is the test file for the class ComplexNumber
*/

#include"ComplexNumber.h"
#include<iostream>

using namespace std;

int main()
{
	// two ComplexNumber operation

	ComplexNumber c1(1, -2);
	ComplexNumber c2(3, 4);
	cout << c1 + c2 << endl;
	cout << c1 - c2 << endl;
	cout << c1 * c2 << endl;
	cout << c1 / c2 << endl;
	cout << (c1 == c2) << endl;
	cout << (c1 != c2) << endl;
	cout << c1 / 1.0 << endl;
	cout << c2 / 10.0 << endl;
	cout << 100.0 / c2 << endl;
	
	//two ComplexNumber operation but same content
	cout << endl << "c3 and c4" << endl << endl;

	ComplexNumber c3(5, 6);
	ComplexNumber c4(5, 6);
	cout << c3 + c4 << endl;
	cout << c3 - c4 << endl;
	cout << c3 * c4 << endl;
	cout << c3 / c4 << endl;
	cout << (c3 == c4) << endl;
	cout << (c3 != c4) << endl;
	cout << c3 / 1.0 << endl;
	cout << c4 / 10.0 << endl;

	//cout << c3 / 0 << endl;      // dividing by zero show error

	// try input ComplexNUmber and different constructor
	cout << endl << "c5 and c6" << endl << endl;

	ComplexNumber c5;
	cout << c5 << endl;
	ComplexNumber c6(-9);
	cout << c6 << endl;
	
	//cout << c6 / c5 << endl;
	cin >> c5;
	cout << c5 << endl;

	// self operation
	cout << endl << "c7" << endl << endl;

	ComplexNumber c7(0, 2);
	ComplexNumber test(10, 10);
	cout << (c7 += 12) << endl;
	cout << (c7 -= 12) << endl;
	cout << (c7 += test) << endl;
	cout << (c7 -= test) << endl;
	cout << +c7 << endl;
	cout << -c7 << endl;
	-c7;
	cout << abs(-c7) << endl;
	cout << ++c7 << endl;
	cout << c7++ << endl;
	cout << --c7 << endl;
	cout << c7-- << endl;
	cout << test + ++c7 << endl;
	cout << test + c7++ << endl;
	cout << test + --c7 << endl;
	cout << test + c7-- << endl;


	


	return 0;
}