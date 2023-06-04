#ifndef C_LEXICAL_LIST_H
#define C_LEXICAL_LIST_H

#include "CException.h"
#include "CStringOperation.h"

#define VALUE_ERROR 3
#define KEY_ERROR 6


class LexicalList
{
	/*Attributs*/
	private:

		char *** pppcLELListValue;		//list of string list value

		char ** ppcLELListKey;			//string list of Key

		unsigned int uiLELnbKey;		//key counter

		unsigned int uiLELnbValue;		//value counter

	/*Constructors & Destructors*/
	public:

		/********************************************************************************
		 ***** LexicalList()														*****
		 ********************************************************************************
		 ***** Input: None															*****
		 ***** Precondition: None													*****
		 ***** Output: None															*****
		 ***** Postconditions: Initializes a new instance of the LexicalList class. *****
		 ********************************************************************************/
		LexicalList();

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
		LexicalList(char * pcText,unsigned int uiNbKey,unsigned int uinbValue);

		/*********************************************************************************
		 ***** LexicalList(LexicalList & LELparam)									 *****
		 *********************************************************************************
		 ***** Input: LELparam - A reference to a LexicalList object.				 *****
		 ***** Precondition: None													 *****
		 ***** Output: None															 *****
		 ***** Postconditions: Initializes a new instance of the LexicalList class,  *****
		 ***** copying the contents of the provided LexicalList object.				 *****
		 *********************************************************************************/
		LexicalList(LexicalList & LELparam);

		/****************************************************************************
		 ***** ~LexicalList()													*****
		 ****************************************************************************
		 ***** Input: None														*****
		 ***** Precondition: None												*****
		 ***** Output: None														*****
		 ***** Postconditions: Destroys an instance of the LexicalList class,	*****
		 ***** releasing any allocated resources.								*****
		 ****************************************************************************/
		~LexicalList(); 

	/*Methods*/
	public:

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
		void LELAnalyse(char * pcText,unsigned int uiNbKey,unsigned int uinbValue);

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
		char * LELGetValue(const char * pcKey, int numValue) const;

		/********************************************************************************************************
		 ***** LELGetkey(char * pcKey)																		*****
		 ********************************************************************************************************
		 ***** Input: pcKey - A pointer to a character array representing the key.							*****
		 ***** Precondition: None																			*****
		 ***** Output: Returns an integer representing the index of the specified key in the LexicalList.	*****
		 ***** Postconditions: None																			*****
		 ********************************************************************************************************/
		int LELGetkey(char * pcKey) const;

		/************************************************************************************************************
		 ***** LELAddkey(char * pcKey)																			*****
		 ************************************************************************************************************
		 ***** Input: pcKey - A pointer to a character array representing the key to add.						*****
		 ***** Precondition: None																				*****
		 ***** Output: Returns an unsigned integer representing the index of the added key in the LexicalList.	*****
		 ***** Postconditions: Adds the specified key to the LexicalList and updates the index.					*****
		 ************************************************************************************************************/
		unsigned int LELAddkey(char *pcKey);

		/************************************************************************************************
		 ***** LELaddValue(unsigned int iKey, char * Value)											*****
		 ************************************************************************************************
		 ***** Input: iKey - An unsigned integer representing the index of the key.					*****
		 *****		Value - A pointer to a character array representing the value to add.			*****
		 ***** Precondition: None																	*****
		 ***** Output: None																			*****
		 ***** Postconditions: Adds the specified value to the LexicalList at the given key index.	*****
		 ************************************************************************************************/
		void LELaddValue(unsigned int iKey, char * Value);

		/************************************************************************************************
		 ***** operator=(LexicalList LELparam)														*****
		 ************************************************************************************************
		 ***** Input: LexicalList LELparam															*****
		 ***** Precondition: None																	*****
		 ***** Output: None																			*****
		 ***** Postconditions: new LexicalList object similar as the param one						*****
		 ************************************************************************************************/
		void operator=(LexicalList LELparam);

	private :
		/************************************************************************************************
		 ***** LELDelete() CLexicalList delete tools (factor code)									*****
		 ************************************************************************************************
		 ***** Input: None																			*****
		 ***** Precondition: None																	*****
		 ***** Output: None																			*****
		 ***** Postconditions: Object destruction & memory management code							*****
		 ************************************************************************************************/
		void LELDelete();
};

#endif	//C_LEXICAL_LIST_H