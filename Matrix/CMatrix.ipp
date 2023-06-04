//CMatrix.ipp file used to define function from CMatrix class declare in CMatrix.h


/************************************************************************************************
 ***** CMatrix() constructor															    *****
 ************************************************************************************************
 ***** Input : nbRow and nbColumn unsigned int											    *****
 ***** Precondition: None																    *****
 ***** Output:  None																	    *****
 ***** Postconditions : construct a CMatrix with nbRow row & nbColumn Column with null value*****
 ************************************************************************************************/
template <class Mtype>
CMatrix<Mtype>::CMatrix(unsigned int uiNbRow, unsigned int uiNbColum)
{
	if (uiNbRow < 0 || uiNbColum < 0) {
		throw(CException(VALUE_ERROR,"VALUE_ERROR\nCMatrix<Mtype>::CMatrix : Use correct value"));
	}

	unsigned int uiLoop;
	unsigned int uiLoop2;


	ppMTypeMATvalue = new Mtype *[uiNbRow];
	for (uiLoop = 0; uiLoop < uiNbRow; uiLoop++)
	{
		ppMTypeMATvalue[uiLoop] = new Mtype[uiNbColum];
		for (uiLoop2 = 0; uiLoop2 < uiNbColum; uiLoop2++)
		{
			ppMTypeMATvalue[uiLoop][uiLoop2] = 0;
		}
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
	if (uiNumRow > uiMATNbRow || uiNumColum > uiMATNbColum || uiNumColum < 0 || uiNumRow < 0)
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


template <class MType>
CMatrix<MType> CMatrix<MType>::operator*(CComplex COMparam) {
	CMatrix MATnew(this.MATGetNbRow(), this.MATGetNbColumn());

	for (unsigned int uiRow = 0; uiRow < MATGetNbRow(); uiRow++) {
		for (unsigned int uiColumn = 0; uiColumn < this.MATGetNbColumn(); uiColumn++) {
			CComplex COMValue = MATGetValue(uiRow, uiColumn);
			COMValue *= COMparam;
			MATnew.MATSetValue(uiRow, uiColumn, COMValue);
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

/********************************************************************************
 ***** operator*() Multiply between a value and a matrix with '*'			*****
 ********************************************************************************
 ***** Input :  dCoeff a double												*****
 ***** Precondition:  None													*****
 ***** Output:  CMatrix														*****
 ***** Postconditions : every element of CMatrix is multiplie by the dCOeff *****
 ********************************************************************************/
template <class MType>
CMatrix<MType> operator*(double dCoeff, CMatrix<MType> MAT)
{
	CMatrix<MType> MATnew(MAT.MATGetNbRow(), MAT.MATGetNbColum());

	unsigned int uiRow, uiColum;
	for (uiRow = 0; uiRow < MAT.MATGetNbRow(); uiRow++)
	{
		for (uiColum = 0; uiColum < MAT.MATGetNbColum(); uiColum++)
		{
			MATnew.MATSetValue(uiRow, uiColum, MAT.MATGetValue(uiRow, uiColum) * dCoeff);
		}
	}
	return MATnew;
}

template<typename T, typename MType>
CMatrix<typename std::common_type<T, MType>::type> operator+(const CMatrix<T>& MATparam1, const CMatrix<MType>& MATparam2)
{
	if (MATparam1.uiMATNbColum != MATparam2.uiMATNbColum || MATparam1.uiMATNbRow != MATparam2.uiMATNbRow) {
		throw CException(DIMENSION_ERROR, "DIMENSION_ERROR\nCMatrix<typename std::common_type<T, MType>::type> operator+ : can't add Matrix with different sizes");
	}

	unsigned int uiRow, uiColum;
	CMatrix<typename std::common_type<T, MType>::type> MATnew(MATparam1.uiMATNbRow, MATparam1.uiMATNbColum);

	for (uiRow = 0; uiRow < MATparam1.uiMATNbRow; uiRow++) {
		for (uiColum = 0; uiColum < MATparam1.uiMATNbColum; uiColum++) {
			MATnew.ppMTypeMATvalue[uiRow][uiColum] = MATparam2.ppMTypeMATvalue[uiRow][uiColum] + MATparam1.ppMTypeMATvalue[uiRow][uiColum];
		}
	}
	return MATnew;
}


template <class MType>
std::ostream & operator<<(std::ostream & os, const CMatrix<MType> & MATparam)
{
	os << "[";
	if (MATparam.ppMTypeMATvalue)
	{
		for (unsigned int uiLoop1 = 0; uiLoop1 < MATparam.MATGetNbRow(); uiLoop1++)
		{
			for (unsigned int uiLoop2 = 0; uiLoop2 < MATparam.MATGetNbColum(); uiLoop2++)
			{
				os << " " << MATparam.MATGetValue(uiLoop1, uiLoop2);
			}
			if (uiLoop1 != MATparam.MATGetNbRow()-1) {
				os << "\n ";
			}
		}
	}
	os << " ]";

	return os;
}
