/*
*   Copyright © 2018
*
*   Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
*
*   Double degree in Mathematics-Computer engineering.
*   Complutense university, Madrid.
*
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool resuelveCaso(int numElems);
bool siemprePremio(vector<int> const& v, int indiceIni, int indiceFin, int &minimo, int &maximo);

int main()
{
	int numElems;

	cin >> numElems;

	while (cin)
	{
		if (resuelveCaso(numElems))
			cout << "SIEMPRE PREMIO\n";

		else
			cout << "ELEGIR OTRA\n";

		cin >> numElems;
	}
	return 0;
}

bool resuelveCaso(int numElems)
{
	/* -> Del caso a resolver solo sabemos el número de elementos */
	vector<int> v;
	int aux, aux2;

	for (int i = 0; i < numElems; i++)
	{
		cin >> aux;
		v.push_back(aux);
	}

	/* -> Aquí ya tenemos el vector leído */

	return siemprePremio(v, 0, numElems, aux, aux2);
}

/**
* PRECONDICIONES:
*	-> indiceIni < indiceFin !! De un vector vacío no podemos decir su mínimo y su máximo.
*
* @param &minimo Al final de la ejecución de la función tiene el valor del mínimo del subsegmento.
* @param &maximo Al final de la ejecución de la función tiene el valor del máximo del subsegmento.
* @return bool   Devuelve true si la disposición de v entre [indiceIni, indiceFin) es de siempre premio, false en caso contrario.
*/
bool siemprePremio(vector<int> const& v, int indiceIni, int indiceFin, int &minimo, int &maximo)
{
		maximo = v[indiceIni]; int indiceMax = indiceIni;
		minimo = v[indiceIni];

		for (int i = indiceIni + 1; i < indiceFin; i++)
		{
			if (v[i] > maximo) { maximo = v[i]; indiceMax = i; }
			if (v[i] < minimo)  minimo = v[i];
		}

		/* Aquí tenemos el mínimo del subsegmento y el máximo con su índice. */
		
		if (indiceFin - indiceIni < 3)	return true;	//Tenemos max y mínimo de exte segmento de longitud pequeña.
		else
		{
			int maxDcha, maxIzq, minDcha, minIzq;
			
			if (indiceIni == indiceMax)	//Para no romper la precondición indiceIni < indiceFin en la llamada
				return siemprePremio(v, indiceMax + 1, indiceFin, minDcha, minIzq);
			else if (indiceMax + 1 == indiceFin) //Para no romper la precondición indiceIni < indiceFin en la llamada
				return siemprePremio(v, indiceIni, indiceMax, minIzq, maxIzq);
			else
				return siemprePremio(v, indiceIni, indiceMax, minIzq, maxIzq)       &&
				       siemprePremio(v, indiceMax + 1, indiceFin, minDcha, maxDcha) &&
				       minIzq >= maxDcha;
		}
}
