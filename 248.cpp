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
using namespace std;

int main()
{
	int maxIni, maxFin, maxMed, max, aux;
	int tam, sumaIni, sumaMed;

	cin >> tam;

	while (tam != 0)
	{
		sumaIni = 0; sumaMed = 0;
		maxIni = -1; maxMed = -1; maxFin = 0;

		for (int i = 0; i < tam; i++)
		{
			cin >> aux;

			if (sumaMed > 0 || aux > 0)
			{
				sumaMed += aux;	if (sumaMed > maxMed)	maxMed = sumaMed;
			}

			sumaIni += aux;	if (sumaIni > maxIni)	maxIni = sumaIni;

			maxFin	+= aux; if (maxFin < 0)			maxFin = 0;
		}

		if (maxMed > maxIni + maxFin)		max = maxMed;
		else								max = maxIni + maxFin;

		cout << max << '\n';

		cin >> tam;
	}

	return 0;
}
