#ifndef C_PARSER_H
#define C_PARSER_H

#include "CException.h"

#define FILE_ERROR 1
#define KEY_ERROR 6


class CParser
{
	/*Attributes*/
	private:

		char ** ppcPARKeyList;			//string list of Key

		char ** ppcPARValueList;		//string list of value associate to Key

		unsigned int uiNbItem;			//list item counter

	/*Constructors & Destructors*/
	public:
		/************************************************************************
		*****Constructor | CParser()                                        *****
		*****Input : None                                                   *****
		*****Precondition : None                                            *****
		*****Output : None                                                  *****
		*****Postconditions : this is initialized                           *****
		************************************************************************/
		CParser();

		/************************************************************************
		*****Constructor | CParser()                                        *****
		*****Input : const CParser & PARparam                               *****
		*****Precondition : PARparam is initialized                         *****
		*****Output : None                                                  *****
		*****Postconditions : this have the same value as PARparam          *****
		************************************************************************/
		CParser(const CParser & PARparam);

		/************************************************************************
		*****Constructor | CParser()                                        *****
		*****Input : const char * pcFilename                                *****
		*****Precondition : pcFilename is the name of an existing file throw*****
		***** CException otherwise                                          *****
		*****Output : None                                                  *****
		*****Postconditions : this is initialized with values of the file   *****
		************************************************************************/
		CParser(const char * pcFilename);

		/************************************************************************
		*****Destructor  | ~CParser()                                       *****
		*****Input : None                                                   *****
		*****Precondition : None                                            *****
		*****Output : None                                                  *****
		*****Postconditions : delete all the attribut of this               *****
		************************************************************************/
		~CParser();

	/*Methods*/
	public:
		/************************************************************************
		*****PARgetValue()                                                  *****
		*****Input : const char pcKey[]                                     *****
		*****Precondition : pcKey is a value of Parser throw CException othe*****
		*****rwise                                                          *****
		*****Output : char*                                                 *****
		*****Postconditions : return the value associed to pcKey            *****
		************************************************************************/
		char * PARgetValue(const char pcKey[]) const;

		/************************************************************************
		*****PARReadFile()                                                  *****
		*****Input : const char * pcPAth                                    *****
		*****Precondition : pcPath is the name of an existing file throw CEx*****
		*****ception otherwise                                              *****
		*****Output : void                                                  *****
		*****Postconditions : this as the value setting by the file         *****
		************************************************************************/
		void PARReadFile(const char * pcPAth);
};

#endif	//C_PARSER_H