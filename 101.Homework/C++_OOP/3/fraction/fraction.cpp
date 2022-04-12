#include "fraction.h"

Fraction::Fraction(int n, int d)
{
	if (d == 0)
	{
		throw invalid_argument("Denominator cannot be zero");
	}
	else
	{
		numerator = n;
		denominator = d;
	}
}

// overload +
Fraction Fraction::operator+(const Fraction& rhs)
{
	int newNumerator = numerator * rhs.denominator + rhs.numerator * denominator;
	int newDenominator = denominator * rhs.denominator;
	return Fraction(newNumerator, newDenominator);
}

// overload -
Fraction Fraction::operator-(const Fraction& rhs)
{
	int newNumerator = numerator * rhs.denominator - rhs.numerator * denominator;
	int newDenominator = denominator * rhs.denominator;
	return Fraction(newNumerator, newDenominator);
}

// overload *
Fraction Fraction::operator*(const Fraction& rhs)
{
	int newNumerator = numerator * rhs.numerator;
	int newDenominator = denominator * rhs.denominator;
	return Fraction(newNumerator, newDenominator);
}

// overload /
Fraction Fraction::operator/(const Fraction& rhs)
{
	int newNumerator = numerator * rhs.denominator;
	int newDenominator = denominator * rhs.numerator;
	return Fraction(newNumerator, newDenominator);
}

// overload <<
ostream& operator<<(ostream& os, const Fraction& f)
{
	os << f.numerator << "/" << f.denominator;
	return os;
}

int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a % b);
	}
}

void Fraction::simplify()
{
	int div = gcd(numerator, denominator);
	numerator /= div;
	denominator /= div;
}

void Fraction::commonDenominator(Fraction &f)
{
	numerator *= f.denominator;
	f.numerator *= denominator;
	int newDenominator = denominator * f.denominator;
	f.denominator = newDenominator;
	denominator = newDenominator;
}
