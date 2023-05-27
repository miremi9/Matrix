#include "ParseTab.h"

void ParseTab(char * pcContent, CMatrix<double> * pMATparam,unsigned int Nblignes, unsigned int NbColonnes)
{
	CStringOperation op;
	unsigned int index = 0;
	while (pcContent[index] == '\n' || pcContent[index] == ' ')
	{
		index++;
	}
	double dValue;
	char * line;
	char* pLineEnd;
	char * pTextEnd;
	char * token;
	line = strtok_s(pcContent, "\n", &pTextEnd);
	while (op.isWhiteSpaceString(line))
	{
		line = strtok_s(nullptr, "\n", &pTextEnd);
	}

	//token = strtok_s(line, " " ,&pLineEnd);
	for (unsigned int uiCol = 0; uiCol < Nblignes; uiCol++)		//For each matrix slot, read associate value
	{
		token = strtok_s(line," ", &pLineEnd);
		for (unsigned int uiline = 0; uiline < NbColonnes; uiline++)
		{
			
			dValue = atof(token);
			pMATparam->MATSetValue(uiCol, uiline, dValue);

			token = strtok_s(NULL," ",&pLineEnd);
		}
		line = strtok_s(nullptr, "\n", &pTextEnd);
		while (op.isWhiteSpaceString(line))
		{
			line = strtok_s(nullptr, "\n", &pTextEnd);
		}
	}
}

void ParseTab(char * pcContent, CMatrix<CComplex>* pMATparam, unsigned int Nblignes, unsigned int NbColonnes)
{
	CStringOperation op;
	unsigned int index = 0;
	while (pcContent[index] == '\n' || pcContent[index] == ' ')
	{
		index++;
	}
	CComplex dValue;
	char * line;
	char* pLineEnd;
	char * pTextEnd;
	char * token;
	double drealPart;
	double dimagiPart;
	line = strtok_s(pcContent, "\n", &pTextEnd);
	while (op.isWhiteSpaceString(line))
	{
		line = strtok_s(nullptr, "\n", &pTextEnd);
	}

	//token = strtok_s(line, " " ,&pLineEnd);
	for (unsigned int uiCol = 0; uiCol < Nblignes; uiCol++)		//For each matrix slot, read associate value
	{
		token = strtok_s(line, " ", &pLineEnd);
		for (unsigned int uiline = 0; uiline < NbColonnes; uiline++)
		{
			op.getComplex(token, drealPart, dimagiPart);

			dValue = CComplex(drealPart, dimagiPart);
			pMATparam->MATSetValue(uiCol, uiline, dValue);

			token = strtok_s(NULL, " ", &pLineEnd);
		}
		line = strtok_s(nullptr, "\n", &pTextEnd);
		while (op.isWhiteSpaceString(line))
		{
			line = strtok_s(nullptr, "\n", &pTextEnd);
		}
	}
}