/*
*   Copyright © 2018
*
*   Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
*
*   Double degree in Mathematics-Computer engineering.
*   Complutense university, Madrid.
*
*/

#include <queue>
#include <stack>
#include <iostream>
using namespace std;


int main()
{
	int tortitas, numVolteos, bloque;

	cin >> tortitas;

	while (tortitas != -1)
	{
		stack<int> pila;
		queue<int> paleta;

		//////BLOQUE DE LECTURA/////////
		pila.push(tortitas);

		cin >> tortitas;
		while (tortitas != -1)
		{
			pila.push(tortitas);
			cin >> tortitas;
		}
		//////BLOQUE DE LECTURA/////////

		cin >> numVolteos;

		for (int i = 0; i < numVolteos; i++)
		{
			/////////EJECUCION DEL VOLTEO/////////
			cin >> bloque;

			for (int j = 0; j < bloque; j++)
			{
				paleta.push(pila.top());
				pila.pop();
			}

			for (int j = 0; j < bloque; j++)
			{
				pila.push(paleta.front());
				paleta.pop();
			}
			/////////EJECUCION DEL VOLTEO//////////
		}

		cout << pila.top() << '\n';

		cin >> tortitas;
	}


}
