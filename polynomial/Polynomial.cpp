//============================================================================
// Name        : Polynomial.cpp
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include "Polynomial.h"
using namespace std;

//constructors
Polynomial::Polynomial(){
	degree = 10;
	poly = new double[21];
}

Polynomial::Polynomial(double *poly, int degree){
	this->degree = degree;
	this->poly = new double[(2*degree) + 1];

	for (int i = 0; i < ((2*degree) + 1); i++)
		*(this->poly+i) = *(poly+i);
}

//destructor
Polynomial::~Polynomial(){
	delete poly;
}

//getters
double* Polynomial::getPoly()const{
	return poly;
}
double Polynomial::getDegree()const{
	return degree;
}

Polynomial Polynomial::operator+(const Polynomial &obj){
	Polynomial result;

	//CASE 1: calling obj and passed obj are polynomials of same degree
	if (degree == obj.degree)
	{	//assign all values of calling object to result
		result.degree = degree;
		for (int s = 0; s < ((2*degree) + 1); s++)
		{	
			//if calling object has missing term but passed obj
			//doesn't, assign values of that term to result
			if(this->poly[s] == 0 && obj.poly[s] != 0)
				result.poly[s] = obj.poly[s];
			else
				*(result.poly+s) = *(poly+s);
		}
		//end assign
			
		for(int i = 0; i < ((2*degree) + 1); i++)
		{
			//add values in calling & passed object and store in result
			result.poly[i] = this->poly[i] + obj.poly[i];
			i++;	//skip the exponent element	
		}
	}
	
	//CASE 2: calling obj is a polynomial of smaller degree than passed obj
	//eg: (2x^2 + 3) + (4x^3 + 2x + 1)
	else if (degree < obj.degree)
	{	
		//assign values of larger polynomial to result
		result.degree = obj.degree;
		for(int s = 0; s < (2*obj.degree) + 1; s++)
			result.poly[s] = obj.poly[s];
		//end assign
		
		int j = 0;	//variable for accessing values in smaller (calling) polynomial
				//that correspond to values in larger (passed) polynomial

		/* EXAMPLE: this-> poly = {5,1,3}
		       obj.poly = {2,3,4,2,3,1,2}
		       => first 4 values of obj will remain unchanged
		 
		      OR this->poly = {2,2,4,1,9}
	  	       obj.poly = {1,3,4,2,1,1,0}
	  	       => first 2 values of obj will remain unchanged
	  	       
	  	    => the number of values that remain unchanged = (difference in degrees)*2
		*/
		
		//start from where values begin to change
		for(int i = ((obj.degree - degree) * 2); i < ((2*obj.degree) + 1); i++)
		{	
			//add values to result
			result.poly[i] += this->poly[j];
			
			//if a term is missing from larger polynomial but
			//is present in smaller polynomial, copy its values to result
			if(obj.poly[i] == 0 && this->poly[j] != 0)
			{	result.poly[i] = poly[j];
				result.poly[i+1] = poly[j+1];
			}

			i++; j+=2;	//skip the exponent element
					//of both calling and passed objects
		}
	}
	
	//CASE 3: calling obj is a polynomial of larger degree than passed obj
	//eg: (2x^3 + 4x^2 + 5x + 3) + (x^2 + 2x + 1)
	else if (degree > obj.degree)
	{	//same logic as above, but with the new larger polynomial
		
		//assign values of larger obj to result
		result.degree = degree;
		for(int s = 0; s < (2*degree) + 1; s++)
			result.poly[s] = poly[s];
		//end assign
		
		int j = 0;	//variable for accessing values in smaller (passed) polynomial
				//that correspond to values in larger (calling) polynomial
			
		//start from where values begin to change
		for(int i = ((degree - obj.degree) * 2); i < ((2*degree) + 1); i++)
		{	//add values
			result.poly[i] += obj.poly[j];
			
			//if a term is missing from larger polynomial but
			//is present in smaller polynomial, copy its values to result
			if(poly[i] == 0 && obj.poly[j] != 0)
			{	result.poly[i] = obj.poly[j];
				result.poly[i+1] = obj.poly[j+1];
			}
			
			i++; j+=2;	//skip the exponent elements
		}
	}
	
	return result;
}

Polynomial Polynomial::operator-(const Polynomial &obj){
	
	Polynomial result;

	//CASE 1: calling obj and passed obj are polynomials of same degree
	if (degree == obj.degree)
	{	//assign all values of calling object to result
		result.degree = degree;
		
		for (int s = 0; s < ((2*degree) + 1); s++)
		{	
			//if calling obj has a missing term
			//assign the term from passed obj to result
			if(this->poly[s] == 0 && obj.poly[s] != 0)
				result.poly[s] = obj.poly[s];
			else
				*(result.poly+s) = *(poly+s);
		}
		//end assign
		
		for(int i = 0; i < ((2*degree) + 1); i++)
		{
			//subtract corresponding values and store in result
			result.poly[i] = this->poly[i] - obj.poly[i];

			i++;	//skip the exponent element	
		}
	}
	
	//CASE 2: calling obj is a polynomial of smaller degree than passed obj
	//eg: (2x^2 + 3) - (4x^3 + 2x + 1)
	else if (degree < obj.degree)
	{
		//assign degree of larger obj to result
		result.degree = obj.degree;
		
		for(int s = 0; s < ((obj.degree - degree) * 2); s++)
		{	result.poly[s] = -1.0*(obj.poly[s]); 	//initial values are subtracted from 0, so sign changes
			result.poly[s+1] = (obj.poly[s+1]); 	//exponents are same
			s++;					//skip exponent
		}
		//end assign
		
		int j = 0;	//variable for accessing values in smaller (calling) polynomial
				//that correspond to values in larger (passed) polynomial
		
		//assign values of calling object to corresponding values in result
		for (int i = ((obj.degree - degree) * 2); i < ((2*obj.degree) + 1); i++)
		{	result.poly[i] = poly[j];
			j++;	//skip exponent
		}
			
		//reset variable
		j = 0;
		
		for(int i = ((obj.degree - degree) * 2); i < ((2*obj.degree) + 1); i++)
		{	
			//subtract values of passed obj from result (which has values of calling obj)
			result.poly[i] -= obj.poly[i];
			
			//if a term is missing from calling obj but is present in passed obj,
			//assign the exponent value to result (coefficient will already be present)
			if(poly[j] == 0 && obj.poly[i] != 0)
				result.poly[i+1] = obj.poly[i+1];
			
			i++; j+=2;	//skip the exponent elements
		}
	}
	
	//CASE 3: calling obj is a polynomial of larger degree than passed obj
	//eg: (2x^3 + 4x^2 + 5x + 3) - (x^2 + 2x + 1)
	else if (degree > obj.degree)
	{	//assign values of larger polynomial to result
		result.degree = degree;
		
		for(int s = 0; s < ((2*degree) + 1); s++)
			result.poly[s] = poly[s];
		
		//end assign
		
		int j = 0;	//variable to access smaller polynomial (passed obj's) values
		
		for(int i = ((degree - obj.degree) * 2); i < ((2*degree) + 1); i++)
		{	
			//subtract values of passed obj from result (which has values of calling obj)
			result.poly[i] -= obj.poly[j];
			
			//if a term is missing from calling obj but is present in passed obj,
			//assign the exponent value to result (coefficient will already be present)
			if(poly[i] == 0 && obj.poly[j] != 0)
				result.poly[i+1] = obj.poly[j+1];
			
			i++; j+=2;	//skip the exponent element
		}
	}
	
	return result;
}

Polynomial& Polynomial::operator+=(const Polynomial &obj){

	//CASE 1: calling obj and passed obj are polynomials of same degree
	if (degree == obj.degree)
	{	for(int i = 0; i < ((2*degree) + 1); i++)
		{
			//if term is missing in calling object but not in passed,
			//assign the exponent to calling object (coefficient will be added)
			if (this->poly[i] == 0 && obj.poly[i] != 0)
				this->poly[i+1] = obj.poly[i+1];
			
			//update values of calling object with sums of corresponding values
			this->poly[i] += obj.poly[i];
			
			i++;	//skip the exponent element
		}
	}
	
	//CASE 2: calling obj is a polynomial of smaller degree than passed obj
	//eg: (2x^2 + 3) += (4x^3 + 2x + 1)
	else if (degree < obj.degree)
	{	
		//create a temp obj with values of larger polynomial assigned to it
		Polynomial result;
		result.degree = obj.degree;
		for(int s = 0; s < (2*obj.degree) + 1; s++)
			result.poly[s] = obj.poly[s];
		//end assign
		
		int j = 0;	//variable to access values of smaller (calling) polynomial
			
		for(int i = ((obj.degree - degree) * 2); i < ((2*obj.degree) + 1); i++)
		{	
			//add corresponding values of smaller polynomial to result
			result.poly[i] += this->poly[j];
			
			//if term is missing in larger polynomial but not in
			//calling polynomial, put values from calling poly to temp
			if(obj.poly[i] == 0 && this->poly[j] != 0)
			{	result.poly[i] = poly[j];
				result.poly[i+1] = poly[j+1];
			}
			
			i++; j+=2;	//skip the exponent elements
		}
		
		//assign values of temp to calling object
		degree = obj.degree;
		poly = new double[(2*degree) + 1];
		
		for(int n = 0; n < (2*degree) + 1; n++)
			poly[n] = result.poly[n];
		//end assign
	}
	
	//CASE 3: calling obj is a polynomial of larger degree than passed obj
	//eg: (2x^3 + 4x^2 + 5x + 3) += (x^2 + 2x + 1)	
	else if (degree > obj.degree)
	{	int j = 0;	//variable to access values in passed obj
			
		//start from where values of calling object will be subtracted
		for(int i = ((degree - obj.degree) * 2); i < ((2*degree) + 1); i++)
		{	
			//if a term is missing in calling obj but present in
			//passed obj, assign the exponent to calling obj (coefficient will be assigned)s
			if(poly[i] == 0 && obj.poly[j] != 0)
				poly[i+1] = obj.poly[j+1];
				
			//update values of calling object with sums
			poly[i] += obj.poly[j];
			
			i++; j+=2;	//skip the exponent elements
		}
	}
	
	return *this;	//return updated calling object
}

Polynomial& Polynomial::operator-=(const Polynomial &obj){

	//CASE 1: calling obj and passed obj are polynomials of same degree
	if (degree == obj.degree)
	{	for (int s = 0; s < ((2*degree) + 1); s++)
		{	
			//if term is missing in calling object but not in passed,
			//assign the exponent to calling object (coefficient will be added)
			if(this->poly[s] == 0 && obj.poly[s] != 0)
				poly[s+1] = obj.poly[s+1];
			
			//update values of calling object with diffences of corresponding values
			poly[s] -= obj.poly[s];
			s++;	//skip exponents
		}
	}

	//CASE 2: calling obj is a polynomial of smaller degree than passed obj
	//eg: (2x^2 + 3) -= (4x^3 + 2x + 1)
	else if (degree < obj.degree)
	{	//create a temp obj with values of larger polynomial assigned to it
		Polynomial result;
		result.degree = obj.degree;

		for(int s = 0; s < ((obj.degree - degree) * 2); s++)
		{	result.poly[s] = -1.0*(obj.poly[s]); 	//initial values of passed obj subtracted from 0
								//because terms are missing from calling object
			result.poly[s+1] = (obj.poly[s+1]); 	//exponents are same
			s++;					//skip exponent
		}
		//end assign
		
		int j = 0; //access values of calling obj using j
		
		//assign values of calling object to corresponding values in result
		for (int i = ((obj.degree - degree) * 2); i < ((2*obj.degree) + 1); i++)
		{	result.poly[i] = poly[j];
			j++;	//skip exponent
		}
			
		//reset variable
		j = 0;
		
		for(int i = ((obj.degree - degree) * 2); i < ((2*obj.degree) + 1); i++)
		{	
			//if any term is missing in calling obj but not in passed obj,
			//assign the exponent to result (coefficient will be added below)
			if(poly[j] == 0 && obj.poly[i] != 0)
				result.poly[i+1] = obj.poly[i+1];
			
			//subtract values of passed obj from result (which has values of calling obj)	
			result.poly[i] -= obj.poly[i];
			
			i++; j+=2;	//skip the exponent elements
		}
		
		//assign values of result to calling object
		degree = obj.degree;
		poly = new double[(2*degree) + 1];
		
		for(int n = 0; n < (2*degree) + 1; n++)
			poly[n] = result.poly[n];
			
		//end assign
	}
	
	//CASE 3: calling obj is a polynomial of larger degree than passed obj
	//eg: (2x^3 + 4x^2 + 5x + 3) -= (x^2 + 2x + 1)
	else if (degree > obj.degree)
	{	int j = 0;	//variable to access values of smaller (passed) polynomial
		
		//start from where values will begin to change
		for(int i = ((degree - obj.degree) * 2); i < ((2*degree) + 1); i++)
		{	
			//if a term is missing in calling obj but not in passed obj,
			//assign the exponent to calling obj (coefficient will be assigned below)
			if(poly[i] == 0 && obj.poly[j] != 0)
				poly[i+1] = obj.poly[j+1];
				
			//update values of calling obj with difference of corresponding values
			poly[i] -= obj.poly[j];
			
			i++; j+=2;	//skip the exponent elements
		}
	}
	
	return *this;	//return updated calling object
}

Polynomial& Polynomial::operator=(const Polynomial &obj){
	this->degree = obj.degree;

	for(int i = 0; i < ((2*degree) + 1); i++ )
		this->poly[i] = obj.poly[i];

	return *this;
}

bool Polynomial::operator==(const Polynomial &obj){

	//if the polynomials are of different degrees, they are not equal
	if (this->degree != obj.degree)
		return false;
	else //if polynomials have same degree
	{	//check every value of the polynomials.
		//if any one is different, they are not equal
		for(int i = 0; i < ((2*degree) + 1); i++)
		{	if(this->poly[i] != obj.poly[i])
				return false;
		}
	}
	
	//if polynomials are equal
	return true;
}

//non-member friend functions to overload << and >>
ostream& operator<<(ostream &output, const Polynomial &obj) {
	for(int i = 0; i < (2*obj.degree)+1; i++)
	{	if(i == (2*obj.degree))		//if constant of polynomial
			output << obj.poly[i];
		else
		{	if(obj.poly[i] == 0);		//if term is missing, output nothing
			else if(obj.poly[i+1] == 1)	//if exponent is 1
				output << obj.poly[i] << "x + ";
			else					//if exponent is >1
				output << obj.poly[i] << "x^" << obj.poly[i+1] << " + ";
		}
		i++;	//skip element of exponent
	}

	return output;
}

istream& operator>>(istream &input, Polynomial &obj) {
	do{
		cout << "Polynomial degree? (positive only): ";
		input >> obj.degree;
	}
	while(obj.degree < 0);	//input validation

	int j = obj.degree;	//variable to put in exponent automatically

	for(int i = 0; i < (2*obj.degree)+1; i++)
	{	cout << "Element [" << i << "]: ";
		input >> obj.poly[i];

		//if term is missing i.e. coefficient is zero
		if(obj.poly[i] == 0)
			obj.poly[i+1] = 0;	//put 0 as exponent as well
		else
			obj.poly[i+1] = j;

		if(i+1 != (2*obj.degree)+1)
		{	cout << "Element [" << i+1 << "]: " << obj.poly[i+1];
			cout << endl;
		}
		i++; j--;
	}

	return input;
}
