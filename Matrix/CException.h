#ifndef C_EXCEPTION_H
#define C_EXCEPTION_H

#include <iostream>


class CException {
	//Attributes
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

		/**********************************************************************************************
		 ***** Class copie constructor                                                            *****
		 **********************************************************************************************
		 ***** Input : CException EXCparam			                                              *****
		 ***** Precondition: None                                                                 *****
		 ***** Output:  None                                                                      *****
		 ***** Postcondition : Create an CException Object with copied value from inputed one     *****
		 **********************************************************************************************/
		CException(const CException & EXCparam);
	
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
		***** EXCsetValue()                                                  *****
		*****Input :  int ivalue                                            *****
		*****Precondition : ivalue is in the range of error set by the class*****
		*****                                                               *****
		*****Output : void                                                  *****
		*****Postconditions : change the value of this                      *****
		************************************************************************/
		void EXCsetValue( int ivalue) { iEXCvalue = ivalue; };

		/************************************************************************
		***** EXCgetValue()                                                 *****
		*************************************************************************
		*****Input : None                                                   *****
		*****Precondition : None                                            *****
		*****Output : unsigned int                                          *****
		*****Postconditions : None                                          *****
		************************************************************************/
		unsigned int EXCgetValue() const { return iEXCvalue; };

		/**********************************************************************************************
		 ***** CException operator=                                                               *****
		 **********************************************************************************************
		 ***** Input : CException EXCparam			                                              *****
		 ***** Precondition: None                                                                 *****
		 ***** Output:  None                                                                      *****
		 ***** Postcondition : return copie CException										      *****
		 **********************************************************************************************/
		CException & operator=(const CException & EXCparam);

		/**********************************************************************************************
		 ***** CException operator<<	                                                          *****
		 **********************************************************************************************
		 ***** Input : ostream os, CException EXCparam			                                  *****
		 ***** Precondition: None                                                                 *****
		 ***** Output:  None                                                                      *****
		 ***** Postcondition : print CExeption values in stream								      *****
		 **********************************************************************************************/
		friend std::ostream & operator<<(std::ostream & os, const CException & exception);
};

#endif	//C_EXCEPTION_H