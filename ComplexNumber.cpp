#include "ComplexNumber.h"
#include<iostream>

using namespace std;

ComplexNumber::ComplexNumber(double r, double i)
{
	this->real = r;
	this->image = i;
}

ComplexNumber::ComplexNumber(double r) : ComplexNumber(r, 0)
{

}

ComplexNumber::ComplexNumber() : ComplexNumber(0, 0)
{

}

void ComplexNumber::setReal(double r)
{
	this->real = r;
}

void ComplexNumber::setImage(double i)
{
	this->image = i;
}

double ComplexNumber::getReal() const
{
	return this->real;
}

double ComplexNumber::getImage() const
{
	return this->image;
}



ComplexNumber ComplexNumber::operator -(const ComplexNumber& c)
{
	double newReal = this->real - c.real;
	double newImage = this->image - c.image;
	ComplexNumber n(newReal, newImage);
	return n;
}


ComplexNumber ComplexNumber::operator +(const ComplexNumber& c)
{
	double newReal = this->real + c.real;
	double newImage = this->image + c.image;
	ComplexNumber n(newReal, newImage);
	return n;
}


ComplexNumber ComplexNumber::operator *(const ComplexNumber& c)
{
	double newReal = (this->real * c.real) - (this->image * c.image);
	double newImage = (this->real * c.image) + (this->image * c.real);
	ComplexNumber n(newReal, newImage);
	return n;
}


ComplexNumber operator /(const ComplexNumber& c, const ComplexNumber &o)
{
	if((!o.real )&& (!o.image))
	{
		cout << "error dividing by 0. Exiting the program" << endl;
		exit(1);
	}

	double bottom = o.real * o.real + o.image * o.image;
	double newReal = ((c.real * o.real) + (c.image * o.image)) / bottom;
	double newImage = ((c.image * o.real) - (c.real * o.image)) / bottom;
	ComplexNumber n(newReal, newImage);
	return n;
}


bool ComplexNumber::operator ==(const ComplexNumber& c)
{
	if (this->real == c.real && this->image == c.image)
		return true;
	else
		return false;
}


ComplexNumber abs(ComplexNumber &c)
{
	double cReal, cImage;

	cReal = c.real < 0 ? -c.real : c.real;
	cImage = c.image < 0 ? -c.image : c.image;
	ComplexNumber answer(cReal, cImage);
	return answer;
}

bool ComplexNumber::operator !=(const ComplexNumber& c)
{
	if (this->real == c.real && this->image == c.image)
		return false;
	else
		return true;
}


ComplexNumber operator /(const ComplexNumber& complex, const double c) throw(int)
{
	if (!c)
	{
		cout << "Error dividing by 0. Exiting the program" << endl;
		exit(1);
	}

	double newReal = complex.real / c;
	double newImage = complex.image / c;
	ComplexNumber n(newReal, newImage);
	return n;
}


ostream& operator <<(ostream& os, const ComplexNumber& c)
{
	if (c.image >= 0)
		os << c.real << " + " << c.image << "i";
	else
		os << c.real << " - " << -c.image << "i";

	return os;
}


istream& operator >>(istream& is, ComplexNumber& c)
{
	cout << "enter for real" << endl;
	is >> c.real;
	cout << "enter for image" << endl;
	is >> c.image;
	return is;
}



ComplexNumber & ComplexNumber::operator +=(const ComplexNumber &c)
{
	this->real += c.real;
	this->image += c.image;
	return *this;
}


ComplexNumber& ComplexNumber::operator -=(const ComplexNumber& c)
{
	this->real -= c.real;
	this->image -= c.image;
	return *this;
}


ComplexNumber& ComplexNumber::operator -()
{
	this->real = -this->real;
	this->image = - this->image;
	return *this;
}


ComplexNumber& ComplexNumber::operator +()
{
	return *this;
}


ComplexNumber& ComplexNumber::operator ++()
{
	this->real++;
	return *this;
}


ComplexNumber& ComplexNumber::operator --()
{
	this->real--;
	return *this;
}


ComplexNumber ComplexNumber::operator ++(int)
{
	ComplexNumber temp = *this;
	this->real++;
	return temp;
}


ComplexNumber ComplexNumber::operator --(int)
{
	ComplexNumber temp = *this;
	this->real--;
	return temp;
}