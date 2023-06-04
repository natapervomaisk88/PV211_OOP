#pragma once
class Fraction
{
	int numerator;
	int denumerator;
public:
	int getNumerator();

	int getDenumerator();

	void setNumerator(int val);

	void setDenumerator(int val);
	
	int operator+(Fraction fr) const;

	int operator+(int) const;

	int sum(Fraction obj);

};

