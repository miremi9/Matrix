// main.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <iostream>

#include "CMatrix.h"
#include "test.h"
#include "CMatrixOperation.h"


int main(int argc, const char **argv)
{
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
	}
	
	try {
		if (argc < 2) { throw CException(FILE_ERROR, " FILE_ERROR\nMake sure your file exist with correct name & place\n"); }		//Test if there is at least one argument	
	}
	catch (const CException & EXCparam) {
		std::cerr << "Error occured during program initialisation\n";
		std::cerr << EXCparam << std::endl;
		return 1;
	}
	/*
	int iValue;
	std::cout << "Please, input a value : \n";		//ask user a constant value
	std::cin >> iValue;*/
	CMatrixOperation<double> MOP;
	

	/*Matrix Construction*/
	CMatrix<double>* ppMATList = new CMatrix<double>[argc - 1];	//List of matrix

	try {
		for (int uiloop = 0; uiloop < argc - 1; uiloop++)	//for each file in argument, create associate matrix
		{
			CMatrix<double> * pMATMatrix = MOP.MOPCreateMAT(argv[uiloop + 1]);
			ppMATList[uiloop] = *pMATMatrix;
		}
	}
	catch (CException EXCparam) {
		std::cout << "Error occured during matrix construction\n";
		std::cout << EXCparam;
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

	delete[] ppMATList;

	return 0;
	
}
