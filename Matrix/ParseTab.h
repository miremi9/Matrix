#pragma once
#include "Matrix.h"
#include "CStringOperation.h"

void ParseTab(char * pcContent, CMatrix<double> * pMATparam, unsigned int Nblignes, unsigned int NbColonnes);
void ParseTab(char * pcContent, CMatrix<CComplex>* pMATparam, unsigned int Nblignes, unsigned int NbColonnes);