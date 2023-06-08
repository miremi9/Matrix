#ifndef C_MATRIX_H
#define C_MATRIX_H

#include <iostream>

#include "CException.h"
#include "CComplex.h"

#define DIMENSION_ERROR 3


template <class MType> class CMatrix
{
	/*Attributes*/
	private:

		MType ** ppMTypeMATvalue;		//Row List of Colum List of MType Value

		unsigned int uiMATNbColum;		//Number of Colum

		unsigned int uiMATNbRow;		//Number of Row

	/*Constructors & Destructors*/
	public:

		/**********************************************************************************************
		 ***** CMatrix() constructor															  *****
		 **********************************************************************************************
		 ***** Input : nbRow and nbColumn unsigned int											  *****
		 ***** Precondition: None																  *****
		 ***** Output:  None																	  *****
		 ***** Postconditions : construct a CMatrix with nbRow row & nbColumn Column with no value*****
		 **********************************************************************************************/
		CMatrix() : CMatrix<MType>(0, 0) {};

		CMatrix(unsigned int nbRow, unsigned int nbColum);

		template <class T>
		CMatrix(const CMatrix<T> & MATParam);

		/****************************************************************************
		 ***** CMatrix() constructor  of copy                                   *****
		 ****************************************************************************
		 ***** Input : a matrix                                                 *****
		 ***** Precondition: None                                               *****
		 ***** Output:  None                                                    *****
		 ***** Postconditions : replace totaly old matrix with inputed one      *****
		 ****************************************************************************/
		CMatrix(const CMatrix<MType>& MATParam);

		/*********************************************************************************
		 ***** CMatrix() destructor													 *****
		 *********************************************************************************
		 ***** Input : None															 *****
		 ***** Precondition: None													 *****
		 ***** Output:  None														 *****
		 ***** Postconditions : delete every element of the object					 *****
		 *********************************************************************************/
		~CMatrix();

	/*Methods*/
	public:

		unsigned int MATGetNbColum() const { return uiMATNbColum; };

		unsigned int MATGetNbRow() const { return uiMATNbRow; };

		MType MATGetValue(unsigned int uiNumColum, unsigned int uiNumRow) const ;

		/**************************************************************************************************************
		 ***** MATSetValue() CHange value from a slot of matrix													  *****
		 **************************************************************************************************************
		 ***** Input : unsigned int uiNumColum, unsigned int uiNumRow, MType mtValue                              *****
		 ***** Precondition: uiNumColum <= uiMATNbColum && uiNumRow <=uiMATNbRow								  *****
		 ***** Output:  None																					  *****
		 ***** Postconditions : the value of the element of the coordonate (uiNumRow,uiNumColum) is mtValue       *****
		 **************************************************************************************************************/
		void MATSetValue(unsigned int uiNumColum, unsigned int uiNumRow, MType mtValue);

		CMatrix operator-() const;

		CMatrix operator+(const CMatrix & MATParam) const;

		CMatrix operator-(const CMatrix & MATParam) const;

		CMatrix& operator=(const CMatrix & MATParam);

		CMatrix operator*(const CMatrix& MATParam) const;

		CMatrix<MType> operator*(const double & dCoeff) const;

		CMatrix<CComplex> operator*(const CComplex & COMparam) const;

		/************************************************************************
		 ***** operator/() Divide matrix by a value with '/'                *****
		 ************************************************************************
		 ***** Input :  dCoeff a double                                     *****
		 ***** Precondition: different of 0                                 *****
		 ***** Output:  CMatrix                                             *****
		 ***** Postconditions : every element of CMatrix is divide by dCoeff*****
		 ************************************************************************/
		CMatrix<MType> operator/(const double & dCoeff) const;

		CMatrix<CComplex> operator/(const CComplex & COMparam) const;

		template <class T>
		explicit operator CMatrix<T>() const;
		
		template <class T>
		friend CMatrix<double> operator*(const double & dCoeff, const CMatrix<T>& MAT);

		template <class T>
		friend CMatrix<CComplex> operator*(const CComplex & COMparam, const CMatrix & MATparam);

		template <class T>
		friend CMatrix<double> operator/(const double & dCoeff, const CMatrix & MATparam);

		template <class T>
		friend CMatrix<CComplex> operator/(const CComplex & COMparam, const CMatrix & MATparam);

		template<class T>
		friend std::ostream & operator<<(std::ostream & os, const CMatrix<T> & MATparam);
};

#include "CMatrix.ipp"

#endif	//C_MATRIX_H