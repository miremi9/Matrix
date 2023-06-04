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

CComplex & CComplex::operator=(const CComplex& other) {
	if (this != &other) {
		dCOMreal = other.dCOMreal;
		dCOMimaginary = other.dCOMimaginary;
	}
	return *this;
}

CComplex& CComplex::operator+=(const CComplex& other) {
	dCOMreal += other.dCOMreal;
	dCOMimaginary += other.dCOMimaginary;
	return *this;
}
// Opérateur d'addition
CComplex CComplex::operator+(const CComplex& COMparam) const
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
	if (denominator != 0) {
		double realQuotient = (dCOMreal * COMparam.dCOMreal + dCOMimaginary * COMparam.dCOMimaginary) / denominator;
		double imaginaryQuotient = (dCOMimaginary * COMparam.dCOMreal - dCOMreal * COMparam.dCOMimaginary) / denominator;
		return CComplex(realQuotient, imaginaryQuotient);
	}
	else {
		throw new CException(VALUE_ERROR, "Division by 0");
	}
}

void CComplex::print() const
{
	std::cout << dCOMreal;
	if (dCOMimaginary >= 0)
		std::cout << " + " << dCOMimaginary << "i";
	else
		std::cout << " - " << -dCOMimaginary << "i";
	std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& os, const CComplex& complex)
{
	if (complex.dCOMimaginary < 0)
	{
		os << complex.dCOMreal<< "-" << complex.dCOMimaginary << "i";
	}
	else
	{
		os << complex.dCOMreal << "+" << complex.dCOMimaginary << "i";
	}
	
	return os;
}

CComplex operator*(double value1, CComplex value2) {
	double real = value1 * value2.getReal();
	double imaginary = value1 * value2.getImaginary();
	return CComplex(real, imaginary);
}
CComplex operator*( CComplex value2, double value1) {
	double real = value1 * value2.getReal();
	double imaginary = value1 * value2.getImaginary();
	return CComplex(real, imaginary);
}

CComplex operator/(double value1, CComplex value2) {
	double denominator = value2.dCOMreal * value2.dCOMreal + value2.dCOMimaginary * value2.dCOMimaginary;
	double realPart = (value1 * value2.dCOMreal) / denominator;
	double imaginaryPart = (-value1 * value2.dCOMimaginary) / denominator;
	return CComplex(realPart, imaginaryPart);
}

// Surcharge de l'opérateur de division / (CComplex, double)
CComplex operator/(CComplex value2, double value1) {
	double realPart = value2.dCOMreal / value1;
	double imaginaryPart = value2.dCOMimaginary / value1;
	return CComplex(realPart, imaginaryPart);
}

CComplex operator-(double value1, CComplex value2) {
	return CComplex(value1 - value2.dCOMreal, -value2.dCOMimaginary);
}


CComplex operator-(CComplex value2, double value1) {
	return CComplex(value2.dCOMreal - value1, value2.dCOMimaginary);
}