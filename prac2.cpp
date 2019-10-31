// Author : Apaar
// Built  : 20-10-2019 17:36:59

#include <bits/stdc++.h>
using namespace std;

#include "Polynomial.h"

int main()
{
    Polynomial a, b, c, t;

    a.enterTerms();
    b.enterTerms();
    t = a; // save the value of a
    cout << "First polynomial is:\n";
    a.printPolynomial();
    cout << "Second polynomial is:\n";
    b.printPolynomial();
    cout << "\nAdding the polynomials yields:\n";
    c = a + b;
    c.printPolynomial();
    cout << "\n+= the polynomials yields:\n";
    a += b;
    a.printPolynomial();
    cout << "\nSubtracting the polynomials yields:\n";
    a = t; // reset a to original value
    c = a - b;
    c.printPolynomial();
    cout << "\n-= the polynomials yields:\n";
    a -= b;
    a.printPolynomial();
    cout << "\nMultiplying the polynomials yields:\n";
    a = t; // reset a to original value
    c = a * b;
    c.printPolynomial();
    cout << "\n*= the polynomials yields:\n";
    a *= b;
    a.printPolynomial();
    cout << endl;
    return 0;
}