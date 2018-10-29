/*
*   Copyright © 2018
*
*   Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
*
*   Double degree in Mathematics-Computer engineering.
*   Complutense university, Madrid.
*
*/

#include <set>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int numIng; string aux;
	set<string> leGustan, noLegustan;

	cin >> numIng;

	while (numIng != 0)
	{
		for (int i = 0; i < numIng; i++)
		{
			cin >> aux;

			if (aux == "SI:")
			{
				cin >> aux;

				while (aux != "FIN")
				{
					leGustan.insert(aux);
					noLegustan.erase(aux);
					cin >> aux;
				}
			}
			else if(aux == "NO:")
			{
				cin >> aux;

				while (aux != "FIN")
				{
					if (leGustan.count(aux) == 0)
						noLegustan.insert(aux);
					cin >> aux;
				}
			}
		}

		for (std::set<std::string>::iterator it = noLegustan.begin(); it != noLegustan.end();)
        {	
          std::cout << *it;
          if(++it != noLegustan.end()) 
          std::cout << ' ';
          
        }
		std::cout << "\n";
		cin >> numIng;
		leGustan.clear();
		noLegustan.clear();
	}

	return 0;
}
