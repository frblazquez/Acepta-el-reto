/*
*   Copyright © 2018
*
*   Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
*
*   Double degree in Mathematics-Computer engineering.
*   Complutense university, Madrid.
*
*/

#include <stack>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

string deshazUltCodificacion(string const& clave);
string deshazPrimCodificacion(string const& clave);
bool esVocal(char c);
void vaciaStack(stack<char> &pila, string &palabra);

int main()
{
	string mensajeCifrado;

	getline(cin, mensajeCifrado);

	while (cin)
	{
		string mensajeDescifrado;

		mensajeDescifrado = deshazUltCodificacion(mensajeCifrado);
		mensajeDescifrado = deshazPrimCodificacion(mensajeDescifrado);

		cout << mensajeCifrado << " => "<< mensajeDescifrado << '\n';

		getline(cin, mensajeCifrado);
	}

	return 0;
}

string deshazUltCodificacion(string const& clave)
{
	string aux = "";
	stack<char> ultimos;	int numUltimos;
	queue<char> primeros;	int numPrimeros;

	for (int i = 0; i < clave.size(); i++)
	{
		if (i % 2 == 0)	primeros.push(clave[i]);
		else            ultimos.push(clave[i]);
	}

	numUltimos = ultimos.size();
	numPrimeros = primeros.size();

	for (int i = 0; i < numPrimeros; i++)
	{
		aux.push_back(primeros.front());
		primeros.pop();
	}
	for (int i = 0; i < numUltimos; i++)
	{
		aux.push_back(ultimos.top());
		ultimos.pop();
	}

	return aux;
}
string deshazPrimCodificacion(string const& clave)
{
	string aux = "";
	stack<char> consonantes;

	for (int i = 0; i < clave.size(); i++)
	{
		if (esVocal(clave[i]))
		{
			vaciaStack(consonantes, aux);
			aux.push_back(clave[i]);
		}
		else
			consonantes.push(clave[i]);
	}

	vaciaStack(consonantes, aux);

	return aux;
}
bool esVocal(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c== 'A' || c== 'E' || c== 'I' || c== 'U' || c == 'O';
}
void vaciaStack(stack<char> &pila, string &palabra)
{
	while (pila.size() > 0)
	{
		palabra.push_back(pila.top());
		pila.pop();
	}
}
