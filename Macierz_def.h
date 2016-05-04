#ifndef MACIERZ_DEF_H
#define MACIERZ_DEF_H

#include <iostream>
#include <cstdarg>		//biblioteka dla zdefiniowania funkcji ze zmnienna liczba argumentow

//konstruktor bezparametrowy klasy aghMatrix
template<class T>
aghMatrix<T>::aghMatrix()
{
	rozmiarx = 0;
	rozmiary = 0;
	tab = NULL;
}

template<class T>
void aghMatrix<T>::setItems(int row, int col, T ...)
{
	va_list arguments;
	va_start(arguments, col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			this->tab[i][j] = va_arg(arguments, T);
		}
	}
	va_end(arguments);
}


//funkcja setitems jako argument przyjmuje wskaznik na poczatek tablicy
template<class T>
void aghMatrix<T>::setItems(T *tab)
{
	for (int i = 0; i < rozmiarx; i++)
	{
		for (int j = 0; j < rozmiary; j++)
		{
			//mozliwy wyjatek
			this->tab[i][j] = tab[i*j];
		}
	}
}

//funkcja setItem przyjmuje trzy argumenty: nr wiersza i kolumny macierzy oraz wartosc
//sluzy do przypisywania wartosci konkretnemu elementowi w macierzy
template<class T>
T aghMatrix<T>::setItem(int row, int col, T value)
{
	this->tab[row][col] = value;
}

//konstruktor klasy aghMatrix z parametrem
//tworzymy tablice elementow dla macierzy
template<class T>
aghMatrix<T>::aghMatrix(aghMatrix<T> & Matrix)
{
	rozmiarx = Matrix.getRozmiarx();
	rozmiary = Matrix.getRozmiary();
	tab = new T*[rozmiarx];
	for (int i = 0; i < rozmiarx; i++)
	{
		tab[i] = new T[rozmiary];
		for (int j = 0; j < rozmiary; j++)
		{
			tab[i][j] = Matrix.tab[i][j];
		}
	}
}

//operator = przypisuje do macierzy inna, zadana macierz 
template<class T>
aghMatrix<T> & aghMatrix<T>::operator=(aghMatrix<T> &value)
{
	if (tab != NULL)
	{
		for (int i = 0; i < rozmiarx; i++)
		{

			delete[] tab[i];
		}
		delete[] tab;
	}
	tab = NULL;
	rozmiarx = value.getRozmiarx();
	rozmiary = value.getRozmiary();
	tab = new T*[rozmiarx];
	for (int i = 0; i < rozmiarx; i++)
	{
		tab[i] = new T[rozmiary];
		for (int j = 0; j < rozmiary; j++)
		{
			tab[i][j] = value.tab[i][j];
		}
	}
	return *this;
}

//operator + dodajacy do siebie dwie macierze
template<class T>
aghMatrix<T> aghMatrix<T>::operator+(aghMatrix<T> & value)
{
	return add(value);
}

//operator * mnozacy dwie macierze
template<class T>
aghMatrix<T> aghMatrix<T>::operator*(aghMatrix<T> & value)
{
	return mul(value);
}

//operator == zwraca true w przypadku,gdy dwie porownywane macierze sa sobie rowne
template<class T>
bool aghMatrix<T>::operator==(aghMatrix<T> & value)
{
	return compare();
}

//operator != , ktory zwraca true, jezeli dwie porownywane macierze sa od siebie rozne
template<class T>
bool aghMatrix<T>::operator!=(aghMatrix<T> &value)
{
	return !compare();
}

//operator (),ktory pozwala na pobranie elementu z konkretnego wiersza i kolumny macierzy
template<class T>
T& aghMatrix<T>::operator()(int row, int col)
{
	return this->tab[row][col];
}

//konstruktor klasy aghMatrix tworzacy macierz o zadanych wymiarach
template<class T>
aghMatrix<T>::aghMatrix(int rozmiarx, int rozmiary)
{
	this->rozmiarx = rozmiarx;
	this->rozmiary = rozmiarx;
	if (rozmiarx < 1 || rozmiary < 1)
	{
		cout << "bledne rozmiary" << endl;
		tab = NULL;
		return;
	}
	tab = new T*[rozmiarx];
	for (int i = 0; i < rozmiarx; i++)
	{
		tab[i] = new T[rozmiary];
	}
}

//destrukror klasy aghMatrix
template<class T>
aghMatrix<T>::~aghMatrix()
{
	if (tab != NULL)
	{
		for (int i = 0; i < rozmiarx; i++)
		{
			delete[] tab[i];
		}
		delete[] tab;
	}
	tab = NULL;
}

//funkcja getRozmiarx() zwraca ilosc wierszy danej macierzy
template<class T>
int aghMatrix<T>::getRozmiarx()
{
	return this->rozmiarx;
}

//funkcja getRozmiary() zwraca ilosc kolumn danej macierzy
template<class T>
int aghMatrix<T>::getRozmiary()
{
	return this->rozmiary;
}

//funkcja pobierajaca konkretny element z macierzy
//WTF?!
template<class T>
T aghMatrix<T>::Pobierz(int wiersz, int kolumna)
{
	if (wiersz > rozmiarx || kolumna > rozmiary || kolumna <= 0 || wiersz <= 0)
	{
		cout << "bledna kolumna lub wiersz" << endl;
		return 0;
	}
	return tab[wiersz - 1][kolumna - 1];
}

//funkcja dodajaca do siebie dwie macierze
template<class T>
aghMatrix<T> aghMatrix<T>::Dodaj(aghMatrix<T> Matrix)
{
	if ((this->rozmiary == Matrix.getRozmiary()) && (this->rozmiarx == Matrix.getRozmiarx()))
	{
		aghMatrix result(rozmiarx, rozmiary);
		for (int i = 0; i < rozmiarx; i++)
		{
			for (int j = 0; j < rozmiary; j++)
			{
				result.tab[i][j] = result.tab[i][j].add(this->tab[i][j]);
			}
		}
		return result;
	}
	else
	{
		cout << " nie mozna dodac" << endl;
		return aghMatrix();
	}
}

//funkcja dodajaca
template<class T>
aghMatrix<T> aghMatrix<T>::add(aghMatrix<T> Matrix)
{
	return Dodaj(Matrix);
}

//
template<class T>
aghMatrix<T> aghMatrix<T>::Mnozenie(aghMatrix<T> Matrix)
{
	if ((this->rozmiarx == Matrix.getRozmiarx()))
	{
		aghMatrix result(this->rozmiarx, Matrix.getRozmiary());
		for (int i = 0; i < rozmiarx; i++)
		{
			for (int j = 0; j < rozmiary; j++)
			{
				for (int k = 0; k < this->rozmiarx; k++)
				{
					result.tab[i][j] = result.tab[i][j] + (this->tab[i][k] * (result.tab[k][j]));
				}
			}
		}
		return result;
	}
	else
	{
		throw aghException();
		cout << "nie mozna pomnozyc" << endl;
		return aghMatrix();
	}
}

//funkcja multiply mnozy dwie macierze
template<class T>
aghMatrix<T> aghMatrix<T>::mul(aghMatrix<T> Matrix)
{
	return Mnozenie(Matrix);
}

//mnozenie dwoch macierzy dowolnego typu
template<class T>
aghMatrix<T> aghMatrix<T>::Mnozenie(T Matrix)
{
	aghMatrix result(rozmiarx, rozmiary);
	for (int i = 0; i < rozmiarx; i++)
	{
		for (int j = 0; j < rozmiary; j++)
		{
			result.tab[i][j] = this->tab[i][j] * Matrix;
		}
	}
	return result;
}

//mnozenie
template<class T>
aghMatrix<T> aghMatrix<T>::mul(T Matrix)
{
	return Mnozenie(Matrix);
}

//porownywanie macierzy, funkcja zwraca true,jezeli dwie macierze sa sobie rowne
template<class T>
bool aghMatrix<T>::compare(aghMatrix<T> & value)
{
	if ((this->rozmiarx != value->getRozmiarx()) || (this->rozmiary != value->getRozmiary()))
	{
		return false;
	}

	for (int i = 0; i < rozmiarx; i++)
	{
		for (int j = 0; j < rozmiary; j++)
		{
			if (this->tab[i][j] != value(i, j))
			{
				return false;
			}
		}
	}
	return true;
}

//potrzebne to jest?
template<class T>
string aghMatrix<T>::print()
{
	string r = "";
	for (int i = 0; i < rozmiarx; i++)
	{
		for (int j = 0; j < rozmiary; j++)
		{
			r += to_string(this->tab[i][j].rz) + "i" + to_string(this->tab[i][j].ur) + "\t";
		}
		r += '\n';
	}
	return r;
}

#endif