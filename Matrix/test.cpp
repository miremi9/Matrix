#include "test.h"


void testOPmatrix()
{
	CMatrixOperation<double> op;
	CMatrix<double> * MAT = op.MOPCreateMAT("exemplefile.txt");
	op.MOPprintMAT(*MAT);
}

void testComplexe() 
{
	// Test de constructeurs et d'accès
	CComplex complex1;  // Constructeur par défaut
	std::cout << "Complex1: ";
	complex1.print();
	std::cout << "Attendu : 0 + 0i\n";

	CComplex complex2(3.5, -2.1);  // Constructeur avec parties réelle et imaginaire spécifiées
	std::cout << "Complex2: ";
	complex2.print();
	std::cout << "Attendu : 3.5 - 2.1i\n";

	CComplex complex3(4.2);  // Constructeur avec partie réelle spécifiée (partie imaginaire par défaut à 0)
	std::cout << "Complex3: ";
	complex3.print();
	std::cout << "Attendu : 4.2 + 0i\n";

	// Test des opérations mathématiques
	CComplex sum = complex1 + complex2;
	std::cout << "Sum: ";
	sum.print();
	std::cout << "Attendu : 3.5 - 2.1i\n";

	CComplex diff = complex2 - complex3;
	std::cout << "Difference: ";
	diff.print();
	std::cout << "Attendu : -0.7 - 2.1i\n";

	CComplex product = complex2 * complex3;
	std::cout << "Product: ";
	product.print();
	std::cout << "Attendu : 14.7 - 8.82i\n";

	CComplex quotient = complex3 / complex2;
	std::cout << "Quotient: ";
	quotient.print();
	std::cout << "Attendu : 0.172577 - 1.60565i\n";

	// Modification des parties réelle et imaginaire
	sum.setReal(2.0);
	sum.setImaginary(-1.5);
	std::cout << "Modified Sum: ";
	sum.print();
	std::cout << "Attendu : 2 - 1.5i\n";

	// Accès aux parties réelle et imaginaire
	double realPart = sum.getReal();
	double imaginaryPart = sum.getImaginary();
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
	i = 1 / CComplex(1, 0);
	i = CComplex(1, 0) / 1;


}

void testComplexMatrix()
{
	CMatrixOperation<CComplex> op;

	// Création d'une matrice de complexe 2x2
	CMatrix<CComplex> MAT(2, 2);
	MAT.MATSetValue(0, 0, CComplex(1, 0));
	MAT.MATSetValue(1, 0, CComplex(2, 0));
	MAT.MATSetValue(1, 1, CComplex(3, 0));
	MAT.MATSetValue(0, 1, CComplex(4, 0));

	// Affichage de la matrice
	std::cout << "Matrice originale : " << std::endl;
	op.MOPprintMAT(MAT);
	std::cout << std::endl;

	// Création d'une matrice identité 2x2
	CMatrix<CComplex> identity(2, 2);
	identity.MATSetValue(0, 0, CComplex(1, 0));
	identity.MATSetValue(1, 1, CComplex(1, 0));

	// Multiplication de la matrice par la matrice identité
	CMatrix<CComplex> result = MAT* identity;

	// Affichage du résultat
	std::cout << "Résultat de la multiplication : " << std::endl;
	op.MOPprintMAT(result);

	result = MAT + MAT;
	std::cout << "Résultat de l'addition de deux originals : " << std::endl;
	op.MOPprintMAT(result);


	result = MAT - MAT;
	std::cout << "Résultat de la soustraction de deux originals : " << std::endl;
	op.MOPprintMAT(result);
	std::cout << std::endl;

	return;
}