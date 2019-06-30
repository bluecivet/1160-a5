#include<iostream>

#ifndef COMPLEX_H
#define COMPLEX_H

class ComplexNumber
{
private:
	double real;
	double image;

public:
	ComplexNumber(double r, double i);
	ComplexNumber(double r);
	ComplexNumber();

	void setReal(double r);
	void setImage(double i);

	double getReal() const;
	double getImage() const;

	ComplexNumber operator -(const ComplexNumber& c);
	ComplexNumber operator +(const ComplexNumber& c);
	ComplexNumber operator *(const ComplexNumber& c);
	ComplexNumber & operator +=(const ComplexNumber& c);
	ComplexNumber & operator -=(const ComplexNumber& c);
	ComplexNumber & operator -();
	ComplexNumber & operator +();
	ComplexNumber & operator ++();
	ComplexNumber & operator --();
	ComplexNumber operator ++(int);
	ComplexNumber operator --(int);
	
	bool operator ==(const ComplexNumber& c);
	bool operator !=(const ComplexNumber& c);

	friend ComplexNumber abs(ComplexNumber& c);
	friend ComplexNumber operator /(const ComplexNumber& c, const ComplexNumber& o);
	friend ComplexNumber operator /(const ComplexNumber& complex, const double c);
	friend std::ostream& operator <<(std::ostream& os, const ComplexNumber& c);
	friend std::istream& operator >> (std::istream& is, ComplexNumber& c);


};

const ComplexNumber i(0, 1);

#endif
