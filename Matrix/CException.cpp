#include <iostream>

#include "CException.h"


/**********************************************************************************************
 ***** EXCPrintException() Print Exception value and details                              *****
 **********************************************************************************************
 ***** Input : None                                                                       *****
 ***** Precondition: None                                                                 *****
 ***** Output:  None                                                                      *****
 ***** Postcondition : Print text message of exception code and details                   *****
 **********************************************************************************************/
void CException::EXCPrintException() {

	std::cout << "Exception number " << EXCReadValue() << " : ";
	if (EXCReadValue() == 0)
	{
		std::cout << "CException value Error\n";
		std::cout << "Make sure to set a correct value for CException value";
	}
	if (EXCReadValue() == 1)
	{
		std::cout << "Dimension error\n";
		std::cout << "Make sure row and colum number are correctly define";
	}
	if (EXCReadValue() == 2)
	{
		std::cout << "Type Error\n";
		std::cout << "Make sure to use correct type (Implemented type : double)";
	}
	if (EXCReadValue() == 3)
	{
		std::cout << "File Error\n";
		std::cout << "Make sure your file exist with correct name & place";
	}
	if (EXCReadValue() == 4)
	{
		std::cout << "Value Error\n";
		std::cout << "Make sure inputed Value match with matrix methods";
	}
	if (EXCReadValue() == 5)
	{
		std::cout << "File Content Error\n";
		std::cout << "Make sure your file respect syntaxe and containt enought/correct element";
	}
	if (EXCReadValue() > 5 || EXCReadValue()<1 )
	{
		std::cout << "CException Error\n";
		std::cout << "CException Value Error not implemented";
	}

	std::cout << std::endl;
	exit(-1);
}