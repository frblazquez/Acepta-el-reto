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

int alturaArbol(int numHijos);

int main()
{
  int numCasos, hijosRaiz; cin >> numCasos;

  while(numCasos--)
  {
    cin  >> hijosRaiz;
    cout << alturaArbol(hijosRaiz) << '\n';
  }

  return 0;
}

int alturaArbol(int numHijos)
{
  int altura = 0, alturaHijo, aux;

  for(int i = 0; i < numHijos; i++)
  {
    cin >> aux;

    alturaHijo = alturaArbol(aux);

    if(alturaHijo > altura) altura = alturaHijo;
  }

  return altura + 1;
}
