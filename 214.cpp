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
	int numRegistros; cin >> numRegistros;

	while (numRegistros)
	{
		unordered_map<string, int> reyesRegistrados;
		 int numRequest; string nombreRey;

		for (int i = 0; i < numRegistros; i++)
		{
			cin >> nombreRey;
			reyesRegistrados[nombreRey]++;
		}

		cin >> numRequest;
		for (int i = 0; i < numRequest; i++)
		{
			cin >> nombreRey;
			cout << ++reyesRegistrados[nombreRey] << '\n';
		}

		cout << '\n';
		cin >> numRegistros;
	}

	return 0;
}
