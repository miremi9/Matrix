
#include <iostream>
#include "CException.h"
/**********************************************************************************************
 ***** Default class constructor                                                          *****
 **********************************************************************************************
 ***** Input : None                                                                       *****
 ***** Precondition: None                                                                 *****
 ***** Output:  None                                                                      *****
 ***** Postcondition : Create an CException Object with default value 0                   *****
 **********************************************************************************************/
CException::CException() {
	iEXCvalue = 0;
	pcEXCMessage = nullptr;
}

/**********************************************************************************************
 ***** Class constructor                                                                  *****
 **********************************************************************************************
 ***** Input : unsigned int                                                               *****
 ***** Precondition: None                                                                 *****
 ***** Output:  None                                                                      *****
 ***** Postcondition : Create an CException Object with inputed value                     *****
 **********************************************************************************************/
CException::CException( int value) {
	iEXCvalue = value;
	pcEXCMessage = nullptr;
}

/**********************************************************************************************
 ***** Class constructor                                                                  *****
 **********************************************************************************************
 ***** Input : unsigned int ,char * message                                               *****
 ***** Precondition: None                                                                 *****
 ***** Output:  None                                                                      *****
 ***** Postcondition : Create an CException Object with inputed value                     *****
 **********************************************************************************************/
CException::CException(int value, const char * pcMessage) {
	iEXCvalue = value;
	pcEXCMessage = new char[strlen(pcMessage) + 1];
	strcpy_s(pcEXCMessage, strlen(pcMessage) + 1, pcMessage);
}

/************************************************************************
*****Destructor | ~CException()                                     *****
*****Input : None                                                   *****
*****Precondition : None                                            *****
*****Output : None                                                  *****
*****Postconditions : Attribut of this are deleted                  *****
************************************************************************/
CException::~CException()
{
	if (pcEXCMessage)
	{
		delete pcEXCMessage;
	}
}

/**********************************************************************************************
 ***** Print Exception value and details                                                  *****
 **********************************************************************************************
 ***** Input : None                                                                       *****
 ***** Precondition: None                                                                 *****
 ***** Output:  None                                                                      *****
 ***** Postcondition : Print text message of exception code and details                   *****
 **********************************************************************************************/
void CException::EXCPrintException() {

		std::cout << "Exception number " << EXCgetValue() << " : ";
		if (EXCgetValue() == 0)
		{
			std::cout << "CException value Error\n";
			std::cout << "Make sure to get a correct value for CException value\n";
		}
		else if (EXCgetValue() == FILE_ERROR)
		{
			std::cout << "File Error\n";
			std::cout << "Make sure your file exist with correct name & place\n";
		}
		else if (EXCgetValue() == FILE_CONTENT_ERROR)
		{
			std::cout << "File Content Error\n";
			std::cout << "Make sure your file respect syntaxe and containt enought/correct element\n";
		}
		else if (EXCgetValue() == VALUE_ERROR)
		{
			std::cout << "Value Error\n";
			std::cout << "Make sure inputed Value match with matrix methods\n";
		}
		else if (EXCgetValue() == TYPE_ERROR)
		{
			std::cout << "Type Error\n";
			std::cout << "Make sure to use correct type (Implemented type : double)\n";
		}
		else if (EXCgetValue() == ID_ERROR)
		{
			std::cout << "ID Error\n";
			std::cout << "Make sure to use correct ID which not already exist\n";
		}
		else if (EXCgetValue() == KEY_ERROR)
		{
			std::cout << "Key Error\n";
			std::cout << "The key was not found\n";
		}
		else 
		{
			std::cout << "CException Error\n";
			std::cout << "CException Value Error not implemented\n";
		}


	if (pcEXCMessage)
	{
		std::cout << pcEXCMessage;
	}
	std::cout << std::endl;
	exit(-1);
}