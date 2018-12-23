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
#include <map>
#include <string>
using namespace std;



int main()
{
	int numEjercicios; cin >> numEjercicios;

	while (numEjercicios)
	{
		map<string, int> mapa; string alumno,  aux;

		for (int i = 0; i < numEjercicios; i++)
		{
			cin.ignore();
			getline(cin, alumno); cin >> aux;

			if (aux == "INCORRECTO")
				mapa[alumno] -= 1;
			else
				mapa[alumno] += 1;
		}

		for (auto it = mapa.begin(); it != mapa.end(); ++it)
			if (it->second != 0) cout << it->first + ", " << it->second << '\n';

		cout << "---\n";
		cin >> numEjercicios;
	}
	

	return 0;
}
