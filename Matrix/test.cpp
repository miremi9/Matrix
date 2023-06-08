#include "test.h"


void testOPmatrix()
{
	//CMatrix<double> mat(2, 2);
	//std::cout << mat << std::endl;
	
	CMatrixOperation<double> op;
	CMatrix<double> * MAT = op.MOPCreateMAT("exemplefile.txt");
	std::cout << *MAT;

	CMatrixOperation<CComplex> op2;
	CMatrix<CComplex> * MAT2 = op2.MOPCreateMAT("exemplefileComplexe.txt");
	std::cout << *MAT2;
}

void testComplexe() 
{
	// Test de constructeurs et d'acc�s
	CComplex complex1;  // Constructeur par d�faut
	std::cout << "Complex1: " << complex1;
	std::cout << "Attendu : 0 + 0i\n";

	CComplex complex2(3.5, -2.1);  // Constructeur avec parties r�elle et imaginaire sp�cifi�es
	std::cout << "Complex2: " << complex2;
	std::cout << "Attendu : 3.5 - 2.1i\n";

	CComplex complex3(4.2);  // Constructeur avec partie r�elle sp�cifi�e (partie imaginaire par d�faut � 0)
	std::cout << "Complex3: " << complex3;
	std::cout << "Attendu : 4.2 + 0i\n";

	// Test des op�rations math�matiques
	CComplex sum = complex1 + complex2;
	std::cout << "Sum: " << sum;
	std::cout << "Attendu : 3.5 - 2.1i\n";

	CComplex diff = complex2 - complex3;
	std::cout << "Difference: " << diff;
	std::cout << "Attendu : -0.7 - 2.1i\n";

	CComplex minus = -complex2;
	std::cout << "minus: " << minus;
	std::cout << "Attendu : -3.5 + 2.1i\n";

	CComplex product = complex2 * complex3;
	std::cout << "Product: " << product;
	std::cout << "Attendu : 14.7 - 8.82i\n";

	product += product;
	std::cout << "Product: " << product;
	std::cout << "Attendu : 29,4 - 17,64\n";

	product -= product;
	std::cout << "Product: " << product;
	std::cout << "Attendu : 0 + 0i\n";

	CComplex quotient = complex3 / complex2;
	std::cout << "Quotient: " << quotient;
	std::cout << "Attendu : 0,88  + 0,529i\n";

	// Modification des parties r�elle et imaginaire
	sum.COMsetReal(2.0);
	sum.COMsetImaginary(-1.5);
	std::cout << "Modified Sum: " << sum;
	std::cout << "Attendu : 2 - 1.5i\n";

	// Acc�s aux parties r�elle et imaginaire
	double realPart = sum.COMgetReal();
	double imaginaryPart = sum.COMgetImaginary();
	std::cout << "Real Part: " << realPart << std::endl;
	std::cout << "Attendu : 2\n";
	std::cout << "Imaginary Part: " << imaginaryPart << std::endl;
	std::cout << "Attendu : -1.5\n";

	
	CComplex i;
	i =  CComplex(1, 0)*CComplex(1, 0);
	i = CComplex(1, 0) * 1.0;
	i = 1.0* CComplex(1, 0);
	i = CComplex(1, 0) - 1;
	i = 1 - CComplex(1, 0);
	i = 1 + CComplex(1, 0);
	i = CComplex(1, 0) + 1;
	i = 1 / CComplex(1, 3);
	std::cout << i;
	i = CComplex(1, 3) / 1;
	std::cout << i << "\n";
}

void testComplexMatrix()
{
	//CMatrixOperation<CComplex> op;

	// Cr�ation d'une matrice de complexe 2x2
	CMatrix<CComplex>* MAT = new CMatrix<CComplex>(2, 2);
	MAT->MATSetValue(0, 0, CComplex(1, 0));
	MAT->MATSetValue(1, 0, CComplex(2, 0));
	MAT->MATSetValue(1, 1, CComplex(3, 0));
	MAT->MATSetValue(0, 1, CComplex(4, 0));

	// Affichage de la matrice
	std::cout << "Matrice originale : " << std::endl;
	std::cout << *MAT;
	std::cout << std::endl;

	// Cr�ation d'une matrice identit� 2x2
	CMatrix<CComplex> identity(2, 2);
	//identity.MATSetValue(0, 0, CComplex(1, 0));
	//identity.MATSetValue(1, 1, CComplex(1, 0));

	
	// Multiplication de la matrice par la matrice identit�
	//CMatrix<CComplex> result = MAT * identity;

	// Affichage du r�sultat
	std::cout << "R�sultat de la multiplication : " << std::endl;
	//std::cout << result;

	//result = MAT + MAT;
	std::cout << "R�sultat de l'addition de deux originals : " << std::endl;
	//std::cout << result;


	//result = MAT - MAT;
	std::cout << "R�sultat de la soustraction de deux originals : " << std::endl;
	//std::cout << result;
	std::cout << std::endl;

	CMatrix<double>* mat1 = new CMatrix<double>(2, 2);
	mat1->MATSetValue(1, 1, 5.83f);
	mat1->MATSetValue(1, 0, 5.83f);
	mat1->MATSetValue(0, 0, 5.83f);
	mat1->MATSetValue(0, 1, 5.83f);
	
	CMatrix<CComplex>* mat2 = new CMatrix<CComplex>(2, 2);
	mat2->MATSetValue(1, 1, CComplex(1,5));
	mat2->MATSetValue(1, 0, 2);
	mat2->MATSetValue(0, 0, 3);
	mat2->MATSetValue(0, 1, 4);

	std::cout << *mat1 << std::endl << *mat2 << std::endl;
	
	std::cout << *mat2 + *mat1 << std::endl;

	std::cout << *mat2 * 5 << std::endl;

	std::cout << *mat1 * 5 << std::endl;

	std::cout << *mat2 * CComplex(2,5) << std::endl;

	std::cout << *mat1 * CComplex(2, 5) << std::endl;

	return;
}

void testGetComplex()
{
	CStringOperation op;
	double real;
	double ima;
	const char * token;
	token = "3 + 4i";
	op.getComplex(token, real, ima);
	std::cout << "attendu : " << token<<"\n";
	std::cout << "real : " << real << " ; imag : " << ima << "\n";

	token = "3 - 4i";
	op.getComplex(token, real, ima);
	std::cout << "attendu : " << token << "\n";
	std::cout << "real : " << real << " ; imag : " << ima << "\n";

	token = "3.111 + 4.1i";
	op.getComplex(token, real, ima);
	std::cout << "attendu : " << token << "\n";
	std::cout << "real : " << real << " ; imag : " << ima << "\n";

	token = "3.111 - 4.1i";
	op.getComplex(token, real, ima);
	std::cout << "attendu : " << token << "\n";
	std::cout << "real : " << real << " ; imag : " << ima << "\n";

}