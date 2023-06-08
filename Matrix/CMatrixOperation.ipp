//CMatrixOperation.ipp file used to define function from CMatrixOperation class declare in CMatrixOperation.h
#include "CMatrixOperation.h"


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
template <class MType>
CMatrix<MType> * CMatrixOperation<MType>::MOPCreateMAT(const char *pcFilename)
{
	CStringOperation SOP;
	CParseTable PTA;
	CParser * pPARcontent = new CParser(pcFilename);
	char * buffer = nullptr;

	CMatrix<MType> * pMATnew;

	buffer = pPARcontent->PARgetValue("NBLignes");		//read NBLignes 
	unsigned int Nblignes = SOP.stoi(buffer);

	buffer = pPARcontent->PARgetValue("NBColonnes");	//read NBColonnes
	unsigned int NbColonnes = SOP.stoi(buffer);

	buffer = pPARcontent->PARgetValue("TypeMatrice");	//read TypeMatrice

	if (strcmp(buffer, "double") == 0)
	{
		if (typeid(MType) != typeid(double))
		{
			throw new CException(VALUE_ERROR, "VALUE_ERROR\nCMatrixOperation<MType>::MOPCreateMAT : incohernent type beetween file and object");
		}
		pMATnew = new CMatrix<MType>(Nblignes, NbColonnes);
	}
	else if (strcmp(buffer, "complex") == 0)
	{
		if (typeid(MType) != typeid(CComplex))
		{
			throw new CException(VALUE_ERROR, "VALUE_ERROR\nCMatrixOperation<MType>::MOPCreateMAT : incohernent type beetween file and object");
		}
		pMATnew = new CMatrix<MType>(Nblignes, NbColonnes);
	}
	else
	{
		throw CException(VALUE_ERROR, "VALUE_ERROR\nCMatrixOperation<MType>::MOPCreateMAT : don't handle this type of element");
	}

	buffer = pPARcontent->PARgetValue("Matrice");		//read values table

	PTA.PTAparseTable(buffer, pMATnew, Nblignes, NbColonnes);	//read values

	delete pPARcontent;

	return pMATnew;
}

/************************************************************************
 ***** MOPransposeMAT() Transpose a matrix                          *****
 ************************************************************************
 ***** Input :  const CMatrix<MType> MATparam                       *****
 ***** Precondition: MATparam is initialized                        *****
 ***** Output:  CMatrix                                             *****
 ***** Postconditions : The output is the transpose of CMatrix      *****
 ************************************************************************/
template <class MType>
CMatrix<MType>* CMatrixOperation<MType>::MOPtransposeMAT(CMatrix<MType> MATparam)
{
	CMatrix<MType>* MATnew = new CMatrix<MType>(MATparam.MATGetNbColum(), MATparam.MATGetNbRow());

	unsigned int uiRow, uiColum;
	for (uiRow = 0; uiRow < MATparam.MATGetNbRow(); uiRow++)
	{
		for (uiColum = 0; uiColum < MATparam.MATGetNbColum(); uiColum++)
		{
			MATnew.ppMTypeMATvalue[uiColum][uiRow] = MATparam.MATGetValue(uiRow, uiColum);
		}
	}
	return MATnew;
}

/**************************************************************************
 ***** MOPfillMATwith                                                 *****
 **************************************************************************
 ***** Input : const CMatrix<MType> MATparam                          *****
 ***** precondtion : MATparam is initialized                          *****
 ***** Output : None                                                  *****
 ***** Postcondition : fill matrix with MType value                   *****
 **************************************************************************/
template <class MType>
void CMatrixOperation<MType>::MOPfillMATwith(CMatrix<MType>& MATparam, const MType& MTypeParam)
{
	for (unsigned int uiRow = 0; uiRow < MATparam.MATGetNbRow() ; uiRow++)
	{
		for (unsigned int uiColum = 0; uiColum < MATparam.MATGetNbColum() ; uiColum++)
		{
			MATparam.MATSetValue(uiRow, uiColum, MTypeParam);
		}
	}
}