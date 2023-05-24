#ifndef C_EXCEPTION_H
#define C_EXCEPTION_H

#define DIMENSION_ERROR 1
#define TYPE_ERROR 2
#define FILE_ERROR 3
#define VALUE_ERROR 4
#define FILE_CONTENT_ERROR 5


class CException {
/*Attributs*/
private :
	unsigned int uiEXCvalue;		//Exception code value

/*Constructors & Destructors*/
public :

	/**********************************************************************************************
	 ***** CException() Default class constructor											  *****
	 **********************************************************************************************
	 ***** Input : None                                                                       *****
	 ***** Precondition: None                                                                 *****
	 ***** Output:  None                                                                      *****
	 ***** Postcondition : Create an CException Object with default value 0                   *****
	 **********************************************************************************************/
	CException() { uiEXCvalue = 0; };
	
	/**********************************************************************************************
	 ***** CException() Class constructor                                                     *****
	 **********************************************************************************************
	 ***** Input : unsigned int                                                               *****
	 ***** Precondition: None                                                                 *****
	 ***** Output:  None                                                                      *****
	 ***** Postcondition : Create an CException Object with inputed value                     *****
	 **********************************************************************************************/
	CException(unsigned int value) { uiEXCvalue = value; };
	
	~CException() {};
	
/*Methods*/
public :

	/**********************************************************************************************
	 ***** EXCReadValue() Read CException value                                               *****
	 **********************************************************************************************
	 ***** Input : None                                                                       *****
	 ***** Precondition: None                                                                 *****
	 ***** Output: Exception value                                                            *****
	 ***** Postcondition : return exception value                                             *****
	 **********************************************************************************************/
	unsigned int EXCReadValue() { return uiEXCvalue; };
	
	/**********************************************************************************************
	 ***** EXCEditValue() Edit CException value                                               *****
	 **********************************************************************************************
	 ***** Input : unsigned int                                                               *****
	 ***** Precondition: None                                                                 *****
	 ***** Output:  None                                                                      *****
	 ***** Postcondition : edit CException value with the inputed value                       *****
	 **********************************************************************************************/
	void EXCEditValue(unsigned int value) { uiEXCvalue = value; };

	/**********************************************************************************************
	 ***** EXCPrintException() Print Exception value and details                              *****
	 **********************************************************************************************
	 ***** Input : None                                                                       *****
	 ***** Precondition: None                                                                 *****
	 ***** Output:  None                                                                      *****
	 ***** Postcondition : Print text message of exception code and details                   *****
	 **********************************************************************************************/
	void EXCPrintException();
};

#endif