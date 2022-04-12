#include "fraction.h"

int main()
{
	try {
		Fraction f1(1, 2);
		Fraction f2(1, 3);
		// Fraction fn(1, 0); 
	}
	catch (const invalid_argument& e) {
		cout << e.what() << endl;
		exit(1);
	}
	// Fraction fn(1, 0); 

	Fraction f1(1, 2);
	Fraction f2(1, 3);

	Fraction f3 = f1 + f2;
	Fraction f4 = f1 - f2;
	Fraction f5 = f1 * f2;
	Fraction f6 = f1 / f2;

	cout << f3 << endl;
	cout << f4 << endl;
	cout << f5 << endl;
	cout << f6 << endl;	

	f1.commonDenominator(f2);
	cout << f1 << endl;
	cout << f2 << endl;

	f1.simplify();
	f2.simplify();
	cout << f1 << endl;
	cout << f2 << endl;
}
