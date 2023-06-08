#include "CComplex.h"

/**************************************************************************
 ***** Default class Constructor | CComplex                           *****
 **************************************************************************
 ***** Input : None                                                   *****
 ***** precondtion : None                                             *****
 ***** Output : None                                                  *****
 ***** Postcondition : Attribut of this are initialized               *****
 **************************************************************************/
CComplex::CComplex()
{
	dCOMreal = 0.0;
	dCOMimaginary = 0.0;
}

/**************************************************************************
 ***** Constructor | CComplex                                         *****
 **************************************************************************
 ***** Input : double real, double imaginary                          *****
 ***** precondtion : None                                             *****
 ***** Output : None                                                  *****
 ***** Postcondition : Attribut of this are initialized according     *****
 ***** tothe parameters                                               *****
 **************************************************************************/
CComplex::CComplex(double dReal, double dImaginary)
{
	dCOMreal = dReal;
	dCOMimaginary = dImaginary;
}

/**************************************************************************
 ***** Constructor | CComplex                                         *****
 **************************************************************************
 ***** Input : double real                                            *****
 ***** precondtion : None                                             *****
 ***** Output : None                                                  *****
 ***** Postcondition : Attribut of this are initialized according     *****
 ***** tothe parameters                                               *****
 **************************************************************************/CComplex::CComplex(double dreal)
{
	dCOMreal = dreal;
	dCOMimaginary = 0;
}

/**************************************************************************
 ***** Constructor of Copy | CComplex                                 *****
 **************************************************************************
 ***** Input : const CComplex & COMparam                              *****
 ***** precondtion : COMparam must be initialized                     *****
 ***** Output : None                                                  *****
 ***** Postcondition : Attribut of this are initialized and it        *****
 ***** attributhave the same value as COMparam                        *****
 **************************************************************************/
CComplex::CComplex(const CComplex & COMparam) {
	dCOMreal = COMparam.dCOMreal;
	dCOMimaginary = COMparam.dCOMimaginary;
}

/**************************************************************************
 ***** operator=                                                      *****
 **************************************************************************
 ***** Input : const CComplex& COMparam                               *****
 ***** precondtion : COMparam is initialized                          *****
 ***** Output : CComplex &                                            *****
 ***** Postcondition : this has the same value as COMparam            *****
 **************************************************************************/
CComplex & CComplex::operator=(const CComplex & COMparam)
{
	if (this != &COMparam) {
		dCOMreal = COMparam.dCOMreal;
		dCOMimaginary = COMparam.dCOMimaginary;
	}
	return *this;
}

/**************************************************************************
 ***** operator+=                                                     *****
 **************************************************************************
 ***** Input : const CComplex& COMparam                               *****
 ***** precondtion : COMparam is initialized                          *****
 ***** Output : CComplex &                                            *****
 ***** Postcondition : this as the value of this + the value of       *****
 ***** COMparam                                                       *****
 **************************************************************************/
CComplex & CComplex::operator+=(const CComplex& COMparam)
{
	dCOMreal += COMparam.dCOMreal;
	dCOMimaginary += COMparam.dCOMimaginary;
	return *this;
}

/**************************************************************************
 ***** operator-=                                                     *****
 **************************************************************************
 ***** Input : const CComplex& COMparam                               *****
 ***** precondtion : COMparam is initialized                          *****
 ***** Output : CComplex &                                            *****
 ***** Postcondition : this as the value of this - the value of       *****
 ***** COMparam                                                       *****
 **************************************************************************/
CComplex & CComplex::operator-=(const CComplex& COMparam)
{
	dCOMreal -= COMparam.dCOMreal;
	dCOMimaginary -= COMparam.dCOMimaginary;
	return *this;
}

/**************************************************************************
 ***** operator*=                                                     *****
 **************************************************************************
 ***** Input : const CComplex& COMparam                               *****
 ***** precondtion : COMparam is initialized                          *****
 ***** Output : CComplex &                                            *****
 ***** Postcondition : this as the value of this * the value of       *****
 ***** COMparam                                                       *****
 **************************************************************************/
CComplex & CComplex::operator*=(const CComplex& COMparam)
{
	dCOMreal = (*this * COMparam).COMgetReal();
	dCOMimaginary = (*this * COMparam).COMgetImaginary();
	return *this;
}

/**************************************************************************
 ***** operator/=                                                     *****
 **************************************************************************
 ***** Input : const CComplex& COMparam                               *****
 ***** precondtion : COMparam is initialized                          *****
 ***** Output : CComplex &                                            *****
 ***** Postcondition : this as the value of this / the value of       *****
 ***** COMparam                                                       *****
 **************************************************************************/
CComplex & CComplex::operator/=(const CComplex& COMparam)
{
	dCOMreal = (*this / COMparam).COMgetReal();
	dCOMimaginary = (*this / COMparam).COMgetImaginary();
	return *this;
}

/**************************************************************************
 ***** operator+                                                      *****
 **************************************************************************
 ***** Input : const CComplex& COMparam                               *****
 ***** precondtion : COMparam is initialized                          *****
 ***** Output : CComplex                                              *****
 ***** Postcondition : return a CComplex thas is the addition of      *****
 ***** this and COMparam                                              *****
 **************************************************************************/
CComplex CComplex::operator+(const CComplex & COMparam) const
{
	double realSum = dCOMreal + COMparam.dCOMreal;
	double imaginarySum = dCOMimaginary + COMparam.dCOMimaginary;
	return CComplex(realSum, imaginarySum);
}

/**************************************************************************
 ***** operator-                                                      *****
 **************************************************************************
 ***** Input : const CComplex& COMparam                               *****
 ***** precondtion : COMparam is initialized                          *****
 ***** Output : CComplex                                              *****
 ***** Postcondition : return a CComplex that a is the result of      *****
 ***** this - COMparam                                                *****
 **************************************************************************/
CComplex CComplex::operator-(const CComplex& COMparam) const
{
	double realDiff = dCOMreal - COMparam.dCOMreal;
	double imaginaryDiff = dCOMimaginary - COMparam.dCOMimaginary;
	return CComplex(realDiff, imaginaryDiff);
}

/**************************************************************************
 ***** operator-                                                      *****
 **************************************************************************
 ***** Input : None							                          *****
 ***** precondtion : COMparam is initialized                          *****
 ***** Output : CComplex                                              *****
 ***** Postcondition : return a CComplex that a is the result of      *****
 ***** this * (-1)		                                              *****
 **************************************************************************/
CComplex CComplex::operator-() const
{
	double realDiff = dCOMreal * (-1);
	double imaginaryDiff = dCOMimaginary * (-1);
	return CComplex(realDiff, imaginaryDiff);
}

/**************************************************************************
 ***** operator*                                                      *****
 **************************************************************************
 ***** Input : const CComplex& COMparam                               *****
 ***** precondtion : COMparam is initialized                          *****
 ***** Output : CComplex                                              *****
 ***** Postcondition : return a CComplex that is the result of this   *****
 ***** * COMparam                                                     *****
 **************************************************************************/
CComplex CComplex::operator*(const CComplex& COMparam) const
{
	double realProduct = dCOMreal * COMparam.dCOMreal - dCOMimaginary * COMparam.dCOMimaginary;
	double imaginaryProduct = dCOMreal * COMparam.dCOMimaginary + dCOMimaginary * COMparam.dCOMreal;
	return CComplex(realProduct, imaginaryProduct);
}

/**************************************************************************
 ***** operator/                                                      *****
 **************************************************************************
 ***** Input : const CComplex& COMparam                               *****
 ***** precondtion : COMparam is initialized                          *****
 ***** Output : CComplex                                              *****
 ***** Postcondition : return a CComplex that is the result of this   *****
 ***** / COMparam                                                     *****
 **************************************************************************/
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
		throw CException(VALUE_ERROR, "VALUE_ERROR\nCComplex::operator/ : Division by 0");
	}
}

/**************************************************************************
 ***** operator double()                                              *****
 **************************************************************************
 ***** Input : None						                              *****
 ***** precondtion : COMparam is initialized                          *****
 ***** Output : double                                                *****
 ***** Postcondition : return real complex part as double			  *****
 **************************************************************************/
CComplex::operator double() const
{
	return dCOMreal;
}

/**************************************************************************
 ***** operator+ double                                               *****
 **************************************************************************
 ***** Input : const CComplex& COMparam                               *****
 ***** precondtion : COMparam is initialized                          *****
 ***** Output : CComplex                                              *****
 ***** Postcondition : return a CComplex thas is the addition of      *****
 ***** this and COMparam                                              *****
 **************************************************************************/
CComplex operator+(double dValue, const CComplex& COMparam)
{
	double drealSum = dValue + COMparam.dCOMreal;
	double dimaginarySum = COMparam.dCOMimaginary;
	return CComplex(drealSum, dimaginarySum);
}

/**************************************************************************
 ***** operator-  double                                              *****
 **************************************************************************
 ***** Input : const CComplex& COMparam                               *****
 ***** precondtion : COMparam is initialized                          *****
 ***** Output : CComplex                                              *****
 ***** Postcondition : return a CComplex that a is the result of      *****
 ***** this - COMparam                                                *****
 **************************************************************************/
CComplex operator-(double dValue, const CComplex& COMparam)
{
	double drealSum = dValue - COMparam.dCOMreal;
	double dimaginarySum = -COMparam.dCOMimaginary;
	return CComplex(drealSum, dimaginarySum);
}

/**************************************************************************
 ***** operator*  double                                              *****
 **************************************************************************
 ***** Input : const CComplex& COMparam                               *****
 ***** precondtion : COMparam is initialized                          *****
 ***** Output : CComplex                                              *****
 ***** Postcondition : return a CComplex that is the result of this   *****
 ***** * COMparam                                                     *****
 **************************************************************************/
CComplex operator*(double dValue, const CComplex& COMparam)
{
	double drealProduct = dValue * COMparam.dCOMreal;
	double dimaginaryProduct =dValue * COMparam.dCOMimaginary;
	return CComplex(drealProduct, dimaginaryProduct);
}

/**************************************************************************
 ***** operator/  double                                              *****
 **************************************************************************
 ***** Input : const CComplex& COMparam                               *****
 ***** precondtion : COMparam is initialized                          *****
 ***** Output : CComplex                                              *****
 ***** Postcondition : return a CComplex that is the result of this   *****
 ***** / COMparam                                                     *****
 **************************************************************************/
CComplex operator/(double dValue, const CComplex& COMparam)
{
	if (COMparam.COMgetReal() == 0 && COMparam.COMgetImaginary() == 0) {
		throw CException(VALUE_ERROR, "VALUE_ERROR\nCComplex::operator/ : Division by 0");
	}

	CComplex COMtemp(dValue);
	double dreal = (COMtemp / COMparam).COMgetReal();
	double dimaginary = (COMtemp / COMparam).COMgetImaginary();
	return CComplex(dreal, dimaginary);
}
/**************************************************************************
 ***** operator<<		                                              *****
 **************************************************************************
 ***** Input : const CComplex& COMparam, ostream                      *****
 ***** precondtion : COMparam is initialized                          *****
 ***** Output : ostream                                               *****
 ***** Postcondition : send in ostream flux CComplex values printable *****
 ***** format	                                                      *****
 **************************************************************************/
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

/**************************************************************************
 ***** operator>>		                                              *****
 **************************************************************************
 ***** Input : const CComplex& COMparam, istream                      *****
 ***** precondtion : COMparam is initialized                          *****
 ***** Output : ostream                                               *****
 ***** Postcondition : create CComplex from inputed value			  *****
 **************************************************************************/
std::istream& operator>>(std::istream& is, CComplex& COMparam) {
	double real, imaginary;
	std::cout << "Enter the real part: ";
    is >> real;
    std::cout << "Enter the imaginary part: ";
	is >> imaginary;
	COMparam = CComplex(real, imaginary);
	return is;
}