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
using namespace std;

int main()
{
  int numCases, suma, etapa, aux; cin >> numCases;

  while(numCases--)
  {
    suma = 0; etapa = 0;

  	cin >> aux;

    while(aux!=0)
    {
      etapa += aux;
      suma += 2*etapa;
      cin >> aux;
    }

    cout << suma << '\n';
  }

  return 0;
}
