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
using namespace std;

int main()
{
	int numExamenes, numRecordados;
	cin >> numExamenes >> numRecordados;

	while (cin)
	{
		unordered_map<int, int> mapa; 
		int examen, numCopias = 0, numDetecciones = 0;

		for (int i = 0; i < numExamenes; i++)
		{
			cin >> examen;

			if (mapa.count(examen) != 0)
			{
				numCopias++;

				if (i - mapa[examen] <= numRecordados)
					numDetecciones++;
			}
			
			mapa[examen] = i;
		}

		cout << numCopias << " " << numDetecciones << '\n';
		cin >> numExamenes >> numRecordados;
	}

	return 0;
}
