#ifndef C_EXCEPTION_H
#define C_EXCEPTION_H

#define FILE_ERROR 1
#define FILE_CONTENT_ERROR 2
#define VALUE_ERROR 3
#define TYPE_ERROR 4
#define ID_ERROR 5
#define KEY_ERROR 6
#define OBJECT_ERROR 7


class CException {
//Attributs
private :

	int iEXCvalue;

	char * pcEXCMessage;

//Constructors & Destructors
public :
	/**********************************************************************************************
	 ***** Default class constructor                                                          *****
	 **********************************************************************************************
	 ***** Input : None                                                                       *****
	 ***** Precondition: None                                                                 *****
	 ***** Output:  None                                                                      *****
	 ***** Postcondition : Create an CException Object with default value 0                   *****
	 **********************************************************************************************/
	CException();
	
	/**********************************************************************************************
	 ***** Class constructor                                                                  *****
	 **********************************************************************************************
	 ***** Input : unsigned int                                                               *****
	 ***** Precondition: None                                                                 *****
	 ***** Output:  None                                                                      *****
	 ***** Postcondition : Create an CException Object with inputed value                     *****
	 **********************************************************************************************/
	CException(int iValue);


	/**********************************************************************************************
	 ***** Class constructor                                                                  *****
	 **********************************************************************************************
	 ***** Input : unsigned int ,char * message                                               *****
	 ***** Precondition: None                                                                 *****
	 ***** Output:  None                                                                      *****
	 ***** Postcondition : Create an CException Object with inputed value                     *****
	 **********************************************************************************************/
	CException(int iValue, const char * pcMessage);
	
	/************************************************************************
	*****Destructor | ~CException()                                     *****
	*****Input : None                                                   *****
	*****Precondition : None                                            *****
	*****Output : None                                                  *****
	*****Postconditions : Attribut of this are deleted                  *****
	************************************************************************/
	~CException();
	
//Methods
public :

	/************************************************************************
	*****EXCsetValue()                                                  *****
	*****Input :  int ivalue                                            *****
	*****Precondition : ivalue is in the range of error set by the class*****
	*****                                                               *****
	*****Output : void                                                  *****
	*****Postconditions : change the value of this                      *****
	************************************************************************/
	void EXCsetValue( int ivalue) { iEXCvalue = ivalue; };

	/************************************************************************
	*****EXCgetValue()                                                  *****
	*****Input : None                                                   *****
	*****Precondition : None                                            *****
	*****Output : unsigned int                                          *****
	*****Postconditions : None                                          *****
	************************************************************************/
	unsigned int EXCgetValue() const { return iEXCvalue; };

	/************************************************************************
	*****EXCPrintException()                                            *****
	*****Input : None                                                   *****
	*****Precondition : None                                            *****
	*****Output : void                                                  *****
	*****Postconditions : None                                          *****
	************************************************************************/
	void EXCPrintException();

};

#endif