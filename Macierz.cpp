#include "Macierz.h"
#include <iostream>

using namespace std;

//operator specjalizowany + typu char,umozliwia dodawanie macierzy typu char
template<>
aghMatrix<char> aghMatrix<char>:: operator +(aghMatrix<char> &value)
{
	//tmp1,tmp2 - zmienne pomocnicze
	int tmp1, tmp2;
	aghMatrix<char> result(rozmiarx, rozmiary);
	for (int i = 0; i < rozmiarx; i++)
	{
		for (int j = 0; j < rozmiary; j++)
		{
			tmp1 = (int)this->tab[i][j] - (int)'a';
			tmp2 = (int)value(i, j) - (int)'a';
			tmp1 += tmp2;
			tmp1 = tmp1 % 26;
			result(i, j) = tmp1 + (int)'a';
		}
	}
	return result;
}

//operator specjalizowany * typu char, umozliwia mnozenie macierzy typu char
template<>
aghMatrix<char> aghMatrix<char>::operator *(aghMatrix<char> &value)
{
	aghMatrix <int> matrix1(rozmiarx, rozmiary);
	aghMatrix <int> matrix2(value.getRozmiarx(), value.getRozmiary());
	for (int i = 0; i < rozmiarx; i++)
	{
		for (int j = 0; j < rozmiary; j++)
		{
			matrix1(i, j) = (int)this->tab[i][j] - (int)'a';
		}
	}
	for (int i = 0; i < value.getRozmiarx(); i++)
	{
		for (int j = 0; j < value.getRozmiary(); j++)
		{
			matrix2(i, j) = (int)value(i, j) - (int)'a';
		}
	}
	matrix1 = matrix1*matrix2;
	aghMatrix <char> result(matrix1.getRozmiarx(), matrix1.getRozmiary());
	for (int i = 0; i < matrix1.getRozmiarx(); i++)
	{
		for (int j = 0; j < matrix1.getRozmiary(); j++)
		{
			result(i, j) = ((char)(matrix1(i, j) % 26) + (int)'a');
		}
	}

	return result;
}

//operator specjalizowany + dla typu string,umozliwia dodawanie macierzy typu string
template<>
aghMatrix<string> aghMatrix<string>::operator +(aghMatrix &value)
{
	aghMatrix <string> result(rozmiarx, rozmiary);
	for (int i = 0; i < rozmiarx; i++)
	{
		for (int j = 0; j < rozmiary; j++)
		{
			result(i, j) = polaczS(this->tab[i][j], value(i, j));
		}
	}
	return result;
}

//operator specjalizowany * dla typu string, umozliwia mnozenie macierzy typu string
template<>
aghMatrix<string> aghMatrix<string>::operator *(aghMatrix & Matrix)
{
	if ((this->rozmiary == Matrix.getRozmiarx()))
	{
		aghMatrix<string> result(this->rozmiarx, Matrix.getRozmiary());

		for (int i = 0; i < rozmiarx; i++)
		{
			for (int j = 0; j < Matrix.getRozmiary(); j++)
			{
				result(i, j) = "";
			}
		}

		for (int i = 0; i < rozmiarx; i++)
		{
			for (int j = 0; j < Matrix.getRozmiary(); j++)
			{
				for (int k = 0; k < this->rozmiary; k++)
				{
					result.tab[i][j] = polaczS(result.tab[i][j], iloczS(this->tab[i][k], (Matrix.tab[k][j])));
				}
			}
		}
		return result;
	}
	else
	{
		throw aghException();
		return aghMatrix<string>();
	}
}

//funkcja laczaca ze soba zmienne typu string, rezultatem jest string bedacy ilorazem dwoch obiektow typu string
string polaczS(string val1, string val2)
{
	string result;
	for (int i = 0; i < val1.length(); i++)
	{
		bool czyDodac = true;
		for (int j = 0; j < result.length(); j++)
		{
			if (val1[i] == result[j])
			{
				czyDodac = false;
				break;
			}
		}
		if (czyDodac)
		{
			result += val1[i];
		}
	}

	for (int i = 0; i < val2.length(); i++)
	{
		bool czyDodac = true;
		for (int j = 0; j < result.length(); j++)
		{
			if (val2[i] == result[j])
			{
				czyDodac = false;
				break;
			}
		}
		if (czyDodac)
		{
			result += val2[i];
		}
	}
	return result;
}

string iloczS(string val1, string val2)
{
	string result;
	for (int i = 0; i < val1.length(); i++)
	{
		bool czyDodac = false;
		for (int j = 0; j < val2.length(); j++)
		{
			if (val1[i] == val2[j])
			{
				czyDodac = true;
				break;
			}
		}
		if (czyDodac)
		{
			result += val1[i];
		}
	}
	return result;
}
