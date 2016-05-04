#ifndef MACIERZ_H
#define MACIERZ_H
#include "Zespolona.h"
#include <string>
#include "aghException.h"
using namespace std;

template <class T>
class aghMatrix
{
public:
	aghMatrix();
	void setItems(int row, int col, T ...);
	void setItems(T *tab);
	T setItem(int row, int col, T value);
	aghMatrix & operator =(aghMatrix & value);
	aghMatrix operator +(aghMatrix & value);
	aghMatrix operator *(aghMatrix & value);
	bool operator ==(aghMatrix & value);
	bool operator !=(aghMatrix & value);
	T& operator ()(int row, int col);
	aghMatrix(aghMatrix &Matrix);
	aghMatrix(int rozmiarx, int rozmiary);
	~aghMatrix();
	int getRozmiarx();
	int getRozmiary();
	aghMatrix Mnozenie(aghMatrix Matrix);
private:
	T Pobierz(int wiersz, int kolumna);
	aghMatrix Dodaj(aghMatrix Matrix);
	aghMatrix add(aghMatrix Matrix);
	aghMatrix mul(aghMatrix Matrix);
	aghMatrix Mnozenie(T Matrix);
	aghMatrix mul(T Matrix);
	bool compare(aghMatrix & value);
	aghMatrix(char* x);
	T** tab;
	string print();
	//rozmiarx-liczba wierszy macierzy, rozmiary-liczba kolumn 
	int rozmiarx;
	int rozmiary;

};

//definicje skladowych klasy szablonowej aghMatrix
#include "Macierz_def.h"

//deklaracja operatorow specjalizowanych dla klasy aghMatrix
aghMatrix<string> aghMatrix<string>::operator +(aghMatrix &);
aghMatrix<string> aghMatrix<string>::operator *(aghMatrix &);
aghMatrix<char> aghMatrix<char>::operator +(aghMatrix &);
string polaczS(string val1, string val2);

#endif