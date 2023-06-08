#ifndef C_MATRIX_H
#define C_MATRIX_H

#include <iostream>

#include "CException.h"
#include "CComplex.h"

#define DIMENSION_ERROR 9


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
		 ***** CMatrix() default constructor													  *****
		 **********************************************************************************************
		 ***** Input : None																		  *****
		 ***** Precondition: None																  *****
		 ***** Output:  None																	  *****
		 ***** Postconditions : construct a CMatrix with 0 row & 0 Column						  *****
		 **********************************************************************************************/
		CMatrix() : CMatrix<MType>(0, 0) {};

		/**********************************************************************************************
		 ***** CMatrix() constructor															  *****
		 **********************************************************************************************
		 ***** Input : nbRow and nbColumn unsigned int											  *****
		 ***** Precondition: None																  *****
		 ***** Output:  None																	  *****
		 ***** Postconditions : construct a CMatrix with nbRow row & nbColumn Column with no value*****
		 **********************************************************************************************/
		CMatrix(unsigned int nbRow, unsigned int nbColum);

		/****************************************************************************
		 ***** CMatrix() constructor  copy	                                    *****
		 ****************************************************************************
		 ***** Input : a matrix  with different type                            *****
		 ***** Precondition: None                                               *****
		 ***** Output:  None                                                    *****
		 ***** Postconditions : replace totaly old matrix with inputed one value*****
		 ****************************************************************************/
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
		/******************************************************************************************
		 ***** MATGetNbColum() Getter of matrix number of colum								  *****
		 ******************************************************************************************
		 ***** Input : None																	  *****
		 ***** Precondition: initialised CMatrix											  *****
		 ***** Output:  unsigned int														  *****
		 ***** Postconditions :  value is the num of colum									  *****
		 ******************************************************************************************/
		unsigned int MATGetNbColum() const { return uiMATNbColum; };

		/******************************************************************************************
		 ***** MATGetNbRow() Getter of matrix number of row									  *****
		 ******************************************************************************************
		 ***** Input : None																	  *****
		 ***** Precondition: initialised CMatrix											  *****
		 ***** Output:  unsigned int														  *****
		 ***** Postconditions :  value is the num of row									  *****
		 ******************************************************************************************/
		unsigned int MATGetNbRow() const { return uiMATNbRow; };

		/******************************************************************************************
		 ***** MATGetValue() Get value from a slot of matrix								  *****
		 ******************************************************************************************
		 ***** Input : unsigned int uiNumColum, unsigned int uiNumRow,						  *****
		 ***** Precondition: uiNumColum <= uiMATNbColum && uiNumRow <=uiMATNbRow			  *****
		 ***** Output:  MyType value														  *****
		 ***** Postconditions :  value is the element of the coordonate (uiNumRow,uiNumColum) *****
		 ******************************************************************************************/
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

		/****************************************************************************************
		 ***** operator-() oposite CMatrix										            *****
		 ****************************************************************************************
		 ***** Input :  None																*****
		 ***** Precondition: this initialized												*****
		 ***** Output:  CMatrix																*****
		 ***** Postconditions : every element of CMatrix is the oposite (* -1) of this  	*****
		 ****************************************************************************************/
		CMatrix operator-() const;

		/********************************************************************************************
		 ***** operator+() Addition between 2 matrix with '+'				                    *****
		 ********************************************************************************************
		 ***** Input :  MATParam     a CMatrix													*****
		 ***** Precondition: MATParam initialized ant same size with this						*****
		 ***** Output:  CMatrix																	*****
		 ***** Postconditions : every element of CMatrix is the addition of this and MATParam	*****
		 ********************************************************************************************/
		CMatrix operator+(const CMatrix & MATParam) const;

		/****************************************************************************************
		 ***** operator-() Substraction between 2 matrix with '-'				            *****
		 ****************************************************************************************
		 ***** Input :  MATParam     a CMatrix												*****
		 ***** Precondition: MATParam initialized											*****
		 ***** Output:  CMatrix																*****
		 ***** Postconditions : every element of CMatrix is the minus of this and MATParam	*****
		 ****************************************************************************************/
		CMatrix operator-(const CMatrix & MATParam) const;

		/************************************************************************
		 ***** operator=() replace matrix                                   *****
		 ************************************************************************
		 ***** Input :  MATParam a CMatrix	                                *****
		 ***** Precondition: none                                           *****
		 ***** Output:  NOne                                                *****
		 ***** Postconditions : this as the sam value as MAtParm            *****
		 ************************************************************************/
		CMatrix& operator=(const CMatrix & MATParam);

		/*************************************************************************************
		 ***** operator*() Multiply between 2 matrix with '*'							 *****
		 *************************************************************************************
		 ***** Input :  MATParam a CMatrix					                             *****
		 ***** Precondition: MATParam initialized and this.nbcolum = MATParam.uiMATnbRow *****
		 ***** Output:  CMatrix															 *****
		 ***** Postconditions : every element of CMatrix is divide by the double		 *****
		 *************************************************************************************/
		CMatrix operator*(const CMatrix& MATParam) const;

		/*************************************************************************************
		 ***** operator/() Multiply between 2 matrix with '/'							 *****
		 *************************************************************************************
		 ***** Input :  MATParam a CMatrix					                             *****
		 ***** Precondition: MATParam initialized and this.nbcolum = MATParam.uiMATnbRow *****
		 ***** Output:  CMatrix															 *****
		 ***** Postconditions : every element of CMatrix is divide by the double		 *****
		 *************************************************************************************/
		CMatrix operator/(const CMatrix& MATParam) const;

		/********************************************************************************
		 ***** operator*() Multiply between matrix and a value with '*'				*****
		 ********************************************************************************
		 ***** Input :  dCoeff a double												*****
		 ***** Precondition:  None													*****
		 ***** Output:  CMatrix														*****
		 ***** Postconditions : every element of CMatrix is multiplie by the dCOeff *****
		 ********************************************************************************/
		CMatrix<MType> operator*(const double & dCoeff) const;

		/********************************************************************************
		 ***** operator*() Multiply between matrix and a value with '*'				*****
		 ********************************************************************************
		 ***** Input :  COMparam a CComplex											*****
		 ***** Precondition:  None													*****
		 ***** Output:  CMatrix														*****
		 ***** Postconditions : every element of CMatrix is multiply by the COMparam*****
		 ********************************************************************************/
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

		/**************************************************************************
		 ***** operator/() Divide matrix by a value with '/'                  *****
		 **************************************************************************
		 ***** Input :  COMparam a CComplex                                   *****
		 ***** Precondition: different of 0                                   *****
		 ***** Output:  CMatrix                                               *****
		 ***** Postconditions : every element of CMatrix is divide by COMparam*****
		 **************************************************************************/
		CMatrix<CComplex> operator/(const CComplex & COMparam) const;

		/**************************************************************************
		 ***** operator CMatrix() conversion operator		                  *****
		 **************************************************************************
		 ***** Input :  None												  *****
		 ***** Precondition: None											  *****
		 ***** Output:  CMatrix<MType>                                        *****
		 ***** Postconditions : convert CMatrix<T> to CMatrix<MType>		  *****
		 **************************************************************************/
		template <class T>
		explicit operator CMatrix<T>() const;
		
		/********************************************************************************
		 ***** operator*() Multiply between matrix and a value with '*'				*****
		 ********************************************************************************
		 ***** Input :  dCoeff a double												*****
		 ***** Precondition:  None													*****
		 ***** Output:  CMatrix														*****
		 ***** Postconditions : every element of CMatrix is multiplie by the dCOeff *****
		 ********************************************************************************/
		template <class T>
		friend CMatrix<T> operator*(const double & dCoeff, const CMatrix<T>& MAT);

		/********************************************************************************
		 ***** operator*() Multiply between matrix and a value with '*'				*****
		 ********************************************************************************
		 ***** Input :  COMparam a CComplex											*****
		 ***** Precondition:  None													*****
		 ***** Output:  CMatrix														*****
		 ***** Postconditions : every element of CMatrix is multiply by the COMparam*****
		 ********************************************************************************/
		template <class T>
		friend CMatrix<CComplex> operator*(const CComplex & COMparam, const CMatrix & MATparam);

		/************************************************************************
		 ***** operator/() Divide matrix by a value with '/'                *****
		 ************************************************************************
		 ***** Input :  dCoeff a double                                     *****
		 ***** Precondition: different of 0                                 *****
		 ***** Output:  CMatrix                                             *****
		 ***** Postconditions : every element of CMatrix is divide by dCoeff*****
		 ************************************************************************/
		template <class T>
		friend CMatrix<T> operator/(const double & dCoeff, const CMatrix & MATparam);

		/**************************************************************************
		 ***** operator/() Divide matrix by a value with '/'                  *****
		 **************************************************************************
		 ***** Input :  COMparam a CComplex                                   *****
		 ***** Precondition: different of 0                                   *****
		 ***** Output:  CMatrix                                               *****
		 ***** Postconditions : every element of CMatrix is divide by COMparam*****
		 **************************************************************************/
		template <class T>
		friend CMatrix<CComplex> operator/(const CComplex & COMparam, const CMatrix & MATparam);

		/**************************************************************************
		 ***** operator<<		                                              *****
		 **************************************************************************
		 ***** Input : const CMatrix& MATparam, ostream                       *****
		 ***** precondtion : MATParam is initialized                          *****
		 ***** Output : ostream                                               *****
		 ***** Postcondition : send in ostream flux MATparam values printable *****
		 ***** format	                                                      *****
		 **************************************************************************/
		template<class T>
		friend std::ostream & operator<<(std::ostream & os, const CMatrix<T> & MATparam);
};

#include "CMatrix.ipp"

#endif	//C_MATRIX_H