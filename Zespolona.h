#ifndef ZESPOLONA_H
#define ZESPOLONA_H

class aghComplex
{
public:
	aghComplex();
	aghComplex(double real,double imag);
	~aghComplex();
	aghComplex operator +(const aghComplex & value);
	aghComplex operator *(const aghComplex & value);
	bool operator!=(const aghComplex & value);
	aghComplex(double real);
	double real, imag;
private:
	aghComplex add(aghComplex Complex);
	aghComplex mul(aghComplex Complex);
	void wypisz();
	bool isZero();
};

#endif
