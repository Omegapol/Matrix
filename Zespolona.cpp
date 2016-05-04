#include<math.h>
#include "Zespolona.h"
#include <iostream>
using namespace std;

////----------------------------------------------------
////---------------------public-------------------------


////---------------------contructors--------------------
//konstruktor klasy ahgComplex
aghComplex::aghComplex()
{
	real = 0;
	imag = 0;
}

//konstruktor parametrowy dla klasy aghComplex
//tworzy liczbe zespolona o konkretnej czesci rzeczywistej i urojonej
aghComplex::aghComplex(double rz, double ur)
{
	this->real = rz;
	this->imag = ur;

}

//dodawanie liczby typu double do liczby zespolonej
aghComplex::aghComplex(double real)
{
	imag = 0;
	this->real = real;
}

////------------------destructor----------------------
//destruktor dla klasy aghComplex
aghComplex::~aghComplex()
{

}

////-------------------operators----------------------

//operator +,umozliwia dodawanie do siebie dwoch liczb zespolonych
aghComplex aghComplex::operator+(const aghComplex & value)
{
	return add(value);
}

//operator *,umozliwia mnozenie ze soba dwoch liczb zespolonych
aghComplex aghComplex::operator*(const aghComplex & value)
{
	return mul(value);
}

bool aghComplex::operator!=(const aghComplex & value)
{
	if (value.real == this->real)
	{
		if (value.imag == this->imag)
		{
			return false;
		}
	}
	return true;
}

////----------------------------------------------------
////---------------------private------------------------

//dodawanie dwoch liczb zespolonych do siebie
aghComplex aghComplex::add(aghComplex Complex)
{
	aghComplex result;
	result.real = Complex.real + this->real;
	result.imag = Complex.imag + this->imag;
	return result;
}

//mnozenie dwoch liczb zespolonych
aghComplex aghComplex::mul(aghComplex Complex)
{
	aghComplex result;
	result.real = real*Complex.real - imag*Complex.imag;
	result.imag = imag*Complex.real + real*Complex.imag;
	return result;
}


//wypisywanie liczby zespolonej
void aghComplex::wypisz()
{
	std::cout << "Czesc rzeczywista: " << real << " Czesc urojona: " << imag << std::endl;
}

//funkcja zwraca true,gdy liczba zespolona jest rowna 0
bool aghComplex::isZero()
{
	if ((this->real == 0) && (this->imag == 0)) return true;
	else
		return false;
}
