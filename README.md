# Operator Overloading
### Complex numbers & Polynomials

* Each class has private data members, constructors (default, parametrized, and copy constructor if needed), a destructor, setters, and getters.
* Each class is implemented in separate .h and .cpp files.

#### Complex Numbers
A class named Complex developed to represent complex numbers.
> A complex number has the general form a + bi, where a is the real part and b is the imaginary part (i stands for imaginary).
> Arithmetic operations on complex numbers are as follows:
>* (a + bi) + (c + di) = (a + c) + (b + d) i
>* (a + bi) – (c + di) = (a – c) + (b – d) i
>* (a + bi) * (c + di) = (ac – bd) + (ad + bc) i
>* (a + bi) / (c + di) = [(ac + bd) + (bc – ad) i] / (c2 + d2 )

The class provides the following overloaded operator capabilities:
* Overloaded addition operator (+) to add two Complex numbers.
* Overloaded subtraction operator (–) to subtract two Complex numbers.
* Overloaded multiplication operator (*) to multiply two Complex numbers. 
* Overloaded division operator (/) to divide two Complex numbers.
* Overloaded addition assignment operator (+=), subtraction assignment operator (–=), multiplication assignment operator (*=), and division assignment operator (/=).
* Overloaded assignment operator (=) to assign one Complex number to another.
* Overloaded stream insertion (<<) to get the input Complex numbers and stream extraction operator (>>) to display Complex numbers.
* Overloaded comparison operators (==) and (!=) to check whether two Complex numbers are equal or not.
* Overloaded comparison operators (<) and (>) to check whether one Complex number is less or greater than the other.
All overloaded operators (except ‘<<’ and ‘>>’) are defined as member functions of the Complex class.
The overloaded function for stream insertion (<<) and stream extraction (>>) operator are non-member friend functions.
Written in three files (complex.h, complex.cpp, and complexMain.cpp)

#### Polynomial
A class named Polynomial to represent a polynomial.
> A polynomial is an array of terms. Each term contains a coefficient and an exponent.
>* E.g.: The term 2x^4 has coefficient 2 and the exponent 4.
>* For a third-degree polynomial 4x^3 + 3x + 2 there are two terms and a constant. The first term has coefficient 4 and the exponent 3, the second term has coefficient 3 and the exponent 1, and the third is a constant 2.

The class provides the following overloaded operator capabilities:
* Overloaded addition operator (+) to add two polynomials.
* Overloaded subtraction operator (–) to subtract two polynomials.
> Guide to add and subtract polynomials [here](https://www.cuemath.com/algebra/adding-and-subtracting-polynomials/).
* Overloaded addition operator (+=) to add two polynomials.
* Overloaded subtraction operator (–=) to subtract two polynomials.
* Overloaded assignment operator (=) to assign one polynomial to another
* Overloaded operator (==) to check if two polynomials are equal.
* Overload stream insertion (<<) to get input polynomial and stream extraction operator (>>) to display the polynomial.
All overloaded operators (except ‘<<’ and ‘>>’) are defined as member functions of the Polynomial class.
The overloaded function for stream insertion (<<) and stream extraction (>>) operator are non-member friend functions.
Written in three files (polynomial.h, polynomial.cpp, and polynomialMain.cpp).
