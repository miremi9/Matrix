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
		CMatrix(const CMatrix<T> & MATParam)
		{
			unsigned int uiRow, uiColum;

			uiMATNbRow = MATParam.MATGetNbRow();
			uiMATNbColum = MATParam.MATGetNbColum();

			ppMTypeMATvalue = new MType*[uiMATNbRow];
			for (unsigned int uiLoop = 0; uiLoop < uiMATNbRow; uiLoop++)
			{
				ppMTypeMATvalue[uiLoop] = new MType[uiMATNbColum];
			}

			for (uiRow = 0; uiRow < uiMATNbRow; uiRow++)
			{
				for (uiColum = 0; uiColum < uiMATNbColum; uiColum++)
				{
					ppMTypeMATvalue[uiRow][uiColum] = static_cast<MType>(MATParam.MATGetValue(uiRow, uiColum));
				}
			}
		}

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

		CMatrix operator-();

		CMatrix operator+(CMatrix MATParam);

		CMatrix operator-(CMatrix MATParam);

		void operator=(CMatrix MATParam);

		CMatrix operator*(CMatrix MATParam);

		CMatrix operator*(double dCoeff);

		CMatrix operator*(CComplex COMparam);

		/************************************************************************
		 ***** operator/() Divide matrix by a value with '/'                *****
		 ************************************************************************
		 ***** Input :  dCoeff a double                                     *****
		 ***** Precondition: different of 0                                 *****
		 ***** Output:  CMatrix                                             *****
		 ***** Postconditions : every element of CMatrix is divide by dCoeff*****
		 ************************************************************************/
		CMatrix operator/(double dCoeff);

		
		template <class T>
		operator CMatrix<T>() const
		{
			CMatrix<T> result(uiMATNbRow, uiMATNbColum);
			for (unsigned int uiRow = 0; uiRow < uiMATNbRow; uiRow++)
			{
				for (unsigned int uiColum = 0; uiColum < uiMATNbColum; uiColum++)
				{
					result.MATSetValue(uiRow, uiColum, static_cast<T>(ppMTypeMATvalue[uiRow][uiColum]));
				}
			}
			return result;
		}

		
		//template<typename T>
		//friend CMatrix<typename std::common_type<T, MType>::type> operator+(const CMatrix<T>& MATparam1, const CMatrix<MType>& MATparam2);
		

		//friend CMatrix operator+(CMatrix MATParam, CMatrix MATParam2);

		template<class T>
		friend std::ostream & operator<<(std::ostream & os, const CMatrix<T> & MATparam);
};

#include "CMatrix.ipp"

#endif	//C_MATRIX_H