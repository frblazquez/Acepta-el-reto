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
  int numDays; cin >> numDays;

  int sumaTotal, sumaPrimeros, sumaFinales, counter, aux;
  int minimCounter, minVariation;

  vector<int> registro;

  while(numDays)
  {
    sumaTotal = 0; sumaPrimeros = 0; registro.clear();

    //Get the total add of values and keep them
    for(int i = 0; i < numDays; i++)
    {
      cin >> aux;

      sumaTotal += aux;
      registro.push_back(aux);
    }

    sumaFinales = sumaTotal;

    //We discover wich point is near of the middle wear
    counter = 0; minimCounter = 0; minVariation = abs(sumaTotal);

    while(sumaPrimeros != sumaFinales && counter < registro.size())
    {
      sumaPrimeros += registro[counter];
      sumaFinales  -= registro[counter];

      counter++;

      if(abs(sumaPrimeros - sumaFinales) < minVariation)
      {
        minimCounter = counter;
        minVariation = abs(sumaPrimeros - sumaFinales);
      }
    }

    //Then we print the solution
    cout << minimCounter << endl;
    cin >> numDays;
  }

  return 0;
}
