#ifndef C_COMPLEX_H
#define C_COMPLEX_H

#include "CException.h"

#define VALUE_ERROR 3


class CComplex {
	//Atributes
	private:

		//Complex representation (a + ib)
		double dCOMreal;		//real value (a)

		double dCOMimaginary;	//imaginary value (b)

	//Constructors & Destructor
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
		 ***** Constructor of Copy | CComplex                                 *****
		 **************************************************************************
		 ***** Input : const CComplex & COMparam                              *****
		 ***** precondtion : COMparam must be initialized                     *****
		 ***** Output : None                                                  *****
		 ***** Postcondition : Attribut of this are initialized and it        *****
		 ***** attributhave the same value as COMparam                        *****
		 **************************************************************************/
		CComplex(const CComplex & COMparam);

	//Methods
	public :
		/**************************************************************************
		 ***** getReal                                                        *****
		 **************************************************************************
		 ***** Input : None                                                   *****
		 ***** precondtion : None                                             *****
		 ***** Output : double                                                *****
		 ***** Postcondition : return the real part of this                   *****
		 **************************************************************************/
		double COMgetReal() const { return dCOMreal; };

		/**************************************************************************
		 ***** getImaginary                                                   *****
		 **************************************************************************
		 ***** Input : None                                                   *****
		 ***** precondtion : None                                             *****
		 ***** Output : double                                                *****
		 ***** Postcondition : get the imaginary Part of this                 *****
		 **************************************************************************/
		double COMgetImaginary() const { return dCOMimaginary; };

		/**************************************************************************
		 ***** setReal                                                        *****
		 **************************************************************************
		 ***** Input : double real                                            *****
		 ***** precondtion : None                                             *****
		 ***** Output : None                                                  *****
		 ***** Postcondition : change the real part of this                   *****
		 **************************************************************************/
		void COMsetReal(double real) { dCOMreal = real; };

		/**************************************************************************
		 ***** setImaginary                                                   *****
		 **************************************************************************
		 ***** Input : double imaginary                                       *****
		 ***** precondtion : None                                             *****
		 ***** Output : None                                                  *****
		 ***** Postcondition : get the imaginary Part of this                 *****
		 **************************************************************************/
		void COMsetImaginary(double imaginary) { dCOMimaginary = imaginary; };

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
		 ***** operator-=                                                     *****
		 **************************************************************************
		 ***** Input : const CComplex& COMparam                               *****
		 ***** precondtion : COMparam is initialized                          *****
		 ***** Output : CComplex &                                            *****
		 ***** Postcondition : this as the value of this - the value of       *****
		 ***** COMparam                                                       *****
		 **************************************************************************/
		CComplex & operator-=(const CComplex& COMparam);

		/**************************************************************************
		 ***** operator*=                                                     *****
		 **************************************************************************
		 ***** Input : const CComplex& COMparam                               *****
		 ***** precondtion : COMparam is initialized                          *****
		 ***** Output : CComplex &                                            *****
		 ***** Postcondition : this as the value of this * the value of       *****
		 ***** COMparam                                                       *****
		 **************************************************************************/
		CComplex & operator*=(const CComplex& COMparam);

		/**************************************************************************
		 ***** operator/=                                                     *****
		 **************************************************************************
		 ***** Input : const CComplex& COMparam                               *****
		 ***** precondtion : COMparam is initialized                          *****
		 ***** Output : CComplex &                                            *****
		 ***** Postcondition : this as the value of this / the value of       *****
		 ***** COMparam                                                       *****
		 **************************************************************************/
		CComplex & operator/=(const CComplex& COMparam);

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
		 ***** operator-                                                      *****
		 **************************************************************************
		 ***** Input : None							                          *****
		 ***** precondtion : COMparam is initialized                          *****
		 ***** Output : CComplex                                              *****
		 ***** Postcondition : return a CComplex that a is the result of      *****
		 ***** this * (-1)		                                              *****
		 **************************************************************************/
		CComplex operator-() const;

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
		 ***** operator double()                                              *****
		 **************************************************************************
		 ***** Input : None						                              *****
		 ***** precondtion : COMparam is initialized                          *****
		 ***** Output : double                                                *****
		 ***** Postcondition : return real complex part as double			  *****
		 **************************************************************************/
		explicit operator double() const;
 
		/**************************************************************************
		 ***** operator+ double                                               *****
		 **************************************************************************
		 ***** Input : const CComplex& COMparam                               *****
		 ***** precondtion : COMparam is initialized                          *****
		 ***** Output : CComplex                                              *****
		 ***** Postcondition : return a CComplex thas is the addition of      *****
		 ***** this and COMparam                                              *****
		 **************************************************************************/
		friend CComplex operator+(double dValue, const CComplex& COMparam);

		/**************************************************************************
		 ***** operator-  double                                              *****
		 **************************************************************************
		 ***** Input : const CComplex& COMparam                               *****
		 ***** precondtion : COMparam is initialized                          *****
		 ***** Output : CComplex                                              *****
		 ***** Postcondition : return a CComplex that a is the result of      *****
		 ***** this - COMparam                                                *****
		 **************************************************************************/
		friend CComplex operator-(double dValue, const CComplex& COMparam);

		/**************************************************************************
		 ***** operator*  double                                              *****
		 **************************************************************************
		 ***** Input : const CComplex& COMparam                               *****
		 ***** precondtion : COMparam is initialized                          *****
		 ***** Output : CComplex                                              *****
		 ***** Postcondition : return a CComplex that is the result of this   *****
		 ***** * COMparam                                                     *****
		 **************************************************************************/
		friend CComplex operator*(double dValue, const CComplex& COMparam);

		/**************************************************************************
		 ***** operator/  double                                              *****
		 **************************************************************************
		 ***** Input : const CComplex& COMparam                               *****
		 ***** precondtion : COMparam is initialized                          *****
		 ***** Output : CComplex                                              *****
		 ***** Postcondition : return a CComplex that is the result of this   *****
		 ***** / COMparam                                                     *****
		 **************************************************************************/
		friend CComplex operator/(double dValue, const CComplex& COMparam);

		/**************************************************************************
		 ***** operator<<		                                              *****
		 **************************************************************************
		 ***** Input : const CComplex& COMparam, ostream                      *****
		 ***** precondtion : COMparam is initialized                          *****
		 ***** Output : ostream                                               *****
		 ***** Postcondition : send in ostream flux CComplex values printable *****
		 ***** format	                                                      *****
		 **************************************************************************/
		friend std::ostream & operator<<(std::ostream & os, const CComplex & COMparam);
};

#endif	//C_COMPLEX_H
