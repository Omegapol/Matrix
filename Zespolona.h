#ifndef ZESPOLONA_H
#define ZESPOLONA_H

class aghComplex
{
public:
	//\\desc: konstruktor domyslny klasy aghComplex
	aghComplex();

	//\\desc: konstruktor klasy aghComplex tworzacy zespolona 
	//\\param double real : czesc rzeczywista
	//\\param double imag : czesc urojona
	aghComplex(double real,double imag);

	//\\desc: konstruktor klasy aghComplex tworzacy zespolona
	//\\param double real : czesc rzeczywista
	aghComplex(double real);

	//\\desc: destruktor
	~aghComplex();

	//\\desc: operator dodajacy
	aghComplex operator +(const aghComplex & value);

	//\\desc: operator mnozacy
	aghComplex operator *(const aghComplex & value);

	//\\desc: operator porownujacy
	bool operator!=(const aghComplex & value);

	//\\desc: czesc rzeczywista
	double real;

	//\\desc: czesc urojona
	double imag;

private:
	aghComplex add(aghComplex Complex);
	aghComplex mul(aghComplex Complex);
	void wypisz();
	bool isZero();
};

#endif
