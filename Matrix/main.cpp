// main.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <iostream>

#include "CMatrix.h"
#include "CMatrixOperation.h"
#include "CParser.h"


int main(int argc, const char **argv)
{
	try {
		if (argc < 2) { throw CException(1, "ARGUMENT_ERROR\nMake sure to execute with a least 1 argument : text file to read\n"); }	//Test if there is at least one argument	
	}
	catch (const CException & EXCparam) {
		std::cerr << "Error occured during program initialisation\n";
		std::cerr << EXCparam << std::endl;
		return 1;
	}

	unsigned int nbComplexMatrix = 0;
	unsigned int nbDoubleMatrix = 0;
	unsigned int ComplexMatrix[50];
	unsigned int DoubleMatrix[50];

	try {
		CParser * pPARcontent;
		char * buffer;

		for (unsigned int uiloop = 1; uiloop <= (unsigned int) argc - 1; uiloop++)
		{
			pPARcontent = new CParser(argv[uiloop]);
			buffer = pPARcontent->PARgetValue("TypeMatrice");

			if (!strcmp(buffer, "double"))
			{
				DoubleMatrix[nbDoubleMatrix] = uiloop;
				nbDoubleMatrix++;
			}
			else if (!strcmp(buffer, "complex"))
			{
				ComplexMatrix[nbComplexMatrix] = uiloop;
				nbComplexMatrix++;
			}
			else {
				throw CException(VALUE_ERROR, "VALUE_ERROR\nLibrary don't handle this type of element for Matrix, only double or Complex");
			}
			delete pPARcontent;
		}
	}
	catch (const CException & EXCparam) {
		std::cerr << "Error occured during program initialisation\n";
		std::cerr << EXCparam << std::endl;
		return 1;
	}


	/*Matrix Construction*/
	CMatrix<double>** ppMATdoubleList = new CMatrix<double>*[nbDoubleMatrix];	//List of matrix double
	CMatrix<CComplex>** ppMATccomplexList = new CMatrix<CComplex>*[nbComplexMatrix];	//List of matrix complex

	CMatrixOperation<double> MOPdouble;
	CMatrixOperation<CComplex> MOPccomplex;

	try {
		for (unsigned int uiloop = 0; uiloop < nbDoubleMatrix; uiloop++)	//for each file in argument, create associate matrix
		{
			CMatrix<double> * pMATMatrix = MOPdouble.MOPCreateMAT(argv[DoubleMatrix[uiloop]]);
			ppMATdoubleList[uiloop] = pMATMatrix;
		}

		for (unsigned int uiloop = 0; uiloop < nbComplexMatrix; uiloop++)	//for each file in argument, create associate matrix
		{
			CMatrix<CComplex> * pMATMatrix = MOPccomplex.MOPCreateMAT(argv[ComplexMatrix[uiloop]]);
			ppMATccomplexList[uiloop] = pMATMatrix;
		}
	}
	catch (CException EXCparam) {
		std::cout << "Error occured during matrix construction\n";
		std::cout << EXCparam;
		return 1;
	}


	//show every created matrix
	std::cout << "Matrix created :\n";
	for (unsigned int uiloop = 0; uiloop < nbComplexMatrix; uiloop++) {	//show every complex matrix created
		std::cout << *ppMATccomplexList[uiloop] << std::endl;
	}
	for (unsigned int uiloop = 0; uiloop < nbDoubleMatrix; uiloop++) {	//show every double matrix created
		std::cout << *ppMATdoubleList[uiloop] << std::endl;
	}
	std::cout << std::endl;


	//initialise and define the scalar
	CComplex* COMvalue = new CComplex();
	std::cout << "Please, input a Scalar value : \n";
	std::cin >> *COMvalue;


	/*Apply methods on matrix*/
	try {

		std::cout << "Matrix product with scalar :\n";						//for each matrix, multiply with scalar
		for (unsigned int uiloop = 0; uiloop < nbComplexMatrix; uiloop++) {
			std::cout << *ppMATccomplexList[uiloop] * *COMvalue << std::endl;
		}
		for (unsigned int uiloop = 0; uiloop < nbDoubleMatrix; uiloop++) {
			std::cout << *ppMATdoubleList[uiloop] * *COMvalue << std::endl;
		}
		std::cout << std::endl;


		std::cout << "Matrix division with scalar :\n";						//for each matrix, divide with scalar
		for (unsigned int uiloop = 0; uiloop < nbComplexMatrix; uiloop++) {
			std::cout << *ppMATccomplexList[uiloop] / *COMvalue << std::endl;
		}
		for (unsigned int uiloop = 0; uiloop < nbDoubleMatrix; uiloop++) {
			std::cout << *ppMATdoubleList[uiloop] / *COMvalue << std::endl;
		}
		std::cout << std::endl;


		unsigned int uiRow;
		unsigned int uiColum;
		if (nbComplexMatrix != 0) {			//get matrix index
			uiRow = ppMATccomplexList[0]->MATGetNbRow(); 
			uiColum = ppMATccomplexList[0]->MATGetNbColum();
		}
		else {
			uiRow = ppMATdoubleList[0]->MATGetNbRow();
			uiColum = ppMATdoubleList[0]->MATGetNbColum();
		}


		std::cout << "Every Matrix addition :\n";
		CMatrix<CComplex>* pMATsum = new CMatrix<CComplex>(uiRow, uiColum);	//addition every matrix
		MOPccomplex.MOPfillMATwith(*pMATsum, 0);
		for (unsigned int uiloop = 0; uiloop < nbComplexMatrix; uiloop++) {
			*pMATsum = *pMATsum + *ppMATccomplexList[uiloop];
		}
		for (unsigned int uiloop = 0; uiloop < nbDoubleMatrix; uiloop++) {
			*pMATsum = *pMATsum + *ppMATdoubleList[uiloop];
		}
		std::cout << *pMATsum << std::endl;


		std::cout << "Every Matrix multiply :\n";						//multiply every matrix
		MOPccomplex.MOPfillMATwith(*pMATsum, 1);
		for (unsigned int uiloop = 0; uiloop < nbComplexMatrix; uiloop++) {
			*pMATsum = *pMATsum * *ppMATccomplexList[uiloop];
		}
		for (unsigned int uiloop = 0; uiloop < nbDoubleMatrix; uiloop++) {
			*pMATsum = *pMATsum * *ppMATdoubleList[uiloop];
		}
		std::cout << *pMATsum << std::endl;
		delete pMATsum;
	}
	catch (CException EXCparam) {
		std::cout << "Error occured during matrix operation\n";
		std::cout << EXCparam;
		return 1;
	}


	/*Memory management*/
	for (unsigned int uiloop = 0; uiloop < nbComplexMatrix; uiloop++) {
		delete ppMATccomplexList[uiloop];
	}
	for (unsigned int uiloop = 0; uiloop < nbDoubleMatrix; uiloop++) {
		delete ppMATdoubleList[uiloop];
	}

	delete[] ppMATdoubleList;
	delete[] ppMATccomplexList;
	delete COMvalue;

	return 0;
}
