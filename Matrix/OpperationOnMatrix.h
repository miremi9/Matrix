#ifndef C_MATRIX_OPPERATION_H
#define C_MATRIX_OPPERATION_H

#define VALUE_ERROR 3
#include "Matrix.h"
#include "CParser.h"
#include "CStringOperation.h"
#include <iostream>
#include <stdlib.h>

#include "ParseTab.h"
template <class MType>
class CMatrixOperation {
public:
	CMatrix<MType> * MOPCreateMAT(const char *pcFilename);
	void MOPprintMAT(const CMatrix<MType> MATparam);
};

template <class MType>
CMatrix<MType> *  CMatrixOperation<MType>::MOPCreateMAT(const char *pcFilename)
{
	CStringOperation SOP;
	CParser * pPARcontent = new CParser(pcFilename);
	char * buffer = nullptr;

	CMatrix<MType> * pMATnew;

	buffer = pPARcontent->PARgetValue("NBLignes");
	unsigned int Nblignes = SOP.stoi(buffer);

	buffer = pPARcontent->PARgetValue("NBColonnes");
	unsigned int NbColonnes = SOP.stoi(buffer);

	buffer = pPARcontent->PARgetValue("TypeMatrice");

	if (strcmp(buffer, "double") == 0)
	{
		pMATnew = new CMatrix<MType>(Nblignes, NbColonnes);
	}
	else if (strcmp(buffer, "CComplexe") == 0)
	{
		pMATnew = new CMatrix<MType>(Nblignes, NbColonnes);
	}
	else
	{
		throw CException(VALUE_ERROR, "don't handle this type of element");
	}

	buffer = pPARcontent->PARgetValue("Matrice");

	ParseTab(buffer, pMATnew, Nblignes, NbColonnes);

	return pMATnew;
	
}


/****************************************************************************
 ***** MATPrint() Print matrix values									*****
 ****************************************************************************
 ***** Input : None														*****
 ***** Precondition: None												*****
 ***** Output:  None													*****
 ***** Postconditions : Print every element of CMatrix in a correct way *****
 ****************************************************************************/
template <class MType>
void  CMatrixOperation<MType>::MOPprintMAT(const CMatrix<MType> MATparam)
{
	unsigned int uiRow, uiColum;
	for (uiRow = 0; uiRow < MATparam.MATGetNbRow(); uiRow++)
	{
		for (uiColum = 0; uiColum < MATparam.MATGetNbColum(); uiColum++)	//foreach value of the new matrix
		{
			std::cout << MATparam.MATGetValue(uiRow,uiColum)<< " ";
		}
		std::cout << "\n";
	}
}

#endif