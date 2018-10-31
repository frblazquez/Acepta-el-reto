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
#include <deque>
using namespace std;


int main()
{
	int longSubintervalo, numSobres;
	deque<int> intervalo, candidatosMax;
	int maximo = 0, aux;

	cin >> numSobres >> longSubintervalo;

	while (numSobres != 0 || longSubintervalo != 0)
	{
		if (longSubintervalo != 1)
		{
			/////////// PREPARAMOS LAS VARIABLES ///////////
			maximo = 0;
			intervalo.clear();
			candidatosMax.clear();

			/////////// LEEMOS LOS DATOS PRIMER SUBINTERVALO ///////////////////
			for (int i = 0; i < longSubintervalo; i++)
			{
				cin >> aux;
				intervalo.push_back(aux);

				if (aux > maximo)
				{
					maximo = aux;
					candidatosMax.clear();
				}
				else
				{
					while (candidatosMax.size() > 0 && candidatosMax.back() < aux)
						candidatosMax.pop_back();

					candidatosMax.push_back(aux);
				}
			}
			///////////// AVANZAMOS  ////////////
			for (int i = longSubintervalo; i < numSobres; i++)
			{
				cout << maximo << " ";

				if (intervalo.front() == maximo)
				{
					maximo = candidatosMax.front();
					candidatosMax.pop_front();
				}

				cin >> aux;
				intervalo.pop_front();
				intervalo.push_back(aux);

				if (aux > maximo)
				{
					maximo = aux;
					candidatosMax.clear();
				}
				else
				{
					while (candidatosMax.size() > 0 && candidatosMax.back() < aux)
						candidatosMax.pop_back();

					candidatosMax.push_back(aux);
				}
			}

			cout << maximo << '\n';
		}
		else
		{
			cin >> aux;

			for (int i = 0; i < numSobres - 1; i++)
			{
				cout << aux << " ";
				cin >> aux;
			}
			cout << aux << '\n';
		}

		cin >> numSobres >> longSubintervalo;
	}

	return 0;
}
