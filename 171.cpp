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


int main()
{
	int numMontanas; cin >> numMontanas;

	while (numMontanas)
	{
		vector<int> cordillera; int aux;

		for (int i = 0; i < numMontanas; i++){
			cin >> aux; cordillera.push_back(aux);
		}

		int maxDcha = cordillera[numMontanas - 1];
		int numAbadias = 1;

		for (int i = numMontanas - 2; i >= 0; i--){
			if (cordillera[i] > maxDcha)
			{
				maxDcha = cordillera[i];
				numAbadias++;
			}
		}

		cout << numAbadias << '\n'; 

		cin >> numMontanas;
	}

	return 0;
}
