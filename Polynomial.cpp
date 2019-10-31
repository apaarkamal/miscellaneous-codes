// Author : Apaar
// Built  : 20-10-2019 17:31:38

// Polynomial class
// Polynomial.h
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial
{
public:
	Polynomial();
	Polynomial operator+( const Polynomial& ) const; // addition
	Polynomial operator-( const Polynomial& ) const; // subtraction
	Polynomial operator*( const Polynomial& ); // multiplication
	const Polynomial operator=( const Polynomial& ); // assignment
	Polynomial& operator+=( const Polynomial& );
	Polynomial& operator-=( const Polynomial& );
	Polynomial& operator*=( const Polynomial& );
	void enterTerms();
	void printPolynomial() const;
	int getNumberOfTerms(); // user should only be able to retrieve value
	int getTermExponent( int );
	int getTermCoefficient( int );
	void setCoefficient( int, int ); // set coefficient of a specific term
	~Polynomial(); // destructor
private:
	int numberOfTerms;
	int exponents[ 100 ]; // exponent array
	int coefficients[ 100 ]; // coefficients array
	void polynomialCombine( Polynomial& ); // combine common terms
}; // end class Polynomial

#endif