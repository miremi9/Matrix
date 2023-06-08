// main.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <iostream>

#include "CMatrix.h"
#include "test.h"
#include "CMatrixOperation.h"


int main(int argc, const char **argv)
{/*
	try {
		testComplexe();
		testOPmatrix();
		testComplexe();
		testComplexMatrix();
		testGetComplex();
	}
	catch (const CException & EXCparam) {
		std::cerr << "Error occured during program initialisation\n";
		std::cerr << EXCparam << std::endl;
		return 1;
	}*/
	
	try {
		if (argc < 2) { throw CException(1, "ARGUMENT_ERROR\nMake sure to execute with a least 1 argument : text file to read\n"); }	//Test if there is at least one argument	
	}
	catch (const CException & EXCparam) {
		std::cerr << "Error occured during program initialisation\n";
		std::cerr << EXCparam << std::endl;
		return 1;
	}
	/*
	int iValue;
	std::cout << "Please, input a value scalar value : \n";		//ask user a scalar value
	std::cin >> iValue;
	*/

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
				throw CException(VALUE_ERROR, "VALUE_ERROR\n don't handle this type of element for Matrix, only double or Complex");
			}
			delete pPARcontent;
		}
	}
	catch (const CException & EXCparam) {
		std::cerr << "Error occured during program initialisation\n";
		std::cerr << EXCparam << std::endl;
		return 1;
	}

	std::cout << nbDoubleMatrix << std::endl;
	std::cout << nbComplexMatrix << std::endl;

	/*Matrix Construction*/
	CMatrix<double>* ppMATdoubleList = new CMatrix<double>[nbDoubleMatrix];	//List of matrix double
	CMatrix<CComplex>* ppMATccomplexList = new CMatrix<CComplex>[nbComplexMatrix];	//List of matrix complex

	try {
		CMatrixOperation<double> MOPdouble;
		CMatrixOperation<CComplex> MOPccomplex;

		for (unsigned int uiloop = 0; uiloop < nbDoubleMatrix; uiloop++)	//for each file in argument, create associate matrix
		{
			std::cout << uiloop << std::endl;
			CMatrix<double> * pMATMatrix = MOPdouble.MOPCreateMAT(argv[DoubleMatrix[uiloop]]);
			ppMATdoubleList[uiloop] = *pMATMatrix;
		}

		for (unsigned int uiloop = 0; uiloop < nbComplexMatrix; uiloop++)	//for each file in argument, create associate matrix
		{
			std::cout << uiloop << std::endl;
			CMatrix<CComplex> * pMATMatrix = MOPccomplex.MOPCreateMAT(argv[ComplexMatrix[uiloop]]);
			ppMATccomplexList[uiloop] = *pMATMatrix;
		}
	}
	catch (CException EXCparam) {
		std::cout << "Error occured during matrix construction\n";
		std::cout << EXCparam;
		return 1;
	}

	for (unsigned int uiloop = 0; uiloop < nbDoubleMatrix; uiloop++)	//for each file in argument, create associate matrix
	{
		std::cout << ppMATccomplexList[uiloop];
	}

	for (unsigned int uiloop = 0; uiloop < nbComplexMatrix; uiloop++)	//for each file in argument, create associate matrix
	{
		std::cout << ppMATdoubleList[uiloop];
	}

	/*Apply methods on matrix*/
	try {

		//MOPprintMAT(iValue + ppMATList[0]);


		/*
		for (int uiloop = 0; uiloop < argc - 1; uiloop++)		//for each matrix, multiply with constant
		{
			std::cout << "Matrix" << uiloop + 1 << " * " << iValue << ":\n";

			MOP.MOPprintMAT(ppMATList[uiloop] * iValue);
		}
		std::cout << "\n";

		for (int uiloop = 0; uiloop < argc - 1; uiloop++)		//for each matrix, divide with constant
		{
			std::cout << "Matrix" << uiloop + 1 << " / " << iValue << ":\n";
			MOP.MOPprintMAT(ppMATList[uiloop] / iValue);
		}
		std::cout << "\n";

		CMatrix<double> MatSum = ppMATList[0];
		for (int uiloop = 0; uiloop < argc - 2; uiloop++)		//addition of every matrix
		{
			MatSum = MatSum + ppMATList[uiloop + 1];
		}
		std::cout << "Addition of every Matrix :\n";
		MOP.MOPprintMAT(MatSum);

		std::cout << "\n";

		MatSum = ppMATList[0];
		for (int uiloop = 0; uiloop < argc - 2; uiloop++)		//addition/substraction of every matrix
		{
			if (uiloop % 2) {
				MatSum = MatSum + ppMATList[uiloop + 1];
			}
			else {
				MatSum = MatSum - ppMATList[uiloop + 1];
			}
		}
		std::cout << "Alternating Addition/Substraction of every Matrix :\n";
		MOP.MOPprintMAT(MatSum);
		std::cout << "\n";

		MatSum = ppMATList[0];
		for (int uiloop = 0; uiloop < argc - 2; uiloop++)		//multiply matrix
		{
			MatSum = MatSum * ppMATList[uiloop + 1];
		}
		std::cout << "Multiplication of every Matrix :\n";
		MOP.MOPprintMAT(MatSum);
		*/
	}
	catch (CException EXCparam) {
		std::cout << "Error occured during matrix operation\n";
		std::cout << EXCparam;
	}

	std::cout << "\ncomplete\n";

	delete[] ppMATdoubleList;
	delete[] ppMATccomplexList;

	return 0;
	
}
