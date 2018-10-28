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
#include <iostream>
using namespace std;



int main()
{
	int numNinos, numSaltos;
	queue<int> cola;

	cin >> numNinos >> numSaltos;

	while (numNinos != 0 || numSaltos != 0)
	{		
		for (int i = 1; i <= numNinos; i++)
			cola.push(i);

		while (cola.size() != 1)
		{
			for (int i = 0; i < numSaltos; i++)
			{
				cola.push(cola.front());
				cola.pop();
			}
				cola.pop();
		}

		cout << cola.front() << '\n';
		
		cola.pop();			//vacía la cola1

		cin >> numNinos >> numSaltos;
	}

	return 0;
}
