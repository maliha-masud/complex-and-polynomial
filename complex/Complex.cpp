//============================================================================
// Name        : Complex.cpp
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include "Complex.h"
using namespace std;

//constructors
Complex::Complex(){
	a = b = 0;
}
Complex::Complex(double real, double imag){
	this->a = real;
	this->b = imag;
}

//destructor
Complex::~Complex(){
}

//setters
void Complex::setReal(double R){
	a = R;
}
void Complex::setImaginary(double I){
	b = I;
}

//getters
double Complex::getReal()const{
	return a;
}
double Complex::getImg()const{
	return b;
}

Complex Complex::operator+(const Complex &obj){
	Complex temp;

	temp.a = this->a + obj.a;
	temp.b = this->b + obj.b;

	return temp;
}

Complex Complex::operator-(const Complex &obj){
	Complex temp;

	temp.a = this->a - obj.a;
	temp.b = this->b - obj.b;

	return temp;
}

Complex Complex::operator*(const Complex &obj){
	/*	(real1 + imag1) * (real2 + imag2) ==
		real = real1*real2 + -1(imag1 * imag2);
		imag = real1*imag2 + (imag1*real2);*/

	Complex temp;

	temp.a = (this->a*obj.a) - (this->b*obj.b);
	temp.b = (this->a*obj.b) + (this->b*obj.a);

	return temp;
}

Complex Complex::operator/(const Complex &obj){
	/*	(real1 + imag1) / (real2 + imag2) ==
		real = real1*real2 + (imag1 * imag2) / (real2^2 + imag2^2);
		imag = imag1*real2 - (real1*imag2)   / (real2^2 + imag2^2);*/

	Complex temp;

	temp.a = ((a*obj.a) + (b*obj.b)) / ((obj.a*obj.a) + (obj.b*obj.b));
	temp.b = ((b*obj.a) - (a*obj.b)) / ((obj.a*obj.a) + (obj.b*obj.b));

	return temp;
}

Complex& Complex::operator+=(const Complex &obj){
	this->a += obj.a;
	this->b += obj.b;

	return *this;
}

Complex& Complex::operator-=(const Complex &obj){
	this->a -= obj.a;
	this->b -= obj.b;

	return *this;
}

Complex& Complex::operator*=(const Complex &obj){
	int temp = (this->a*obj.a) - (this->b*obj.b);	//assign to temp rather than a because we need a later
	this->b = (this->a*obj.b) + (this->b*obj.a);

	this->a = temp;									//assign temp to a

	return *this;
}

Complex& Complex::operator/=(const Complex &obj){
	int temp = ((a*obj.a) + (b*obj.b)) / ((obj.a*obj.a) + (obj.b*obj.b));
	this->b = ((b*obj.a) - (a*obj.b)) / ((obj.a*obj.a) + (obj.b*obj.b));

	this->a = temp;

	return *this;
}

Complex& Complex::operator=(const Complex &obj){
	//member-wise assignment
	this->a = obj.a;
	this->b = obj.b;

	return *this;
}

bool Complex::operator==(const Complex &obj){
	if ((this->a == obj.a) && (this->b == obj.b))
		return true;
	//else
	return false;
}

bool Complex::operator!=(const Complex &obj){
	//if not equal, return true
	if ((this->a != obj.a) || (this->b != obj.b))
		return true;
	//else
	return false;
}

bool Complex::operator>(const Complex &obj){
	//if real part is greater, return true
	if (this->a > obj.a)
		return true;
	else if (this->a == obj.a)
	{	//if real parts are equal, compare imaginary parts
		if (this->b > obj.b)
			return true;
		else if (this->b < obj.b)
			return false;

		//else if number is equal
		return false;
	}
	//else, if real part of first number is smaller
	//than second number's real
	return false;
}

bool Complex::operator<(const Complex &obj){
	//if real part is smaller, return true
	if (this->a < obj.a)
		return true;
	else if (this->a == obj.a)
	{	//if real parts are equal, compare imaginary parts
		if (this->b < obj.b)
			return true;
		else if (this->b > obj.b)
			return false;

		//if number is equal
		return false;
	}
	//else, if real part of first number is greater
	//than second number's real part
	return false;
}

ostream &operator<<(ostream &output, const Complex &obj) {
	//output in format:- real + (img)i
	output  << obj.a;
	if(obj.b < 0)
	output << " " << obj.b << 'i';
	else
	output	<< " + " << obj.b << 'i';
	return output;
}

istream &operator>>(istream &input, Complex &obj) {
	//prompt and store real and imaginary parts
	cout << "Real = ";
	input >> obj.a;
	cout << "Imaginary = ";
	input >> obj.b;
	return input;
}
