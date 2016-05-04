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
	aghMatrix(aghMatrix &Matrix);
	aghMatrix(int rozmiarx, int rozmiary);
	~aghMatrix();
	void Resize(int row, int col);
	void setItems(int row, int col, T ...);
	void setItems(T *tab);
	void setItem(int row, int col, T value);
	aghMatrix & operator =(aghMatrix value);
	aghMatrix operator +(aghMatrix & value);
	aghMatrix operator *(aghMatrix & value);
	bool operator ==(aghMatrix & value);
	bool operator !=(aghMatrix & value);
	T& operator ()(int row, int col);
	int getRozmiarx();
	int getRozmiary();
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
	//\\rozmiarx-liczba wierszy macierzy, 
	int rozmiarx;
	//\\rozmiary-liczba kolumn 
	int rozmiary;

};

//definicje skladowych klasy szablonowej aghMatrix
#include "Macierz_def.h"

//deklaracja operatorow specjalizowanych dla klasy aghMatrix
template<>
aghMatrix<string> aghMatrix<string>::operator +(aghMatrix &);


template<>
aghMatrix<string> aghMatrix<string>::operator *(aghMatrix &);

template<>
aghMatrix<char> aghMatrix<char>::operator +(aghMatrix &);

template<>
aghMatrix<char> aghMatrix<char>::operator *(aghMatrix &);

string polaczS(string val1, string val2);

#endif