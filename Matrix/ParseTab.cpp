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

	line = strtok_s(pcContent, "\n", &pTextEnd);
	while (op.isWhiteSpaceString(line))
	{
		line = strtok_s(nullptr, "\n", &pTextEnd);
	}

	dValue = strtod(line, &pLineEnd);
	for (unsigned int uiCol = 0; uiCol < Nblignes; uiCol++)		//For each matrix slot, read associate value
	{
		dValue = strtod(line, &pLineEnd);
		for (unsigned int uiline = 0; uiline < NbColonnes; uiline++)
		{
			pMATparam->MATSetValue(uiCol, uiline, dValue);
			dValue = strtod(pLineEnd, NULL);
		}
		line = strtok_s(nullptr, "\n", &pTextEnd);
		while (op.isWhiteSpaceString(line))
		{
			line = strtok_s(nullptr, "\n", &pTextEnd);
		}
	}

}