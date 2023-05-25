#include "test.h"


void testOPmatrix()
{
	CMatrixOperation<double> op;
	CMatrix<double> * MAT = op.MOPCreateMAT("exemplefile.txt");
	op.MOPprintMAT(*MAT);
}