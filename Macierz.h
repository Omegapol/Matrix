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

	//\\desc: konstruktor domyslny klasy aghMatrix
	aghMatrix();

	//\\desc: konstruktor kopiujacy
	aghMatrix(const aghMatrix<T> &Matrix);

	//\\desc: konstruktor klasy aghMatrix tworzacy macierz o zadanych wymiarach
	//\\param int rozmiarx : ilosc wierszy
	//\\param int rozmiary : ilosc kolumn
	aghMatrix(int rozmiarx, int rozmiary);

	//\\destrukror klasy aghMatrix
	~aghMatrix();

	//\\desc: funkcja zmieniajaca rozmiary macierzy
	//\\param int row : ilosc wierszy
	//\\param int col : ilosc kolumn
	void Resize(int row, int col);

	//\\desc: funkcja ustawiajaca kolejne elementy macierzy
	//\\param int wiersze : ilosc wierszy
	//\\param int kolumny : ilosc kolumn
	//\\param Arguments... args : kolejne elementy macierzy
	template<class ... Arguments>void setItems(int wiersze, int kolumny, Arguments... args);

	//\\desc: funkcja setitems jako argument przyjmuje wskaznik na poczatek tablicy
	//\\param T *tab : tablica danych
	void setItems(T *tab);

	//\\desc: funkcja setItem przyjmuje trzy argumenty: nr wiersza i kolumny macierzy oraz wartosc
	//\\sluzy do przypisywania wartosci konkretnemu elementowi w macierzy
	//\\param int row : wiersz
	//\\param int col : kolumna
	//\\param T value : dana do przypisania
	void setItem(int row, int col, T value);

	//\\desc: operator = przypisuje do macierzy inna, zadana macierz 
	aghMatrix & operator =(aghMatrix value);

	//\\desc: operator + dodajacy do siebie dwie macierze
	aghMatrix operator +(aghMatrix & value);

	//\\desc: operator * mnozacy dwie macierze
	aghMatrix operator *(aghMatrix & value);

	//\\desc: operator == zwraca true w przypadku,gdy dwie porownywane macierze sa sobie rowne
	bool operator ==(aghMatrix & value);

	//\\desc: operator != , ktory zwraca true, jezeli dwie porownywane macierze sa od siebie rozne
	bool operator !=(aghMatrix & value);

	//\\desc: operator (),ktory pozwala na pobranie elementu z konkretnego wiersza i kolumny macierzy
	//\\param int row : wiersz
	//\\param int col : kolumna
	T& operator ()(int row, int col);

	//\\desc: zwraca ilosc wierszy danej macierzy
	int getRozmiarx() const;

	//\\desc: zwraca ilosc kolumn danej macierzy
	int getRozmiary() const;

private:
	aghMatrix add(aghMatrix Matrix);
	aghMatrix mul(aghMatrix Matrix);
	aghMatrix mul(T value);
	bool compare(aghMatrix & value);

	//\\tablica dwuwymiarowa przechowujaca dane
	T** tab;

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

//\\desc: funkcja zwracajaca sume dwoch stringow (jako zbiorow)
//\\param string val1 : ilosc wierszy
//\\param string val2 : ilosc kolumn
string polaczS(string val1, string val2);

//\\desc: funkcja zwracajaca iloczyn dwoch stringow (jako zbiorow)
//\\param string val1 : ilosc wierszy
//\\param string val2 : ilosc kolumn
string iloczS(string val1, string val2);

#endif