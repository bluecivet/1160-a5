/*
  this file is the implementation for the class ComplexNumber
*/

#include "ComplexNumber.h"
#include<iostream>
#include<cmath>

using namespace std;

// this are the constructor for CompleNumber

/*
  the constructor will set the real and image 
  r is double set for real
  i is double set for image
*/

ComplexNumber::ComplexNumber(double r, double i)
{
	this->real = r;
	this->image = i;
}

//////////////////////////////////////////////////////


/*
  the constructor set the real and set defialt for image which is 0
  r is double set for real
*/

ComplexNumber::ComplexNumber(double r) : ComplexNumber(r, 0)
{

}

/////////////////////////////////////////////////////////

/*
  the constructor set the default value for ComplexNumber
  both real and image will be 0
*/

ComplexNumber::ComplexNumber() : ComplexNumber(0, 0)
{

}

/////////////////////////////////////////////////////

/*
  the method will set the ComplexNumber for real 
  r is double 
*/

void ComplexNumber::setReal(double r)
{
	this->real = r;
}

////////////////////////////////////////////////

/*
  the function will set for image for ComplexNumber 
  i is double 
*/

void ComplexNumber::setImage(double i)
{
	this->image = i;
}

/////////////////////////////////////////////////

/*
  this is the function is the getting for real
  return a double for real
*/

double ComplexNumber::getReal() const
{
	return this->real;
}

////////////////////////////////////////////////////

/*
  this is the setter for image for ComplexNumber
  return double for image
*/

double ComplexNumber::getImage() const
{
	return this->image;
}

/////////////////////////////////////////////////

/*
  the function overload the operator - which substruct a ComplexNumber
  c is the ComplexNumber 
  return the result for ComplexNumber
*/

ComplexNumber ComplexNumber::operator -(const ComplexNumber& c)
{
	double newReal = this->real - c.real;
	double newImage = this->image - c.image;
	ComplexNumber n(newReal, newImage);
	return n;
}

///////////////////////////////////////////////////////////

/*
  the function overload the operator + which adding two ComplexNumber each other
  c is the ComplexNumber need to add
  return a ComplexNumber 
*/

ComplexNumber ComplexNumber::operator +(const ComplexNumber& c)
{
	double newReal = this->real + c.real;
	double newImage = this->image + c.image;
	ComplexNumber n(newReal, newImage);
	return n;
}

/////////////////////////////////////////////////////

/*
  the function overload the operator * will mutipy the ComplexNumber together
  c is the ComplexNumber 
  return ComplexNumber result
*/

ComplexNumber ComplexNumber::operator *(const ComplexNumber& c)
{
	double newReal = (this->real * c.real) - (this->image * c.image);
	double newImage = (this->real * c.image) + (this->image * c.real);
	ComplexNumber n(newReal, newImage);
	return n;
}

/////////////////////////////////////////////////////////////

/*
  the function will overload the operator / which dividy two ComplexNumber
  c is the ComplexNumber 
  return the result of two dividy
*/

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


/////////////////////////////////////////////////////////

/*
  the function overload the funtion == which compare the the ComplexNumber 
  check if they are same or not 
  c is the ComplexNumber 
  return a bool true for same false for not same
*/


bool ComplexNumber::operator ==(const ComplexNumber& c)
{
	if (this->real == c.real && this->image == c.image)
		return true;
	else
		return false;
}

///////////////////////////////////////////////////

/*
  the function will return a ComplexNumber which is absulute
  c is the ComplexNumber
  return ComplexNUmber for absolute
*/
double abs(ComplexNumber &c)
{
	double answer = sqrt((c.real * c.real) + (c.image * c.image));
	return answer;
}

///////////////////////////////////////////////////////

/*
  the function overload the != whcih compare two ComplexNumber same or not
  c is the ComplexNumber that need to compare
  return true for not same otherwise false 
*/

bool ComplexNumber::operator !=(const ComplexNumber& c)
{
	if (this->real == c.real && this->image == c.image)
		return false;
	else
		return true;
}

/////////////////////////////////////////////////////////////

/*
  the function overload the operator / whcih dividy the ComplexNumber with a number
  conplex is the ComplexNumber 
  c is the number need to dividy
  return the ComplexNumber which is the answer
*/

ComplexNumber operator /(const ComplexNumber& complex, const double c)
{
	if (!c)  // if dividing by 0 send error message and exit 
	{
		cout << "Error dividing by 0. Exiting the program" << endl;
		exit(1);
	}

	double newReal = complex.real / c;
	double newImage = complex.image / c;
	ComplexNumber n(newReal, newImage);
	return n;
}


/////////////////////////////////////////////////////////////
/*
  the function overload the operator << show a ComplexNumber on screen
  os is ostream 
  c is the number need to show
  return the ostream
*/

ostream& operator <<(ostream& os, const ComplexNumber& c)
{
	if (c.image >= 0)
		os << c.real << " + " << c.image << "i";
	else
		os << c.real << " - " << -c.image << "i";

	return os;
}

//////////////////////////////////////////////////////////////
/*
  the function overload the operator >> whcih need to input a ComplexNumber
  is is the istream
  c is the number need to input
  return the istream
*/


istream& operator >>(istream& is, ComplexNumber& c)
{
	cout << "enter for real" << endl;
	is >> c.real;
	cout << "enter for image" << endl;
	is >> c.image;
	return is;
}

//////////////////////////////////////////////////////////////////
/*
  the function overload the operator += whcih adding a ComplexNumber to itself
  c is the number need to add
  return the ComplexNumber which is the answer
*/

ComplexNumber & ComplexNumber::operator +=(const ComplexNumber &c)
{
	this->real += c.real;
	this->image += c.image;
	return *this;
}

/////////////////////////////////////////////////////////////////
/*
  the function overload the operator -= whcih substructing a ComplexNumber to itself
  c is the number need to substruct
  return the ComplexNumber which is the answer
*/

ComplexNumber& ComplexNumber::operator -=(const ComplexNumber& c)
{
	this->real -= c.real;
	this->image -= c.image;
	return *this;
}

/////////////////////////////////////////////////////
/*
  the function overload the operator - whcih make negative to itself
  return the ComplexNumber which is the answer
*/
ComplexNumber& ComplexNumber::operator -()
{
	this->real = -this->real;
	this->image = - this->image;
	return *this;
}

//////////////////////////////////////////////////////
/*
  the function overload the operator + whcih do nothing
  return the ComplexNumber which is the answer
*/

ComplexNumber& ComplexNumber::operator +()
{
	return *this;
}

////////////////////////////////////////////////////
/*
  the function overload the operator ++ whcih adding 1 to itself
  return the ComplexNumber which is the answer
*/

ComplexNumber& ComplexNumber::operator ++()
{
	this->real++;
	return *this;
}

//////////////////////////////////////////////////////
/*
  the function overload the operator -- whcih substructing 1 to itself
  return the ComplexNumber which is the answer
*/

ComplexNumber& ComplexNumber::operator --()
{
	this->real--;
	return *this;
}

////////////////////////////////////////////////////////////////////
/*
  the function overload the operator ++ whcih adding 1 to itself after
  return the ComplexNumber itself
*/

ComplexNumber ComplexNumber::operator ++(int)
{
	ComplexNumber temp = *this;
	this->real++;
	return temp;
}

////////////////////////////////////////////////////////////
/*
  the function overload the operator -- whcih adding 1 to itself
  return the ComplexNumber which is the answer
*/

ComplexNumber ComplexNumber::operator --(int)
{
	ComplexNumber temp = *this;
	this->real--;
	return temp;
}