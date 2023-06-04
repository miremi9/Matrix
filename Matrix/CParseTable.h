#ifndef C_PARSE_TABLE_H
#define C_PARSE_TABLE_H

#include "CMatrix.h"
#include "CStringOperation.h"

class CParseTable
{
	public:

		/**************************************************************************
		 ***** ParseTab                                                       *****
		 **************************************************************************
		 ***** Input : char * pcContent, CMatrix<double> * pMATparam,         *****
		 ***** unsigned int Nblignes, unsigned int NbColonnes                 *****
		 ***** precondtion : pcContent is a char * representing a array of    *****
		 ***** double with a coherent Nbligne and Nbcolonnes                  *****
		 ***** Output : None                                                  *****
		 ***** Postcondition : set the value of pMATparam with the array      *****
		 ***** values                                                         *****
		 **************************************************************************/
		void PTAparseTable(char * pcContent, CMatrix<double> * pMATparam, unsigned int Nblignes, unsigned int NbColonnes);

		/**************************************************************************
		 ***** ParseTab                                                       *****
		 **************************************************************************
		 ***** Input : char * pcContent, CMatrix<CCOmplex> * pMATparam,       *****
		 ***** unsigned int Nblignes, unsigned int NbColonnes                 *****
		 ***** precondtion : pcContent is a char * representing a array of    *****
		 ***** CComplex with a coherent Nbligne and Nbcolonnes                *****
		 ***** Output : None                                                  *****
		 ***** Postcondition : set the value of pMATparam with the array      *****
		 ***** values                                                         *****
		 **************************************************************************/
		void PTAparseTable(char * pcContent, CMatrix<CComplex>* pMATparam, unsigned int Nblignes, unsigned int NbColonnes);
};

#endif	//C_PARSE_TABLE_H