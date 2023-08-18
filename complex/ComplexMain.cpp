//============================================================================
// Name        : Complex_Main.cpp
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include "Complex.h"
#include "Complex.cpp"
using namespace std;

int main(){
	Complex num1(1,2); //create object using parametrized constructor
	Complex num2;	   //create object using default constructor

	cout << "First Complex Number = ";
	cout << num1 << endl; //overloaded << operator on object

	//overloaded = operator
	num2 = num1;

	cout << "Second Complex Number after assignment using overloaded  = ";
	cout << num2 << endl; //overloaded << operator

	//overloaded == operator
	cout << "Comparing Num1 and Num2 using overloaded ==:" << endl;
	cout << "Num1 == Num2? ";
	if (num1 == num2)
		cout << "Yes, Equal" << endl;
	else
		cout << "No, Not Equal" << endl;

	cout << endl;

	Complex num3;
	cout << "Create a Complex Number using overloaded >> : " << endl;
	cin >> num3;  //overloaded >> operator

	cout << "Your number = " << num3 << endl << endl;

	//overloaded + operator
	Complex obj = num1 + num2;
	cout << "Calling overloaded + operator, Num1 + Num 2 = ";
	cout << '(' << num1 << ") + (" << num2 << ") = ";
	cout << obj.getReal() << " + " << obj.getImg() << 'i' << endl;

	//overloaded - operator
	obj = num3 - num1;
	cout << "Calling overloaded - operator, Your Num - Num 1 = ";
	cout << '(' << num3 << ") - (" << num1 << ") = ";
	cout << obj.getReal() << " + " << obj.getImg() << 'i' << endl;

	//overloaded * operator
	num1.setReal(1); num1.setImaginary(2);
	num2.setReal(3); num2.setImaginary(6);
	obj = num1 * num2;
	cout << "Calling overloaded * operator, Num1 * Num2 = ";
	cout << '(' << num1 << ") * (" << num2 << ") = ";
	cout << obj.getReal() << " + " << obj.getImg() << 'i' << endl;

	//overloaded / operator
	obj = num2/num1;
	cout << "Calling overloaded / operator, Num2 / Num1 = ";
	cout << '(' << num2 << ") / (" << num1 << ") = ";
	cout << obj << endl;

	//overloaded += operator
	cout << "Calling overloaded += operator, Num1 += Num1: ";
	cout << '(' << num1 << ") += (" << num1 << ") = ";
	num1+= num1;
	cout << num1 << endl;

	//overloaded > operator
	cout << "Comparing Num1 and Num2 using overloaded >:" << endl;
	cout << '(' << num1 << ") > (" << num2 << ")? ";
	if (num1 > num2)
		cout << "Yes, Greater" << endl;
	else
		cout << "No, Smaller" << endl;

	//overloaded -= operator
	cout << "Calling overloaded -= operator, Num2 -= Num1: ";
	cout << '(' << num2 << ") -= (" << num1 << ") = ";
	num2-= num1;
	cout << num2 << endl;

	//overloaded < operator
	cout << "Comparing Num1 and Num2 using overloaded <: " << endl;
	cout << '(' << num1 << ") < (" << num2 << ")? ";
	if (num1 < num2)
		cout << "Yes, Smaller" << endl;
	else
		cout << "No, Greater" << endl;

	//overloaded *= operator
	num1.setReal(1); num1.setImaginary(2);
	num2.setReal(3); num2.setImaginary(6);
	cout << "Calling overloaded *= operator, Num1 *= Num2: ";
	cout << '(' << num1 << ") *= (" << num2 << ") = ";
	num1 *= num2;
	cout << num1.getReal() << " + " << num1.getImg() << 'i' << endl;

	//overloaded /= operator
	num1.setReal(1); num1.setImaginary(2);
	cout << "Calling overloaded /= operator, Num2 /= Num1: ";
	cout << '(' << num2 << ") /= (" << num1 << ") = ";
	num2 /= num1;
	cout << num2 << endl;

	//overloaded != operator
	cout << "Comparing Num1 and Num2 using overloaded != " << endl;
	cout << '(' << num1 << ") != (" << num2 << ")? ";
	if (num1 != num2)
		cout << "Yes, Not Equal" << endl;
	else
		cout << "No, Equal" << endl;

	return 0;
}

