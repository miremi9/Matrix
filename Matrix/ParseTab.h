#pragma once
#include "Matrix.h"
#include "CStringOperation.h"
/**************************************************************************
 ***** ParseTab                                                       *****
 **************************************************************************
 ***** Input : char * pcContent, CMatrix<double> * pMATparam,         *****
 ***** unsigned int Nblignes, unsigned int NbColonnes                 *****
 ***** precondtion : pcContent is a char * representing a array of    *****
 ***** double with a coherent Nbligne and Nbcolonnes                  *****
 ***** Output : None                                                  *****
 ***** Postcondition : set the value of pMATparam with the array      *****
 ***** values                                                         *****
 **************************************************************************/
void ParseTab(char * pcContent, CMatrix<double> * pMATparam, unsigned int Nblignes, unsigned int NbColonnes);

/**************************************************************************
 ***** ParseTab                                                       *****
 **************************************************************************
 ***** Input : char * pcContent, CMatrix<CCOmplex> * pMATparam,       *****
 ***** unsigned int Nblignes, unsigned int NbColonnes                 *****
 ***** precondtion : pcContent is a char * representing a array of    *****
 ***** CComplex with a coherent Nbligne and Nbcolonnes                *****
 ***** Output : None                                                  *****
 ***** Postcondition : set the value of pMATparam with the array      *****
 ***** values                                                         *****
 **************************************************************************/
void ParseTab(char * pcContent, CMatrix<CComplex>* pMATparam, unsigned int Nblignes, unsigned int NbColonnes);