#include "CMatrixOperation.h"
//CMatrixOperation.ipp file used to define function from CMatrixOperation class declare in CMatrixOperation.h


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

	buffer = pPARcontent->PARgetValue("NBLignes");
	unsigned int Nblignes = SOP.stoi(buffer);

	buffer = pPARcontent->PARgetValue("NBColonnes");
	unsigned int NbColonnes = SOP.stoi(buffer);

	buffer = pPARcontent->PARgetValue("TypeMatrice");

	if (strcmp(buffer, "double") == 0)
	{
		if (typeid(MType) != typeid(double))
		{
			throw new CException(VALUE_ERROR, "incohernent type beetween file and object");
		}
		pMATnew = new CMatrix<MType>(Nblignes, NbColonnes);
	}
	else if (strcmp(buffer, "complex") == 0)
	{
		if (typeid(MType) != typeid(CComplex))
		{
			throw new CException(VALUE_ERROR, "incohernent type beetween file and object");
		}
		pMATnew = new CMatrix<MType>(Nblignes, NbColonnes);
	}
	else
	{
		throw CException(VALUE_ERROR, "don't handle this type of element");
	}

	buffer = pPARcontent->PARgetValue("Matrice");

	PTA.PTAparseTable(buffer, pMATnew, Nblignes, NbColonnes);

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
 ***** MOPfillMAT                                                     *****
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