#include "Fraction.h"
int Fraction::getNumerator()
{
	return numerator;
}

int Fraction::getDenumerator()
{
	return denumerator;
}

void Fraction::setNumerator(int val)
{
	numerator = val;
}

int Fraction::operator+(Fraction fr) const
{
	return numerator/denumerator + fr.numerator/fr.denumerator;
}

int Fraction::operator+(int val) const
{
	return (numerator + val) / (denumerator + val);
}

void Fraction::setDenumerator(int val)
{
	denumerator = val;
}

int Fraction::sum(Fraction obj)
{
	return numerator / denumerator + obj.numerator / obj.denumerator;
}
