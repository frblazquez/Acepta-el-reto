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
#include <list>
#include <string>
using namespace std;

string transformaTeclado(string const& entrada);

int main()
{
	string cadenaTeclado, salidaPantalla;
	list<char> prueba;

	getline(cin, cadenaTeclado);

	while (cin)
	{
		salidaPantalla = transformaTeclado(cadenaTeclado);

		cout << salidaPantalla << '\n';

		prueba.clear();

		getline(cin, cadenaTeclado);
	}

	return 0;
}

string transformaTeclado(string const& entrada)
{
	string aux = ""; int indice = 0;
	list<char> cola;
	auto index = cola.end();

	for (char c : entrada)
	{
		switch (c)
		{
		case '+':
		{
			index = cola.end();
		}break;
		case '-':
		{
			index = cola.begin();
		}break;
		case '*':
		{
			if (index != cola.end())
				index++;
		}break;
		case '3':
		{
			if (index != cola.end())
			index = cola.erase(index);

		}break;
		default:
		{
			cola.insert(index, c);
		}
		}
	}


	//Vaciamos la cola en aux
	while(cola.size() > 0)
	{
		aux.push_back(cola.front());
		cola.pop_front();
	}

	return aux;
}
