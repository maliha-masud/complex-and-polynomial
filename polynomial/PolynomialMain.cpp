//============================================================================
// Name        : Polynomial.cpp
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include "Polynomial.h"
#include "Polynomial.cpp"
using namespace std;

int main(){
	double ptr[7] = {4,3,3,2,5,1,1};
	Polynomial poly1(ptr,3);
	Polynomial poly2;

	cout << "First Polynomial = ";
	cout << poly1 << endl; //overloaded <<

	//overloaded = operator
	poly2 = poly1;
	cout << "Second Polynomial, after assignment using = : ";
	cout << poly2 << endl; //overloaded << operator

	//overloaded == operator
	cout << "Comparing polynomials using overloaded ==:" << endl;
	cout << '(' << poly1 << ") == (" << poly2 << ")? ";
	if (poly1 == poly2)
		cout << "Yes, equal" << endl;
	else
		cout << "No, not equal" << endl;

	Polynomial polyUser;
	cout << "Create a polynomial:" << endl;
	cin >> polyUser;  //overloaded >> operator

	cout << "Your Polynomial: ";
	cout << polyUser << endl;

	//overloaded + operator
	Polynomial obj = polyUser + poly1;
	cout << "Calling overloaded + operator, YourPoly + Poly1: ";
	cout << '(' << polyUser << ") + (" << poly1 << ")  = ";
	cout << obj << endl;

	//overloaded - operator
	obj = polyUser - poly1;
	cout << "Calling overloaded - operator, YourPoly - Poly1 = ";
	cout << '(' << polyUser << ") - (" << poly1 << ")  = ";
	cout << obj << endl;

	//overloaded += operator
	cout << "Calling overloaded += operator, Poly1 += Poly1: ";
	cout << '(' << poly1 << ") += (" << poly1 << ")  = ";
	poly1+= poly1;
	cout << poly1 << endl;

	//overloaded -= operator
	cout << "Calling overloaded -= operator, YourPoly -= Poly2: ";
	cout << '(' << polyUser << ") -= (" << poly2 << ")  = ";
	polyUser-= poly2;
	cout << polyUser << endl;

	return 0;
}

