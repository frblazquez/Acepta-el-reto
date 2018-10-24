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
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
	string categoria, clave1, clave2;
	int valor1, valor2;

	cin >> categoria;

	while (categoria != "FIN")
	{
		cin >> clave1;

		unordered_map<string, int> parejas_puntos;
		int numPartidos = 0, puntosCampeon;
		string campeon = clave1; bool empate = false;

		while (clave1 != "FIN")
		{
			cin >> valor1 >> clave2 >> valor2;

			//Todos los datos de este partido leidos en este punto.
			if (valor1 > valor2)
			{
				parejas_puntos[clave1] += 2;
				parejas_puntos[clave2] += 1;
			}
			else
			{
				parejas_puntos[clave2] += 2;
				parejas_puntos[clave1] += 1;
			}

			numPartidos++; cin >> clave1;
		}

		if (numPartidos > 0)
		{
		puntosCampeon = parejas_puntos[campeon];

		for (auto it = parejas_puntos.begin(); it != parejas_puntos.end(); ++it)
		{
			if (it->first != campeon)
			{
				if (it->second > puntosCampeon)
				{
					campeon = it->first; empate = false;
					puntosCampeon = it->second;
				}
				else if (it->second == puntosCampeon) empate = true;
			}
		}
		}

		if (empate || numPartidos == 0)
			cout << "EMPATE 0\n";
		else
			cout << campeon << " " << parejas_puntos.size()*(parejas_puntos.size() - 1)  - numPartidos << '\n';

		cin >> categoria;
	}



	return 0;
}
