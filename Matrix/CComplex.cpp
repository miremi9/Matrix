#include "CComplex.h"

CComplex::CComplex()
{
	dCOMreal = 0.0;
	dCOMimaginary = 0.0;
}

// Constructeur avec parties réelle et imaginaire spécifiées
CComplex::CComplex(double dReal, double dImaginary)
{
	dCOMreal = dReal;
	dCOMimaginary = dImaginary;
}

// Constructeur avec partie réelle spécifiée et partie imaginaire par défaut à zéro
CComplex::CComplex(double dreal)
{
	dCOMreal = dreal;
	dCOMimaginary = 0;
}

CComplex::CComplex(const CComplex & COMparam) {
	dCOMreal = COMparam.dCOMreal;
	dCOMimaginary = COMparam.dCOMimaginary;
}

CComplex & CComplex::operator=(const CComplex & COMparam)
{
	if (this != &COMparam) {
		dCOMreal = COMparam.dCOMreal;
		dCOMimaginary = COMparam.dCOMimaginary;
	}
	return *this;
}

CComplex & CComplex::operator+=(const CComplex& COMparam)
{
	dCOMreal += COMparam.dCOMreal;
	dCOMimaginary += COMparam.dCOMimaginary;
	return *this;
}

CComplex & CComplex::operator-=(const CComplex& COMparam)
{
	dCOMreal -= COMparam.dCOMreal;
	dCOMimaginary -= COMparam.dCOMimaginary;
	return *this;
}

CComplex & CComplex::operator*=(const CComplex& COMparam)
{
	dCOMreal = (*this * COMparam).COMgetReal();
	dCOMimaginary = (*this * COMparam).COMgetImaginary();
	return *this;
}

CComplex & CComplex::operator/=(const CComplex& COMparam)
{
	dCOMreal = (*this / COMparam).COMgetReal();
	dCOMimaginary = (*this / COMparam).COMgetImaginary();
	return *this;
}

// Opérateur d'addition
CComplex CComplex::operator+(const CComplex & COMparam) const
{
	double realSum = dCOMreal + COMparam.dCOMreal;
	double imaginarySum = dCOMimaginary + COMparam.dCOMimaginary;
	return CComplex(realSum, imaginarySum);
}

// Opérateur de soustraction
CComplex CComplex::operator-(const CComplex& COMparam) const
{
	double realDiff = dCOMreal - COMparam.dCOMreal;
	double imaginaryDiff = dCOMimaginary - COMparam.dCOMimaginary;
	return CComplex(realDiff, imaginaryDiff);
}

CComplex CComplex::operator-() const
{
	double realDiff = dCOMreal * (-1);
	double imaginaryDiff = dCOMimaginary * (-1);
	return CComplex(realDiff, imaginaryDiff);
}

// Opérateur de multiplication
CComplex CComplex::operator*(const CComplex& COMparam) const
{
	double realProduct = dCOMreal * COMparam.dCOMreal - dCOMimaginary * COMparam.dCOMimaginary;
	double imaginaryProduct = dCOMreal * COMparam.dCOMimaginary + dCOMimaginary * COMparam.dCOMreal;
	return CComplex(realProduct, imaginaryProduct);
}

// Opérateur de division
CComplex CComplex::operator/(const CComplex& COMparam) const
{
	double denominator = COMparam.dCOMreal * COMparam.dCOMreal + COMparam.dCOMimaginary * COMparam.dCOMimaginary;

	if (denominator != 0)
	{
		double realQuotient = (dCOMreal * COMparam.dCOMreal + dCOMimaginary * COMparam.dCOMimaginary) / denominator;
		double imaginaryQuotient = (dCOMimaginary * COMparam.dCOMreal - dCOMreal * COMparam.dCOMimaginary) / denominator;
		return CComplex(realQuotient, imaginaryQuotient);
	}
	else {
		throw new CException(VALUE_ERROR, "VALUE_ERROR\nDivision by 0");
	}
}

CComplex::operator double() const
{
	return dCOMreal;
}

CComplex operator+(double dValue, const CComplex& COMparam)
{
	double drealSum = dValue + COMparam.dCOMreal;
	double dimaginarySum = COMparam.dCOMimaginary;
	return CComplex(drealSum, dimaginarySum);
}

CComplex operator-(double dValue, const CComplex& COMparam)
{
	double drealSum = dValue - COMparam.dCOMreal;
	double dimaginarySum = -COMparam.dCOMimaginary;
	return CComplex(drealSum, dimaginarySum);
}

CComplex operator*(double dValue, const CComplex& COMparam)
{
	double drealProduct = dValue * COMparam.dCOMreal;
	double dimaginaryProduct =dValue * COMparam.dCOMimaginary;
	return CComplex(drealProduct, dimaginaryProduct);
}

CComplex operator/(double dValue, const CComplex& COMparam)
{
	CComplex COMtemp(dValue);
	double dreal = (COMtemp / COMparam).COMgetReal();
	double dimaginary = (COMtemp / COMparam).COMgetImaginary();
	return CComplex(dreal, dimaginary);
}

std::ostream & operator<<(std::ostream & os, const CComplex & COMparam)
{
	os << COMparam.dCOMreal;
	if (COMparam.dCOMimaginary >= 0)
	{
		os << "+";
	}
	os << COMparam.dCOMimaginary << "i";

	return os;
}