#ifndef C_STRING_OPERATION_H
#define C_STRING_OPERATION_H	

#include "CException.h"
class CStringOperation {
	public:

		/*************************************************************************
		 ***** isWhiteSpaceString(const char * str)							 *****
		 *************************************************************************
		 ***** Input : str : Pointer to a null-terminated string			 *****
		 ***** Precondition: None											 *****
		 ***** Output: bool													 *****
		 ***** Postconditions : Returns true if the provided string consists *****
		 ***** solely of white spaces, false otherwise.						 *****
		 *************************************************************************/
		bool isWhiteSpaceString(const char * str);

		/************************************************************************
		 ***** trim(char* str)												*****
		 ************************************************************************
		 ***** Input : str : Pointer to a null-terminated string			*****
		 ***** Precondition: None											*****
		 ***** Output: None													*****
		 ***** Postconditions : Modifies the provided string by removing	*****
		 ***** leading and trailing white spaces.							*****
		 ************************************************************************/
		void trim(char* str);

		/************************************************************************
		 ***** removeSpaces(char *str)										*****
		 ************************************************************************
		 ***** Input : str : Pointer to a null-terminated string			*****
		 ***** Precondition: None											*****
		 ***** Output: None													*****
		 ***** Postconditions : Modifies the provided string by removing	*****
		 ***** all white spaces from it.									*****
		 ************************************************************************/
		void removeSpaces(char *str);

		/****************************************************************************
		 ***** stoi(const char *s)												*****
		 ****************************************************************************
		 ***** Input : s : Pointer to a null-terminated string					*****
		 ***** Precondition: None												*****
		 ***** Output: long														*****
		 ***** Postconditions : Converts the provided string to a long integer	*****
		 ***** and returns the result.											*****
		 ****************************************************************************/
		long stoi(const char *s);

};

#endif