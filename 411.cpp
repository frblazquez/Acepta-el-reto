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
  int maxWeight; cin >> maxWeight;

  while(maxWeight)
  {
    int weight = 0, numElephants = 0, aux;

    cin >> aux;

    while(aux != 0 && weight+aux<= maxWeight)
    {
      weight+=aux;
      numElephants++;
      cin >> aux;
    }

    while(aux != 0) cin >> aux;

    cout << numElephants << '\n';
    cin >> maxWeight;
  }

  return 0;
}
