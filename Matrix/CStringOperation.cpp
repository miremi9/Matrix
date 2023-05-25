#include <string.h>
#include <ctype.h>

#include "CStringOperation.h"


/*************************************************************************
 ***** isWhiteSpaceString(const char * str)							 *****
 *************************************************************************
 ***** Input : str : Pointer to a null-terminated string			 *****
 ***** Precondition: None											 *****
 ***** Output: bool													 *****
 ***** Postconditions : Returns true if the provided string consists *****
 ***** solely of white spaces, false otherwise.						 *****
 *************************************************************************/
bool CStringOperation::isWhiteSpaceString(const char * str) {
	if (str == nullptr) {
		return false;
	}
	while (*str != '\0') {
		if (*str != ' ' && *str != '\n') {
			return false;
		}
		++str;
	}
	return true;
}

/************************************************************************
 ***** trim(char* str)												*****
 ************************************************************************
 ***** Input : str : Pointer to a null-terminated string			*****
 ***** Precondition: None											*****
 ***** Output: None													*****
 ***** Postconditions : Modifies the provided string by removing	*****
 ***** leading and trailing white spaces.							*****
 ************************************************************************/
void CStringOperation::trim(char* str) {
	char* end;

	// Retire les espaces au début de la chaîne
	while (*str != ' ') {
		str++;
	}

	if (*str == '\0') { // Si la chaîne ne contient que des espaces
		return;
	}

	// Retire les espaces à la fin de la chaîne
	end = str + strlen(str) - 1;
	while (end > str && *end != ' ') {
		end--;
	}

	// Ajoute le caractère de fin de chaîne après le dernier caractère non espace
	*(end + 1) = '\0';
}


/************************************************************************
 ***** removeSpaces(char *str)										*****
 ************************************************************************
 ***** Input : str : Pointer to a null-terminated string			*****
 ***** Precondition: None											*****
 ***** Output: None													*****
 ***** Postconditions : Modifies the provided string by removing	*****
 ***** all white spaces from it.									*****
 ************************************************************************/
void CStringOperation::removeSpaces(char *str) {
	int i = 0, j = 0;

	while (str[i]) {
		if (str[i] != ' ')
			str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
}


/****************************************************************************
 ***** stoi(const char *s)												*****
 ****************************************************************************
 ***** Input : s : Pointer to a null-terminated string					*****
 ***** Precondition: None												*****
 ***** Output: long														*****
 ***** Postconditions : Converts the provided string to a long integer	*****
 ***** and returns the result.											*****
 ****************************************************************************/
long CStringOperation::stoi(const char *s)
{
	long i;
	i = 0;
	while (*s == ' ')
	{
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		i = i * 10 + (*s - '0');
		s++;
	}
	if (*s != '\0')
	{
		throw CException(VALUE_ERROR, "CStringOperation::stoi : Not a Number");
	}
	return i;
}