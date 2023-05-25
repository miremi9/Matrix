#include <iostream>

#include "CParser.h"

#define MAX_ITEM 50


/************************************************************************
***** CParser() *****

***** Input : None *****
***** Precondition: None *****
***** Output: None *****
***** Postconditions : Initializes a new instance of the CParser class. *****
************************************************************************/
CParser::CParser()
{
	ppcPARKeyList = new char*[MAX_ITEM];
	ppcPARValueList = new char*[MAX_ITEM];
	uiNbItem = 0;
};

/************************************************************************
***** CParser(const CParser & PARparam) *****

***** Input : PARparam : Reference to an existing CParser object. *****
***** Precondition: None *****
***** Output: None *****
***** Postconditions : Initializes a new instance of the CParser class *****
***** by copying the contents of the provided *****
***** CParser object. *****
************************************************************************/
CParser::CParser(const CParser & PARparam)
{
	// Copy the number of items
	uiNbItem = PARparam.uiNbItem;

	// Allocate memory for key list
	ppcPARKeyList = new char*[uiNbItem];

	// Allocate memory for value list
	ppcPARValueList = new char*[uiNbItem];

	// Copy the key-value pairs
	for (unsigned int i = 0; i < uiNbItem; i++)
	{
		// Copy the key
		size_t keyLength = strlen(PARparam.ppcPARKeyList[i]) + 1;
		ppcPARKeyList[i] = new char[keyLength];
		strcpy_s(ppcPARKeyList[i], keyLength, PARparam.ppcPARKeyList[i]);

		// Copy the value
		size_t valueLength = strlen(PARparam.ppcPARValueList[i]) + 1;
		ppcPARValueList[i] = new char[valueLength];
		strcpy_s(ppcPARValueList[i], valueLength, PARparam.ppcPARValueList[i]);
	}
}

/************************************************************************
***** CParser(const char * pcFilename) *****

***** Input : pcFilename : Pointer to a null-terminated string *****
***** Precondition: None *****
***** Output: None *****
***** Postconditions : Initializes a new instance of the CParser class *****
***** and reads the contents of the file with *****
***** the provided filename. *****
************************************************************************/
CParser::CParser(const char * pcFileName)
{
	ppcPARKeyList = new char*[MAX_ITEM];
	ppcPARValueList = new char*[MAX_ITEM];
	PARReadFile(pcFileName);
};

/************************************************************************
***** ~CParser() *****

***** Input : None *****
***** Precondition: None *****
***** Output: None *****
***** Postconditions : Destroys the instance of the CParser class. *****
************************************************************************/
CParser::~CParser()
{
	unsigned int uiLoop;
	if (ppcPARKeyList != nullptr)
	{
		for (uiLoop = 0; uiLoop < uiNbItem; uiLoop++)
		{
			if (ppcPARKeyList[uiLoop] != nullptr)
			{
				delete[] ppcPARKeyList[uiLoop];
			}

		}
		delete[] ppcPARKeyList;
	}
	if (ppcPARValueList != nullptr)
	{
		for (uiLoop = 0; uiLoop < uiNbItem; uiLoop++)
		{
			if (ppcPARValueList[uiLoop] != nullptr)
			{
				delete[] ppcPARValueList[uiLoop];
			}
		}
		delete[] ppcPARValueList;
	}
}

/************************************************************************
***** ReadFile(const char * pcPAth) *****

***** Input : pcPath : Pointer to a null-terminated string *****
***** Precondition: None *****
***** Output: None *****
***** Postconditions : Reads the contents of the file with the provided *****
***** path and populates the key-value lists. *****
************************************************************************/
void CParser::PARReadFile(const char * pcFileName)
{
	unsigned int uiLoop;
	for (uiLoop = 0; uiLoop < uiNbItem; uiLoop++)
	{
		if (ppcPARKeyList[uiLoop] != nullptr)
		{
			delete[] ppcPARKeyList[uiLoop];
		}
		if (ppcPARValueList[uiLoop] != nullptr)
		{
			delete[] ppcPARValueList[uiLoop];
		}
	}
	uiNbItem = 0;
	FILE * fptr;
	int err;
	err = fopen_s(&fptr, pcFileName, "r");
	if (err == 0)
	{
		//printf("The file 'crt_fopen_s.c' was opened\n");
	}
	else
	{
		//printf("The file 'crt_fopen_s.c' was not opened\n");
		throw CException(FILE_ERROR, " CParser::PARReadFile : File was not opened");
	}
	// Store the content of the file

	int index = 0;
	int depth;
	//char bufferLine[500];
	char key[50] = "";
	char buffer;
	char value[50] = "";

	do
	{
		index = 0;
		ppcPARKeyList[uiNbItem] = new char[500];
		ppcPARValueList[uiNbItem] = new char[500];
		do
		{			//get VARIABLE_NAME part
			buffer = fgetc(fptr);
			while ((buffer == '\n' || buffer == ' '))
			{
				buffer = fgetc(fptr);
			}
			if (buffer == EOF)
			{
				delete[] ppcPARKeyList[uiNbItem];
				delete[] ppcPARValueList[uiNbItem];
				break;
			}

			ppcPARKeyList[uiNbItem][index] = buffer;
			index += 1;


		} while (buffer != '=');
		if (buffer == EOF)
		{
			break;
		}
		ppcPARKeyList[uiNbItem][index - 1] = '\0';

		index = 0;
		depth = 0;

		do			//get the VALUE part
		{
			if (buffer == EOF)
			{
				break;
			}
			buffer = fgetc(fptr);
			if (buffer == '[')
			{
				depth += 1;
			}
			else if (buffer == ']')
			{
				depth -= 1;
			}
			else
			{
				ppcPARValueList[uiNbItem][index] = buffer;
				index += 1;
			}

		} while (!(buffer == '\n' && depth == 0) && buffer != EOF);

		ppcPARValueList[uiNbItem][index - 1] = '\0';

		uiNbItem += 1;

	} while (buffer != EOF);
	// Close the file
	fclose(fptr);
}

/************************************************************************
***** getValue(const char pcKey[]) *****

***** Input : pcKey : Pointer to a null-terminated string *****
***** Precondition: None *****
***** Output: char* *****
***** Postconditions : Returns a pointer to the value associated with the *****
***** provided key in the key-value list. *****
************************************************************************/
char * CParser::PARgetValue(const char pcKey[]) const
{
	unsigned int uiLoop;
	for (uiLoop = 0; uiLoop < uiNbItem; uiLoop++)
	{
		if (strcmp(ppcPARKeyList[uiLoop], pcKey) == 0)
		{
			return ppcPARValueList[uiLoop];
		}
	};
	throw CException(KEY_ERROR, "CParser::PARgetValue : Key not found");
}