//HEADER GUARDS
#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

using namespace std;

class Polynomial{
//private data members
	double *poly;
	int degree;

public:
	//constructors
	Polynomial();							//default constructor
	Polynomial(double *poly, int degree);	//parametrized constructor

	//destructor
	~Polynomial();

	//getters
	double *getPoly()const;
	double getDegree()const;

	//overloaded operators as member functions
	Polynomial operator+(const Polynomial &obj);
	Polynomial operator-(const Polynomial &obj);

	Polynomial& operator+= (const Polynomial &obj);
	Polynomial& operator-= (const Polynomial &obj);

	Polynomial& operator=(const Polynomial &obj);
	bool operator==(const Polynomial &obj);

	//Overload stream insertion and extraction operator (<<) & (>>)
	//non-member friend functions
	friend ostream &operator<<(ostream &output, const Polynomial &obj);
	friend istream &operator>>(istream &input, Polynomial &obj);
};

#endif /*POLYNOMIAL_H_*/
