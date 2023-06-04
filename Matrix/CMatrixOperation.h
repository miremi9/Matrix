#ifndef C_MATRIX_OPPERATION_H
#define C_MATRIX_OPPERATION_H

#include "CMatrix.h"
#include "CParser.h"
#include "CStringOperation.h"
#include <iostream>
#include <stdlib.h>
#include "CParseTable.h"

#define VALUE_ERROR 3


template <class MType> class CMatrixOperation
{
	public:

		/**************************************************************************
		 ***** MOPCreateMAT                                                   *****
		 **************************************************************************
		 ***** Input : const char *pcFilename                                 *****
		 ***** precondtion : pcFilename is the name of an actual file with    *****
		 ***** the correct syntax for initialized a matrix                    *****
		 ***** Output : CMatrix<MType> *                                      *****
		 ***** Postcondition : return CMatrix * with the type and the value   *****
		 ***** from the file                                                  *****
		 **************************************************************************/
		CMatrix<MType> * MOPCreateMAT(const char *pcFilename);

		/**************************************************************************
		 ***** MOPprintMAT                                                    *****
		 **************************************************************************
		 ***** Input : const CMatrix<MType> MATparam                          *****
		 ***** precondtion : MATparam is initialized                          *****
		 ***** Output : None                                                  *****
		 ***** Postcondition : print the matrix                               *****
		 **************************************************************************/
		void MOPprintMAT(const CMatrix<MType> MATparam);
};

#include "CMatrixOperation.ipp"

#endif	//C_MATRIX_OPPERATION_H