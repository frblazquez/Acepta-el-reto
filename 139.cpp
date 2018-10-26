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
#include <set>
using namespace std;

int siguiente(int aux);

int main()
{
	set<int> c;
	int aux;

	cin >> aux;

	while (aux != 0)
	{
		if (aux == 1) {
			cout << aux << " -> cubifinito.\n";
			cin >> aux;
			c.clear();
		}
		else if (c.count(aux) == 0){
			cout << aux << " - ";
			c.insert(aux);
			aux = siguiente(aux);
		}
		else
		{
			cout << aux	<< " -> no cubifinito.\n";
			cin >> aux;
			c.clear();
		}
	}
}

int siguiente(int aux)
{
	int digito;
	int suma = 0;

	while (aux != 0)
	{
		digito = aux % 10;
		suma += digito*digito*digito;
		aux /= 10;
	}

	return suma;
}
