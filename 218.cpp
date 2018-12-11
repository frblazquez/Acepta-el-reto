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
#include <vector>
using namespace std;

void preFromInPost(vector<int> const& inorden, int ini1, int fin1, vector<int> postorden, int ini2, int fin2, vector<int> &preorden);

int main()
{
	int numNodos;
	cin >> numNodos;

	while (numNodos)
	{
		vector<int> inorden, postorden; int aux;
		for (int i = 0; i < numNodos; i++)
		{cin >> aux; inorden.push_back(aux);}
		for (int i = 0; i < numNodos; i++)
		{cin >> aux; postorden.push_back(aux);}
		/* Inorden y postorden leídos. */

		vector<int> preorden; 
		preFromInPost(inorden, 0, numNodos, postorden, 0, numNodos, preorden);

		for (int i = 0; i < numNodos - 1; i++)
			cout << preorden[i] << " ";
			cout << preorden[numNodos - 1] << '\n';

		cin >> numNodos;
	}

	return 0;
}

void preFromInPost(vector<int> const& inorden, int ini1, int fin1, vector<int> postorden, int ini2, int fin2, vector<int> &preorden)
{
	if (fin1 - ini1 == 1) //El arbol solo tiene raiz
	{preorden.push_back(postorden[fin2 - 1]);}

	else if (fin1 - ini1 > 1) //Hemos llamado con un segmento grande
	{
		int aux = ini1; while (inorden[aux] != postorden[fin2 - 1]) aux++;
		
		preorden.push_back(postorden[fin2 - 1]);
		preFromInPost(inorden, ini1, aux, postorden, ini2, ini2 + aux - ini1, preorden);
		preFromInPost(inorden, aux + 1, fin1, postorden, ini2 + aux - ini1, fin2 - 1, preorden);
	}
}
