#include <string.h>

#include "CLexicalList.h"


/********************************************************************************
 ***** LexicalList()														*****
 ********************************************************************************
 ***** Input: None															*****
 ***** Precondition: None													*****
 ***** Output: None															*****
 ***** Postconditions: Initializes a new instance of the LexicalList class. *****
 ********************************************************************************/
LexicalList::LexicalList()
{
	uiLELnbKey = 0;
	uiLELnbValue = 0;
	pppcLELListValue = nullptr;
	ppcLELListKey = nullptr;
}

/************************************************************************************
 ***** LexicalList(char * pcText, unsigned int uiNbKey, unsigned int uinbValue) *****
 ************************************************************************************
 ***** Input: pcText - A pointer to a character array representing the text.	*****
 *****		uiNbKey - The number of keys in the LexicalList.					*****
 *****		uinbValue - The number of values in the LexicalList.				*****
 ***** Precondition: None														*****
 ***** Output: None																*****
 ***** Postconditions: Initializes a new instance of the LexicalList class with *****
 ***** the provided text, number of keys, and number of values.					*****
 ************************************************************************************/
LexicalList::LexicalList(char * pcText, unsigned int nbKey, unsigned int uinbValue)
{
	uiLELnbKey = 0;
	uiLELnbValue = 0;
	pppcLELListValue = nullptr;
	ppcLELListKey = nullptr;
	LELAnalyse(pcText,nbKey,uinbValue);
}

/*********************************************************************************
 ***** LexicalList(LexicalList & LELparam)									 *****
 *********************************************************************************
 ***** Input: LELparam - A reference to a LexicalList object.				 *****
 ***** Precondition: None													 *****
 ***** Output: None															 *****
 ***** Postconditions: Initializes a new instance of the LexicalList class,  *****
 ***** copying the contents of the provided LexicalList object.				 *****
 *********************************************************************************/
LexicalList::LexicalList(LexicalList & LELparam)
{
	uiLELnbKey = LELparam.uiLELnbKey;
	uiLELnbValue = LELparam.uiLELnbValue;
	pppcLELListValue = new char **[uiLELnbKey];
	ppcLELListKey = new char *[uiLELnbKey];

	for (unsigned int i = 0; i < uiLELnbKey; i++)
	{
		if (LELparam.pppcLELListValue[i] == nullptr)
		{
			pppcLELListValue[i] = nullptr;
		}
		else
		{
			pppcLELListValue[i] = new char *[uiLELnbValue];
			for (unsigned int j = 0; j < uiLELnbValue; j++)
			{
				if (LELparam.pppcLELListValue[i][j] == nullptr)
				{
					pppcLELListValue[i][j] = nullptr;
				}
				else
				{
					size_t uiSize = strlen(LELparam.pppcLELListValue[i][j]) + 1;
					pppcLELListValue[i][j] = new char[uiSize];
					strcpy_s(pppcLELListValue[i][j], uiSize, LELparam.pppcLELListValue[i][j]);
				}
			}
		}
		if (LELparam.ppcLELListKey[i] == nullptr)
		{
			ppcLELListKey[i] = nullptr;
		}
		else
		{
			size_t uiSize = strlen(LELparam.ppcLELListKey[i]) + 1;
			ppcLELListKey[i] = new char[uiSize];
			strcpy_s(ppcLELListKey[i], uiSize, LELparam.ppcLELListKey[i]);
		}
	}
};

/****************************************************************************
 ***** ~LexicalList()													*****
 ****************************************************************************
 ***** Input: None														*****
 ***** Precondition: None												*****
 ***** Output: None														*****
 ***** Postconditions: Destroys an instance of the LexicalList class,	*****
 ***** releasing any allocated resources.								*****
 ****************************************************************************/
LexicalList::~LexicalList()
{
	LELDelete();
}

/********************************************************************************************
 ***** LELAnalyse(char * pcText, unsigned int uiNbKey, unsigned int uinbValue)			*****
 ********************************************************************************************
 ***** Input: pcText - A pointer to a character array representing the text to analyze. *****
 *****		uiNbKey - The number of keys in the text									*****
 *****		uinbValue - The number of element in the text.								*****
 ***** Precondition: None																*****
 ***** Output: None																		*****
 ***** Postconditions: Analyzes the provided text and initializes the					*****
 ***** LexicalList object with the specified number of keys and values.					*****
 ********************************************************************************************/
void LexicalList::LELAnalyse(char* pcText, unsigned int uinbKey, unsigned int uinbValue)
{
	CStringOperation SOP;
	// Réinitialisation de la liste
	LELDelete();

	uiLELnbKey = uinbKey;
	uiLELnbValue = uinbValue;

	ppcLELListKey = new char*[uiLELnbKey];
	unsigned int uiLoop;

	for (uiLoop = 0; uiLoop < uiLELnbKey; uiLoop++)
	{
		ppcLELListKey[uiLoop] = nullptr;
	}
	pppcLELListValue = new char**[uiLELnbKey];

	// Parcours des lignes
	const char delim[] = ", =\n";
	char* contextText = nullptr;
	char* contextLine = nullptr;
	char * token;
	//unsigned int uiLoop;
	int iNumkey;
	char* pcLine = strtok_s(pcText, "\n", &contextText);

	while (pcLine != nullptr) {
		if (!SOP.isWhiteSpaceString(pcLine))
		{
			contextLine = nullptr;
			token = strtok_s(pcLine, delim, &contextLine);

			while (token != nullptr)
			{
				if (!SOP.isWhiteSpaceString(token))
				{
					//Key
					SOP.removeSpaces(token);
					
					iNumkey = LELGetkey(token);	
					if (iNumkey == -1)
					{
						iNumkey = LELAddkey(token);
					}
					//Value
					token = strtok_s(nullptr, delim, &contextLine);
					SOP.removeSpaces(token);

					LELaddValue(iNumkey, token);
				}
				token = strtok_s(nullptr, delim, &contextLine);
			}
		}
		pcLine = strtok_s(nullptr, "\n", &contextText);
	}
}

/************************************************************************************************************
 ***** LELAddkey(char * pcKey)																			*****
 ************************************************************************************************************
 ***** Input: pcKey - A pointer to a character array representing the key to add.						*****
 ***** Precondition: None																				*****
 ***** Output: Returns an unsigned integer representing the index of the added key in the LexicalList.	*****
 ***** Postconditions: Adds the specified key to the LexicalList and updates the index.					*****
 ************************************************************************************************************/
unsigned int LexicalList::LELAddkey(char * pcKey)
{
	unsigned int uiLoop;
	uiLoop = 0;
	unsigned int key;

	//find the right place
	while (uiLoop <uiLELnbKey && ppcLELListKey[uiLoop] !=nullptr)
	{
		uiLoop++;
	}
	if (uiLoop == uiLELnbKey) //if it s full
	{
		throw CException(VALUE_ERROR,"LexicalList::LELAddke : Too many value for key");
	}
	key = uiLoop;
	ppcLELListKey[key] = new char[strlen(pcKey)+1];
	pppcLELListValue[key] =  new char*[uiLELnbValue];

	for (uiLoop = 0; uiLoop < uiLELnbValue; uiLoop++)
	{
		pppcLELListValue[key][uiLoop] = nullptr;
	}
	strcpy_s(ppcLELListKey[key], strlen(pcKey) + 1, pcKey);

	return key;
}


/********************************************************************************************************
 ***** LELGetkey(char * pcKey)																		*****
 ********************************************************************************************************
 ***** Input: pcKey - A pointer to a character array representing the key.							*****
 ***** Precondition: None																			*****
 ***** Output: Returns an integer representing the index of the specified key in the LexicalList.	*****
 ***** Postconditions: None																			*****
 ********************************************************************************************************/
int LexicalList::LELGetkey(char * pcKey) const
{
	unsigned int uiLoop;
	uiLoop = 0;

	//find the right place
	while (ppcLELListKey[uiLoop] != nullptr)
	{
		if (strcmp(ppcLELListKey[uiLoop],pcKey)==0)
		{
			return uiLoop;
		}
		uiLoop++;
	}
	return -1;
}

/************************************************************************************************
 ***** LELaddValue(unsigned int iKey, char * Value)											*****
 ************************************************************************************************
 ***** Input: iKey - An unsigned integer representing the index of the key.					*****
 *****		Value - A pointer to a character array representing the value to add.			*****
 ***** Precondition: None																	*****
 ***** Output: None																			*****
 ***** Postconditions: Adds the specified value to the LexicalList at the given key index.	*****
 ************************************************************************************************/
void LexicalList::LELaddValue(unsigned int iKey, char * pcValue)
{
	if (iKey<0 || iKey >uiLELnbKey)
	{
		throw CException(KEY_ERROR,"LexicalList::LELaddValue : the key isn't valide");
	}
	unsigned int uiLoop;
	uiLoop = 0;
	unsigned int uiNumValue;

	//find the right place
	while (uiLoop < uiLELnbValue && pppcLELListValue[iKey][uiLoop] != nullptr)
	{
		uiLoop++;
	}
	if (uiLoop == uiLELnbValue) //if it s full
	{
		throw CException(VALUE_ERROR," LexicalList::LELaddValue : More key input than expected");
	}

	uiNumValue = uiLoop;
	pppcLELListValue[iKey][uiNumValue] = new char[strlen(pcValue) + 1];
	strcpy_s(pppcLELListValue[iKey][uiNumValue], strlen(pcValue) + 1, pcValue);
}

/****************************************************************************************
 ***** LELGetValue(const char * pcKey, int numValue)								*****
 ****************************************************************************************
 ***** Input: pcKey - A pointer to a constant character array representing the key. *****
 *****		numValue - The index of the value to retrieve.							*****
 ***** Precondition: None															*****
 ***** Output: Returns a pointer to a character array representing the value		*****
 ***** corresponding to the specified key and value index.							*****
 ***** Postconditions: None															*****
 ****************************************************************************************/
char * LexicalList::LELGetValue(const char * pcKey, int numValue) const
{
	unsigned int uiLoop;
	for (uiLoop = 0; uiLoop < uiLELnbKey; uiLoop++)
	{
		if (strcmp(ppcLELListKey[uiLoop], pcKey) == 0)
		{
			return pppcLELListValue[uiLoop][numValue];
		}
	}
	throw CException(KEY_ERROR,"LexicalList::LELGetValue : key not found");
}

/************************************************************************************************
 ***** operator=(LexicalList LELparam)														*****
 ************************************************************************************************
 ***** Input: LexicalList LELparam															*****
 ***** Precondition: None																	*****
 ***** Output: None																			*****
 ***** Postconditions: new LexicalList object similar as the param one						*****
 ************************************************************************************************/
void LexicalList::operator=(LexicalList LELparam)
{
	LELDelete();

	uiLELnbKey = LELparam.uiLELnbKey;
	uiLELnbValue = LELparam.uiLELnbValue;
	pppcLELListValue = new char **[uiLELnbKey];
	ppcLELListKey = new char *[uiLELnbKey];

	for (unsigned int i = 0; i < uiLELnbKey; i++)
	{
		if (LELparam.pppcLELListValue[i] == nullptr)
		{
			pppcLELListValue[i] = nullptr;
		}
		else
		{
			pppcLELListValue[i] = new char *[uiLELnbValue];
			for (unsigned int j = 0; j < uiLELnbValue; j++)
			{
				if (LELparam.pppcLELListValue[i][j] == nullptr)
				{
					pppcLELListValue[i][j] = nullptr;
				}
				else
				{
					size_t uiSize = strlen(LELparam.pppcLELListValue[i][j]) + 1;
					pppcLELListValue[i][j] = new char[uiSize];
					strcpy_s(pppcLELListValue[i][j], uiSize, LELparam.pppcLELListValue[i][j]);
				}
			}
		}
		if (LELparam.ppcLELListKey[i] == nullptr)
		{
			ppcLELListKey[i] = nullptr;
		}
		else
		{
			size_t uiSize = strlen(LELparam.ppcLELListKey[i]) + 1;
			ppcLELListKey[i] = new char[uiSize];
			strcpy_s(ppcLELListKey[i], uiSize, LELparam.ppcLELListKey[i]);
		}
	}
}

/************************************************************************************************
 ***** LELDelete() CLexicalList delete tools (factor code)									*****
 ************************************************************************************************
 ***** Input: None																			*****
 ***** Precondition: None																	*****
 ***** Output: None																			*****
 ***** Postconditions: Object destruction & memory management code							*****
 ************************************************************************************************/
void LexicalList::LELDelete()
{
	if (pppcLELListValue != nullptr)
	{
		for (unsigned int i = 0; i < uiLELnbKey; i++)
		{
			if (pppcLELListValue[i] != nullptr)
			{
				for (unsigned int j = 0; j < uiLELnbValue; j++)
				{
					if (pppcLELListValue[i][j] != nullptr)
					{
						delete[] pppcLELListValue[i][j];
					}
				}
				delete[] pppcLELListValue[i];
			}
		}
		delete[] pppcLELListValue;
	}
	if (ppcLELListKey != nullptr)
	{
		for (unsigned int i = 0; i < uiLELnbKey; i++)
		{
			if (ppcLELListKey[i] != nullptr)
			{
				delete[] ppcLELListKey[i];
			}
		}
		delete[] ppcLELListKey;
	}
	ppcLELListKey = nullptr;
	pppcLELListValue = nullptr;
	uiLELnbKey = 0;
	uiLELnbValue = 0;
}