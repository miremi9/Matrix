// Matrix.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <iostream>

#include "Matrix.h"
#include "test.h"
#include "CMatrixOperation.h"
int main(int argc, const char **argv)
{
	try
	{
		testComplexe();
		testOPmatrix();
		testComplexe();
		testComplexMatrix();
		testGetComplex();

	}
	catch (CException a)
	{

	}
	return 0;
	try {
		if (argc < 2) { throw(CException(FILE_ERROR)); }		//Test if there is at least one argument	
	}
	catch (CException EXCException) {
		std::cout << "Error occured during program initialisation\n";
		EXCException.EXCPrintException();
	}
	
	int iValue;
	std::cout << "Please, input a value : \n";		//ask user the constant value
	std::cin >> iValue;


	

	/*Matrix Construction*/
	CMatrixOperation<double> op;
	CMatrix<double>* ppMATList = new CMatrix<double>[argc - 1];	//List of matrix

	try {
		for (int uiloop = 0; uiloop < argc - 1; uiloop++)	//for each file in argument, create associate matrix
		{
			CMatrix<double> * pMATMatrix = op.MOPCreateMAT(argv[uiloop + 1]);
			ppMATList[uiloop] = *pMATMatrix;
		}
	}
	catch (CException EXCException) {
		std::cout << "Error occured during matrix construction\n";
		EXCException.EXCPrintException();
	}


	/*Apply methods on matrix*/
	try {
		for (int uiloop = 0; uiloop < argc - 1; uiloop++)		//for each matrix, multiply with constant
		{
			std::cout << "Matrix" << uiloop + 1 << " * " << iValue << ":\n";

			op.MOPprintMAT(ppMATList[uiloop] * iValue);
		}
		std::cout << "\n";

		for (int uiloop = 0; uiloop < argc - 1; uiloop++)		//for each matrix, divide with constant
		{
			std::cout << "Matrix" << uiloop + 1 << " / " << iValue << ":\n";
			op.MOPprintMAT(ppMATList[uiloop] / iValue);
		}
		std::cout << "\n";

		CMatrix<double> MatSum = ppMATList[0];
		for (int uiloop = 0; uiloop < argc - 2; uiloop++)		//addition of every matrix
		{
			MatSum = MatSum + ppMATList[uiloop + 1];
		}
		std::cout << "Addition of every Matrix :\n";
		op.MOPprintMAT(MatSum);

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
		op.MOPprintMAT(MatSum);
		std::cout << "\n";

		MatSum = ppMATList[0];
		for (int uiloop = 0; uiloop < argc - 2; uiloop++)		//multiply matrix
		{
			MatSum = MatSum * ppMATList[uiloop + 1];
		}
		std::cout << "Multiplication of every Matrix :\n";
		op.MOPprintMAT(MatSum);
	}
	catch (CException EXCException) {
		std::cout << "Error occured during matrix operation\n";
		EXCException.EXCPrintException();
	}

	delete[] ppMATList;

	return 0;
	
}
