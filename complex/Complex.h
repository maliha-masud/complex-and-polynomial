//HEADER GUARDS
#ifndef COMPLEX_H_
#define COMPLEX_H_

using namespace std;

class Complex{
//private data members
	double a;			//real part
	double b;			//imaginary part

public:
	//constructors
	Complex();					//default constructor
	Complex(double real, double imag);	//parametrized constructor

	//destructor
	~Complex();

	//setters
	void setReal(double);
	void setImaginary(double);

	//getters
	double getReal()const;
	double getImg()const;

	//overloaded operators as member functions
	Complex operator+(const Complex &obj);	//part a
	Complex operator-(const Complex &obj);	//part b
	Complex operator*(const Complex &obj);	//part c
	Complex operator/(const Complex &obj);	//part d

	//overloaded assignment operators
	Complex& operator+= (const Complex &obj);
	Complex& operator-= (const Complex &obj);
	Complex& operator*= (const Complex &obj);
	Complex& operator/= (const Complex &obj);

	//assignment operator to assignn one comple num to another
	Complex& operator=(const Complex &obj);

	//Overload stream insertion operators (<<) & (>>) to input & display
	//non-member friend functions:-
	friend ostream &operator<<(ostream &output, const Complex &obj);
	friend istream &operator>>(istream &input, Complex &obj);

	//Overload the comparison operators (==) and (!=) to check equality
	bool operator==(const Complex &obj);
	bool operator!=(const Complex &obj);

	//overload comparison operators > and <
	bool operator>(const Complex &obj);
	bool operator<(const Complex &obj);
};

#endif /*COMPLEX_H_*/
