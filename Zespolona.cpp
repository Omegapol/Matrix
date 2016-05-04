#include<math.h>
#include "Zespolona.h"
#include <iostream>
using namespace std;

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

//destruktor dla klasy aghComplex
aghComplex::~aghComplex()
{

}

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

//dodawanie liczby typu double do liczby zespolonej
aghComplex::aghComplex(double real)
{	
	imag = 0;
	this->real = real;
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