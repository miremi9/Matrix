#ifndef STD_C_MATRIX_H
#define STD_C_MATRIX_H

#include <iostream>

#include "CException.h"

#define DIMENSION_ERROR 3

template <class MType> class CMatrix
{
/*Attributs*/
private:
	MType ** ppMTypeMATvalue;		//Row List of Colum List of MType Value

	unsigned int uiMATNbColum;		//Number of Colum

	unsigned int uiMATNbRow;		//Number of Row

/*Constructors & Destructors*/
public:
	CMatrix() : CMatrix<MType>(0, 0) {};

	CMatrix(unsigned int nbRow, unsigned int nbColum);

	CMatrix(const CMatrix<MType>& MATParam);

	~CMatrix();

/*Methods*/
public:
	unsigned int MATGetNbColum() const { return uiMATNbColum; };

	unsigned int MATGetNbRow() const  { return uiMATNbRow; };

	MType MATGetValue(unsigned int uiNumColum, unsigned int uiNumRow) const ;

	void MATSetValue(unsigned int uiNumColum, unsigned int uiNumRow, MType mtValue);

	CMatrix operator+(CMatrix MATParam);

	CMatrix operator-(CMatrix MATParam);

	void operator=(CMatrix MATParam);

	CMatrix operator*(CMatrix MATParam);

	CMatrix operator*(double dCoeff);

	CMatrix operator/(double dCoeff);

	CMatrix MATTranspose();

	
};

/**********************************************************************************************
 ***** CMatrix() constructor															  *****
 **********************************************************************************************
 ***** Input : nbRow and nbColumn unsigned int											  *****
 ***** Precondition: None																  *****
 ***** Output:  None																	  *****
 ***** Postconditions : construct a CMatrix with nbRow row & nbColumn Column with no value*****
 **********************************************************************************************/
template <class Mtype>
CMatrix<Mtype>::CMatrix(unsigned int uiNbRow, unsigned int uiNbColum)
{
	if (uiNbRow < 0 || uiNbColum < 0) {
		throw(CException(VALUE_ERROR));
	}

	unsigned int uiLoop;
	
	ppMTypeMATvalue = new Mtype * [uiNbRow];
	for (uiLoop = 0; uiLoop < uiNbRow; uiLoop++)
	{
		ppMTypeMATvalue[uiLoop] = new Mtype[uiNbColum];
	}
	uiMATNbRow = uiNbRow;
	uiMATNbColum = uiNbColum;
}

/****************************************************************************
 ***** CMatrix() constructor  of copy                                   *****
 ****************************************************************************
 ***** Input : a matrix                                                 *****
 ***** Precondition: None                                               *****
 ***** Output:  None                                                    *****
 ***** Postconditions : replace totaly old matrix with inputed one      *****
 ****************************************************************************/
template <class Mtype>
CMatrix<Mtype>::CMatrix(const CMatrix<Mtype>& MATParam)
{
	unsigned int uiRow, uiColum;

	uiMATNbRow = MATParam.uiMATNbRow;
	uiMATNbColum = MATParam.uiMATNbColum;

	ppMTypeMATvalue = new Mtype*[uiMATNbRow];
	for (unsigned int uiLoop = 0; uiLoop < uiMATNbRow; uiLoop++)
	{
		ppMTypeMATvalue[uiLoop] = new Mtype[uiMATNbColum];
	}

	for (uiRow = 0; uiRow < uiMATNbRow; uiRow++)
	{
		for (uiColum = 0; uiColum < uiMATNbColum; uiColum++)
		{
			ppMTypeMATvalue[uiRow][uiColum] = MATParam.ppMTypeMATvalue[uiRow][uiColum];
		}
	}
}


/*********************************************************************************
 ***** CMatrix() destructor													 *****
 *********************************************************************************
 ***** Input : None															 *****
 ***** Precondition: None													 *****
 ***** Output:  None														 *****
 ***** Postconditions : delete every element of the object					 *****
 *********************************************************************************/
template <class Mtype>
CMatrix<Mtype>::~CMatrix()
{
	unsigned int uiLoop;
	for (uiLoop = 0; uiLoop < uiMATNbRow; uiLoop++)
	{
		delete[] ppMTypeMATvalue[uiLoop];
	}
	delete[] ppMTypeMATvalue;
}

/******************************************************************************************
 ***** MATGetValue() Get value from a slot of matrix								  *****
 ******************************************************************************************
 ***** Input : unsigned int uiNumColum, unsigned int uiNumRow,						  *****
 ***** Precondition: uiNumColum <= uiMATNbColum && uiNumRow <=uiMATNbRow			  *****
 ***** Output:  MyType value														  *****
 ***** Postconditions :  value is the element of the coordonate (uiNumRow,uiNumColum) *****
 ******************************************************************************************/
template <class Mtype>
Mtype CMatrix<Mtype>::MATGetValue(unsigned int uiNumRow, unsigned int uiNumColum) const 
{
	if (uiNumRow >uiMATNbRow || uiNumColum > uiMATNbColum ||uiNumColum <0 || uiNumRow <0)
	{
		throw(CException(VALUE_ERROR));
	}

	return ppMTypeMATvalue[uiNumRow][uiNumColum];
}

/**************************************************************************************************************
 ***** MATSetValue() CHange value from a slot of matrix													  *****
 **************************************************************************************************************
 ***** Input : unsigned int uiNumColum, unsigned int uiNumRow, MType mtValue                              *****
 ***** Precondition: uiNumColum <= uiMATNbColum && uiNumRow <=uiMATNbRow								  *****
 ***** Output:  None																					  *****
 ***** Postconditions : the value of the element of the coordonate (uiNumRow,uiNumColum) is mtValue       *****
 **************************************************************************************************************/
template <class MType>
void CMatrix<MType>::MATSetValue(unsigned int uiNumRow, unsigned int uiNumColum, MType mtValue)
{
	if (uiNumRow > uiMATNbRow || uiNumColum > uiMATNbColum || uiNumColum < 0 || uiNumRow < 0)
	{
		throw(CException(VALUE_ERROR));
	}

	ppMTypeMATvalue[uiNumRow][uiNumColum] = mtValue;
}

/********************************************************************************************
 ***** operator+() Addition between 2 matrix with '+'				                    *****
 ********************************************************************************************
 ***** Input :  MATParam     a CMatrix													*****
 ***** Precondition: MATParam initialized ant same size with this						*****
 ***** Output:  CMatrix																	*****
 ***** Postconditions : every element of CMatrix is the addition of this and MATParam	*****
 ********************************************************************************************/
template <class MType>
CMatrix<MType> CMatrix<MType>::operator+(CMatrix MATParam)
{
	if (uiMATNbColum != MATParam.uiMATNbColum || uiMATNbRow != MATParam.uiMATNbRow)
	{
		throw(CException(DIMENSION_ERROR));
	}

	unsigned int uiRow, uiColum;

	CMatrix<MType> MATnew(uiMATNbRow, uiMATNbColum);
	for (uiRow = 0; uiRow < uiMATNbRow; uiRow++)
	{
		for (uiColum = 0; uiColum < uiMATNbColum; uiColum++)
		{
			MATnew.ppMTypeMATvalue[uiRow][uiColum] = MATParam.ppMTypeMATvalue[uiRow][uiColum] + ppMTypeMATvalue[uiRow][uiColum];
		}
	}
	return MATnew;
}

/****************************************************************************************
 ***** operator-() Substraction between 2 matrix with '-'				            *****
 ****************************************************************************************
 ***** Input :  MATParam     a CMatrix												*****
 ***** Precondition: MATParam initialized											*****
 ***** Output:  CMatrix																*****
 ***** Postconditions : every element of CMatrix is the minus of this and MATParam	*****
 ****************************************************************************************/
template <class MType>
CMatrix<MType> CMatrix<MType>::operator-(CMatrix MATParam)
{
	if (uiMATNbColum != MATParam.uiMATNbColum || uiMATNbRow != MATParam.uiMATNbRow)
	{
		throw(CException(DIMENSION_ERROR));
	}

	unsigned int uiRow, uiColum;

	CMatrix<MType> MATnew(uiMATNbRow, uiMATNbColum);
	for (uiRow = 0; uiRow < uiMATNbRow; uiRow++)
	{
		for (uiColum = 0; uiColum < uiMATNbColum; uiColum++)
		{
			MATnew.ppMTypeMATvalue[uiRow][uiColum] = ppMTypeMATvalue[uiRow][uiColum] - MATParam.ppMTypeMATvalue[uiRow][uiColum];
		}
	}
	return MATnew;
}

/************************************************************************
 ***** operator=() replace matrix                                   *****
 ************************************************************************
 ***** Input :  MATParam a CMatrix	                                *****
 ***** Precondition: none                                           *****
 ***** Output:  NOne                                                *****
 ***** Postconditions : this as the sam value as MAtParm            *****
 ************************************************************************/
template <class MType>
void CMatrix<MType>::operator=(CMatrix MATParam)
{
	unsigned int uiRow, uiColum;

	for (unsigned int uiLoop = 0; uiLoop < uiMATNbRow; uiLoop++)	//delete old matrix
	{
		delete[] ppMTypeMATvalue[uiLoop];
	}
	delete[] ppMTypeMATvalue;

	uiMATNbRow = MATParam.uiMATNbRow;
	uiMATNbColum = MATParam.uiMATNbColum;

	ppMTypeMATvalue = new MType*[uiMATNbRow];			//create a new matrix
	for (unsigned int uiLoop = 0; uiLoop < uiMATNbRow; uiLoop++)
	{
		ppMTypeMATvalue[uiLoop] = new MType[uiMATNbColum];
	}

	for (uiRow = 0; uiRow < uiMATNbRow; uiRow++)		//copie value to the new matrix
	{
		for (uiColum = 0; uiColum < uiMATNbColum; uiColum++)
		{
			ppMTypeMATvalue[uiRow][uiColum] = MATParam.ppMTypeMATvalue[uiRow][uiColum];
		}
	}
}

/*************************************************************************************
 ***** operator*() Multiply between 2 matrix with '*'							 *****
 *************************************************************************************
 ***** Input :  MATParam a CMatrix					                             *****
 ***** Precondition: MATParam initialized and this.nbcolum = MATParam.uiMATnbRow *****
 ***** Output:  CMatrix															 *****
 ***** Postconditions : every element of CMatrix is divide by the double		 *****
 *************************************************************************************/
template <class MType>
CMatrix<MType> CMatrix<MType>::operator*(CMatrix MATParam)
{
	if (uiMATNbColum != MATParam.uiMATNbRow) {
		throw(CException(DIMENSION_ERROR));
	}

	CMatrix<MType> MATnew(uiMATNbRow, MATParam.uiMATNbColum);

	unsigned int uiRow, uiColum;
	unsigned int uiSize = uiMATNbColum;
	unsigned int uiLoop;
	MType mtValue;
	for (uiRow = 0; uiRow < uiMATNbRow; uiRow++)
	{
		for (uiColum = 0; uiColum < MATParam.uiMATNbColum; uiColum++)	//foreach value of the new matrix
		{
			mtValue = 0;
			for (uiLoop = 0; uiLoop < uiSize; uiLoop++)
			{
				mtValue += ppMTypeMATvalue[uiRow][uiLoop] * MATParam.ppMTypeMATvalue[uiLoop][uiColum];
			}
			MATnew.ppMTypeMATvalue[uiRow][uiColum] = mtValue;
		}
	}
	return MATnew;
}

/********************************************************************************
 ***** operator*() Multiply between matrix and a value with '*'				*****
 ********************************************************************************
 ***** Input :  dCoeff a double												*****
 ***** Precondition:  None													*****
 ***** Output:  CMatrix														*****
 ***** Postconditions : every element of CMatrix is multiplie by the dCOeff *****
 ********************************************************************************/
template <class MType>
CMatrix<MType> CMatrix<MType>::operator*(double dCoeff)
{
	CMatrix<MType> MATnew(uiMATNbRow, uiMATNbColum);

	unsigned int uiRow, uiColum;
	for (uiRow = 0; uiRow < uiMATNbRow; uiRow++)
	{
		for (uiColum = 0; uiColum < uiMATNbColum; uiColum++)
		{
			MATnew.ppMTypeMATvalue[uiRow][uiColum] = ppMTypeMATvalue[uiRow][uiColum] * dCoeff;
		}
	}
	return MATnew;
}

/************************************************************************
 ***** operator/() Divide matrix by a value with '/'                *****
 ************************************************************************
 ***** Input :  dCoeff a double                                     *****
 ***** Precondition: different of 0                                 *****
 ***** Output:  CMatrix                                             *****
 ***** Postconditions : every element of CMatrix is divide by dCoeff*****
 ************************************************************************/
template <class MType>
CMatrix<MType> CMatrix<MType>::operator/(double dCoeff)
{
	CMatrix<MType> MATnew(uiMATNbRow, uiMATNbColum);

	unsigned int uiRow, uiColum;
	for (uiRow = 0; uiRow < uiMATNbRow; uiRow++)
	{
		for (uiColum = 0; uiColum < uiMATNbColum; uiColum++)
		{
			MATnew.ppMTypeMATvalue[uiRow][uiColum] = ppMTypeMATvalue[uiRow][uiColum] / dCoeff;
		}

	}
	return MATnew;
}

/************************************************************************
 ***** MATTranspose() Transpose a matrix                            *****
 ************************************************************************
 ***** Input :  None                                                *****
 ***** Precondition: None                                           *****
 ***** Output:  CMatrix                                             *****
 ***** Postconditions : The output is the transpose of CMatrix      *****
 ************************************************************************/
template <class MType>
CMatrix<MType> CMatrix<MType>::MATTranspose()
{
	CMatrix<MType> MATnew(uiMATNbColum, uiMATNbRow);

	unsigned int uiRow, uiColum;
	for (uiRow = 0; uiRow < uiMATNbRow; uiRow++)
	{
		for (uiColum = 0; uiColum < uiMATNbColum; uiColum++)
		{
			MATnew.ppMTypeMATvalue[uiColum][uiRow] = ppMTypeMATvalue[uiRow][uiColum];
		}

	}
	return MATnew;
}


/********************************************************************************
 ***** operator*() Multiply between a value and a matrix with '*'			*****
 ********************************************************************************
 ***** Input :  dCoeff a double												*****
 ***** Precondition:  None													*****
 ***** Output:  CMatrix														*****
 ***** Postconditions : every element of CMatrix is multiplie by the dCOeff *****
 ********************************************************************************/
template <class MType>
CMatrix<MType> operator*(double dCoeff,CMatrix<MType> MAT)
{
	CMatrix<MType> MATnew(MAT.MATGetNbRow(), MAT.MATGetNbColum());

	unsigned int uiRow, uiColum;
	for (uiRow = 0; uiRow < MAT.MATGetNbRow(); uiRow++)
	{
		for (uiColum = 0; uiColum < MAT.MATGetNbColum(); uiColum++)
		{
			MATnew.MATSetValue(uiRow,uiColum,MAT.MATGetValue(uiRow,uiColum) * dCoeff);
		}
	}
	return MATnew;
}

#endif