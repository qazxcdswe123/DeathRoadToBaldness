#include <iostream>
#include <exception>

using namespace std;

class Fraction {
private:
	int numerator;
	int denominator;

public:
	// constructor
	Fraction(int num, int den);
	// copy constructor
	Fraction(const Fraction &rhs) = default; // kinda useless?
	// add two fractions
	Fraction operator+(const Fraction &rhs);
	// subtract two fractions
	Fraction operator-(const Fraction &rhs);
	// multiply two fractions
	Fraction operator*(const Fraction &rhs);
	// divide two fractions
	Fraction operator/(const Fraction &rhs);
	// overload the << operator
	friend ostream& operator<<(ostream &out, const Fraction &rhs);
	// simplify fraction
	void simplify();
	// common denominator
	void commonDenominator(Fraction &f);
	
};
