/*
*   Copyright © 2018
*
*   Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
*
*   Double degree in Mathematics-Computer engineering.
*   Complutense university, Madrid.
*
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;


void leerDatos(vector<string> &v);
void resuelveCaso(vector<string> &v, int numCamas, int numSorteo);
void mostrarVector(vector<string> const& v);

int main()
{
	vector<string> v;
	int numCasos; int numSorteo, numConCama;

	cin >> numCasos;

	for (int i = 0; i < numCasos; i++)
	{
		//Leemos los datos
		leerDatos(v); cin >> numConCama >> numSorteo;

		//Llamamos a resolver caso
		resuelveCaso(v, numConCama, numSorteo);

		//Eliminamos los datos almacenados
		v.clear();
	}

	return 0;
}

void leerDatos(vector<string> &v)
{
	string aux; cin >> aux;

	while (aux != "F")
	{
		v.push_back(aux);
		cin >> aux;
	}
}
void resuelveCaso(vector<string> &v, int numCamas, int numSorteo)
{
	if (numCamas >= v.size())		cout << "TODOS TIENEN CAMA\n";
	else if (numCamas == 0)			cout << "NADIE TIENE CAMA\n";
	else
	{
		int i = (numSorteo - 1)%v.size();

		while (v.size() > numCamas)
		{
			v.erase(v.begin() + i);
			i = (i + numSorteo - 1) % v.size();
		}

		mostrarVector(v);
	}
}
void mostrarVector(vector<string> const& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];

	    if (i + 1 != v.size())
			cout << " ";
	}

		cout << '\n';
	}
