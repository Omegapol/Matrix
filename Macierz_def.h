#ifndef MACIERZ_DEF_H
#define MACIERZ_DEF_H

#include <iostream>
#include <array>

/////------------------------public--------------------------

////-----------------------constructors----------------------
template<class T>
aghMatrix<T>::aghMatrix()
{
	rozmiarx = 0;
	rozmiary = 0;
	tab = NULL;
}

template<class T>
aghMatrix<T>::aghMatrix(const aghMatrix<T> & Matrix)
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

template<class T>
aghMatrix<T>::aghMatrix(int rozmiarx, int rozmiary)
{
	this->rozmiarx = rozmiarx;
	this->rozmiary = rozmiary;
	if (rozmiarx < 1 || rozmiary < 1)
	{
		tab = NULL;
		throw aghException();
		return;
	}
	tab = new T*[rozmiarx];
	for (int i = 0; i < rozmiarx; i++)
	{
		tab[i] = new T[rozmiary];
	}
}

/////----------------------destructor--------------------------------
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
	rozmiarx = 0;
	rozmiary = 0;
}


/////----------------------operators---------------------------------

template<class T>
aghMatrix<T> & aghMatrix<T>::operator=(aghMatrix<T> value)
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
			tab[i][j] = value(i,j);
		}
	}
	return *this;
}

template<class T>
aghMatrix<T> aghMatrix<T>::operator+(aghMatrix<T> & value)
{
	return add(value);
}

template<class T>
aghMatrix<T> aghMatrix<T>::operator*(aghMatrix<T> & value)
{
	return mul(value);
}

template<class T>
bool aghMatrix<T>::operator==(aghMatrix<T> & value)
{
	return compare(value);
}

template<class T>
bool aghMatrix<T>::operator!=(aghMatrix<T> &value)
{
	return !compare(value);
}

template<class T>
T& aghMatrix<T>::operator()(int row, int col)
{
	if (row<0 || row>=rozmiarx || col<0 || col>=rozmiary)
	{
		throw aghException();
	}
	return this->tab[row][col];
}

/////----------------------utility methods---------------------------

template<class T>
void aghMatrix<T>::Resize(int row, int col)
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
	rozmiarx = row;
	rozmiary = col;
	tab = new T*[row];
	for (int i = 0; i < row; i++)
	{
		tab[i] = new T[col];
	}
}

template<class T>
int aghMatrix<T>::getRozmiarx() const
{
	return this->rozmiarx;
}

template<class T>
int aghMatrix<T>::getRozmiary() const
{
	return this->rozmiary;
}


template<class T>
template<typename... Arguments>
void aghMatrix<T>::setItems(int row, int col, Arguments ... args)
{
	array<T, sizeof...(args)>unpacked_args{ args... };

	this->Resize(row, col);
	int i = 0;
	int j = 0;

	for (T arg : unpacked_args)
	{
		tab[i][j] = arg;
		j++;
		if (j == rozmiary)
		{
			j = 0;
			i++;
		}
	}
}


template<class T>
void aghMatrix<T>::setItems(T *tab)
{
	for (int i = 0; i < rozmiarx; i++)
	{
		for (int j = 0; j < rozmiary; j++)
		{
			//mozliwy wyjatek
			this->tab[i][j] = tab[i*rozmiary + j];
		}
	}
}

template<class T>
void aghMatrix<T>::setItem(int row, int col, T value)
{
	this->tab[row][col] = value;
}



/////--------------------------------------------------------------------
/////-----------------------------private--------------------------------


//\\desc: funkcja dodajaca macierze
//\\param aghMatrix<T> value : macierz dodawana
//\\throws
template<class T>
aghMatrix<T> aghMatrix<T>::add(aghMatrix<T> value)
{
	if ((this->rozmiary == value.getRozmiary()) && (this->rozmiarx == value.getRozmiarx()))
	{
		aghMatrix<T> result(rozmiarx, rozmiary);
		for (int i = 0; i < rozmiarx; i++)
		{
			for (int j = 0; j < rozmiary; j++)
			{
				result.tab[i][j] = value.tab[i][j] + (this->tab[i][j]);
			}
		}
		return result;
	}
	else
	{
		throw aghException();
		return aghMatrix<T>();
	}
}


//funkcja multiply mnozy dwie macierze
template<class T>
aghMatrix<T> aghMatrix<T>::mul(aghMatrix<T> Matrix)
{
	if ((this->rozmiary == Matrix.getRozmiarx()))
	{
		aghMatrix<T> result(this->rozmiarx, Matrix.getRozmiary());

		for (int i = 0; i < rozmiarx; i++)
		{
			for (int j = 0; j < Matrix.getRozmiary(); j++)
			{
				result(i,j) = (T)0;
			}
		}

		for (int i = 0; i < rozmiarx; i++)
		{
			for (int j = 0; j < Matrix.getRozmiary(); j++)
			{
				for (int k = 0; k < this->rozmiary; k++)
				{
					result.tab[i][j] = result.tab[i][j] + (this->tab[i][k] * (Matrix.tab[k][j]));
				}
			}
		}
		return result;
	}
	else
	{
		throw aghException();
		return aghMatrix<T>();
	}
}


//mnozenie macierzy przez liczbe
template<class T>
aghMatrix<T> aghMatrix<T>::mul(T value)
{
	aghMatrix result(rozmiarx, rozmiary);
	for (int i = 0; i < rozmiarx; i++)
	{
		for (int j = 0; j < rozmiary; j++)
		{
			result.tab[i][j] = this->tab[i][j] * value;
		}
	}
	return result;
}

//porownywanie macierzy, funkcja zwraca true,jezeli dwie macierze sa sobie rowne
template<class T>
bool aghMatrix<T>::compare(aghMatrix<T> & value)
{
	if ((this->rozmiarx != value.getRozmiarx()) || (this->rozmiary != value.getRozmiary()))
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

#endif