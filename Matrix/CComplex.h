#ifndef CCOMPLEX_H
#define CCOMPLEX_H
#include <iostream>

class CComplex {
private:
	double dCOMreal;
	double dCOMimaginary;  

public:
	// Constructeurs
	CComplex();
	CComplex(double real, double imaginary);
	CComplex(const CComplex & COMparam);
	CComplex(double real);
	// Accesseurs et mutateurs

	double getReal() const { return dCOMreal; };
	double getImaginary() const { return dCOMimaginary; };
	void setReal(double real) { dCOMreal = real; };
	void setImaginary(double imaginary) { dCOMimaginary = imaginary; };


	CComplex & operator=(const CComplex& other);
	CComplex & operator+=(const CComplex& other);
	// Opérations mathématiques
	CComplex operator+(const CComplex& other) const;
	CComplex operator-(const CComplex& other) const;
	CComplex operator*(const CComplex& other) const;
	CComplex operator/(const CComplex& other) const;

	friend CComplex operator*(double value1, CComplex value2);
	friend CComplex operator*(CComplex value2, double value1);

	friend CComplex operator-(double value1, CComplex value2);
	friend CComplex operator-(CComplex value2, double value1);

	friend CComplex operator/(double value1, CComplex value2);
	friend CComplex operator/(CComplex value2, double value1);


	friend std::ostream& operator<<(std::ostream& os, const CComplex& complex);

	// Méthode d'affichage
	void print() const;
};

#endif
