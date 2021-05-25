#pragma once

class Fraction
{
private:

	int numerator;
	int denumerator;

public:

	Fraction(int num, int denum);

	void showme();

	Fraction operator + (Fraction f);

	Fraction operator - (Fraction f);

	Fraction operator * (Fraction f);

	Fraction operator / (Fraction f);

	friend std::ostream& operator<< (std::ostream& out, Fraction f);
};