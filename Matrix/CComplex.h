#ifndef CCOMPLEX_H
#define CCOMPLEX_H
#include <iostream>

class CComplex {
private:
	double dCOMreal;
	double dCOMimaginary;  

public:
	/**************************************************************************
	 ***** Default class Constructor | CComplex                           *****
	 **************************************************************************
	 ***** Input : None                                                   *****
	 ***** precondtion : None                                             *****
	 ***** Output : None                                                  *****
	 ***** Postcondition : Attribut of this are initialized               *****
	 **************************************************************************/
	CComplex();

	/**************************************************************************
	 ***** Constructor | CComplex                                         *****
	 **************************************************************************
	 ***** Input : double real, double imaginary                          *****
	 ***** precondtion : None                                             *****
	 ***** Output : None                                                  *****
	 ***** Postcondition : Attribut of this are initialized according     *****
	 ***** tothe parameters                                               *****
	 **************************************************************************/
	CComplex(double real, double imaginary);

	/**************************************************************************
	 ***** Constructor of Copy | CComplex                                 *****
	 **************************************************************************
	 ***** Input : const CComplex & COMparam                              *****
	 ***** precondtion : COMparam must be initialized                     *****
	 ***** Output : None                                                  *****
	 ***** Postcondition : Attribut of this are initialized and it        *****
	 ***** attributhave the same value as COMparam                        *****
	 **************************************************************************/
	CComplex(const CComplex & COMparam);

	/**************************************************************************
	 ***** Constructor | CComplex                                         *****
	 **************************************************************************
	 ***** Input : double real                                            *****
	 ***** precondtion : None                                             *****
	 ***** Output : None                                                  *****
	 ***** Postcondition : Attribut of this are initialized according     *****
	 ***** tothe parameters                                               *****
	 **************************************************************************/
	CComplex(double real);

	/**************************************************************************
	 ***** getReal                                                        *****
	 **************************************************************************
	 ***** Input : None                                                   *****
	 ***** precondtion : None                                             *****
	 ***** Output : double                                                *****
	 ***** Postcondition : return the real part of this                   *****
	 **************************************************************************/
	double getReal() const { return dCOMreal; };

	/**************************************************************************
	 ***** getImaginary                                                   *****
	 **************************************************************************
	 ***** Input : None                                                   *****
	 ***** precondtion : None                                             *****
	 ***** Output : double                                                *****
	 ***** Postcondition : get the imaginary Part of this                 *****
	 **************************************************************************/
	double getImaginary() const { return dCOMimaginary; };

	/**************************************************************************
	 ***** setReal                                                        *****
	 **************************************************************************
	 ***** Input : double real                                            *****
	 ***** precondtion : None                                             *****
	 ***** Output : None                                                  *****
	 ***** Postcondition : change the real part of this                   *****
	 **************************************************************************/
	void setReal(double real) { dCOMreal = real; };

	/**************************************************************************
	 ***** setImaginary                                                   *****
	 **************************************************************************
	 ***** Input : double imaginary                                       *****
	 ***** precondtion : None                                             *****
	 ***** Output : None                                                  *****
	 ***** Postcondition : get the imaginary Part of this                 *****
	 **************************************************************************/
	void setImaginary(double imaginary) { dCOMimaginary = imaginary; };

	/**************************************************************************
	 ***** operator=                                                      *****
	 **************************************************************************
	 ***** Input : const CComplex& COMparam                               *****
	 ***** precondtion : COMparam is initialized                          *****
	 ***** Output : CComplex &                                            *****
	 ***** Postcondition : this has the same value as COMparam            *****
	 **************************************************************************/
	CComplex & operator=(const CComplex& COMparam);

	/**************************************************************************
	 ***** operator+=                                                     *****
	 **************************************************************************
	 ***** Input : const CComplex& COMparam                               *****
	 ***** precondtion : COMparam is initialized                          *****
	 ***** Output : CComplex &                                            *****
	 ***** Postcondition : this as the value of this + the value of       *****
	 ***** COMparam                                                       *****
	 **************************************************************************/
	CComplex & operator+=(const CComplex& COMparam);

	/**************************************************************************
	 ***** operator+                                                      *****
	 **************************************************************************
	 ***** Input : const CComplex& COMparam                               *****
	 ***** precondtion : COMparam is initialized                          *****
	 ***** Output : CComplex                                              *****
	 ***** Postcondition : return a CComplex thas is the addition of      *****
	 ***** this and COMparam                                              *****
	 **************************************************************************/
	CComplex operator+(const CComplex& COMparam) const;

	/**************************************************************************
	 ***** operator-                                                      *****
	 **************************************************************************
	 ***** Input : const CComplex& COMparam                               *****
	 ***** precondtion : COMparam is initialized                          *****
	 ***** Output : CComplex                                              *****
	 ***** Postcondition : return a CComplex that a is the result of      *****
	 ***** this - COMparam                                                *****
	 **************************************************************************/
	CComplex operator-(const CComplex& COMparam) const;

	/**************************************************************************
	 ***** operator*                                                      *****
	 **************************************************************************
	 ***** Input : const CComplex& COMparam                               *****
	 ***** precondtion : COMparam is initialized                          *****
	 ***** Output : CComplex                                              *****
	 ***** Postcondition : return a CComplex that is the result of this   *****
	 ***** * COMparam                                                     *****
	 **************************************************************************/
	CComplex operator*(const CComplex& COMparam) const;

	/**************************************************************************
	 ***** operator/                                                      *****
	 **************************************************************************
	 ***** Input : const CComplex& COMparam                               *****
	 ***** precondtion : COMparam is initialized                          *****
	 ***** Output : CComplex                                              *****
	 ***** Postcondition : return a CComplex that is the result of this   *****
	 ***** / COMparam                                                     *****
	 **************************************************************************/
	CComplex operator/(const CComplex& COMparam) const;

	/**************************************************************************
	 ***** operator*                                                      *****
	 **************************************************************************
	 ***** Input : double dValue, CComplex COMparam                       *****
	 ***** precondtion : COMparam is initialized                          *****
	 ***** Output : CComplex                                              *****
	 ***** Postcondition : return CComplex result of COMparam * dValue    *****
	 **************************************************************************/
	friend CComplex operator*(double dValue, CComplex COMparam);
	friend CComplex operator*(CComplex COMparam, double dValue);

	/**************************************************************************
	 ***** operator-                                                      *****
	 **************************************************************************
	 ***** Input : double dValue, CComplex COMparam                       *****
	 ***** precondtion : COMparam is initialized                          *****
	 ***** Output : CComplex                                              *****
	 ***** Postcondition : return CComplex result of dValue/COMparam      *****
	 **************************************************************************/
	friend CComplex operator-(double dValue, CComplex COMparam);

	/**************************************************************************
	 ***** operator-                                                      *****
	 **************************************************************************
	 ***** Input : double dValue, CComplex COMparam                       *****
	 ***** precondtion : COMparam is initialized                          *****
	 ***** Output : CComplex                                              *****
	 ***** Postcondition : return CComplex result of COMparam/dValue      *****
	 **************************************************************************/
	friend CComplex operator-(CComplex COMparam, double dValue);

	/**************************************************************************
	 ***** operator/                                                      *****
	 **************************************************************************
	 ***** Input : double dValue, CComplex COMparam                       *****
	 ***** precondtion : COMparam is initalized                           *****
	 ***** Output : CComplex                                              *****
	 ***** Postcondition : return CComplex result of dValue/COMparam      *****
	 **************************************************************************/
	friend CComplex operator/(double dValue, CComplex COMparam);

	/**************************************************************************
	 ***** operator/                                                      *****
	 **************************************************************************
	 ***** Input : double dValue, CComplex COMparam                       *****
	 ***** precondtion : COMparam is initalized                           *****
	 ***** Output : CComplex                                              *****
	 ***** Postcondition : return CComplex result of COMparam/dValue      *****
	 **************************************************************************/
	friend CComplex operator/(CComplex COMparam, double dValue);


	friend std::ostream& operator<<(std::ostream& os, const CComplex& complex);

	// Méthode d'affichage
	void print() const;
};

#endif
