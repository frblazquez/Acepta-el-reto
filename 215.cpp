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

void postFromPreIn(vector<int> const& preorden, int ini1, int fin1, vector<int> const& inorden, int ini2, int fin2, vector<int> &postorden);

int main()
{
	int aux;
	cin >> aux;

	while (aux != -1)
	{
		vector<int> preorden, inorden;
		do{ preorden.push_back(aux); cin >> aux; } while (aux != -1); cin >> aux;
		do{ inorden.push_back(aux); cin >> aux; } while (aux != -1);
		/* Aquí están los recorridos leídos. */

		//bintree<int> construccion = arbolPreInorden(preorden, 0, preorden.size(), inorden, 0, inorden.size());
		vector<int> postorden; 
		postFromPreIn(preorden, 0, preorden.size(), inorden, 0, inorden.size(), postorden);

		for (int i = 0; i < postorden.size() - 1; i++)
			cout << postorden[i] << " ";
			cout << postorden[postorden.size() - 1] << '\n';

		cin >> aux;
	}

	return 0;
}

void postFromPreIn(vector<int> const& preorden, int ini1, int fin1, vector<int> const& inorden, int ini2, int fin2, vector<int> &postorden)
{
	if (fin1 - ini1 > 1) //Hay al menos dos elementos
	{
		int aux = ini2; while (preorden[ini1] != inorden[aux]) aux++;
		/* Aquí se tiene que la raiz del árbol generado está en preorden[ini] y en inorden[aux]. */

		int dif = aux - ini2;
		postFromPreIn(preorden, ini1 + 1, ini1 + dif + 1, inorden, ini2, ini2 + dif, postorden);
		postFromPreIn(preorden, ini1 + dif + 1, fin1, inorden, aux + 1, fin2, postorden);
		postorden.push_back(preorden[ini1]);
	}
	else if (fin1 - ini1 == 1) //Hay un solo elemento
	{
		postorden.push_back(preorden[ini1]);
	}	
}
