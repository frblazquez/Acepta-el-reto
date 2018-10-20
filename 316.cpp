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
  int numCases; cin >> numCases;
  int numReg, bestIni, bestFin, actualIni;
  int bestResult, actualResult, dayResult;

  for(int i = 0; i < numCases; i++)
  {
    cin >> numReg;

    bestIni = 1; bestFin = 1; actualIni = 1;
    actualResult = 0; bestResult = 0;

    for(int j = 1; j <= numReg; j++)
    {
       cin >> dayResult;

       actualResult += dayResult;

       if(actualResult <= 0)
       {
         actualResult = 0;
         actualIni = j+1;
       }else if(actualResult > bestResult || (actualResult == bestResult && j-actualIni < bestFin - bestIni))
       {
         bestIni = actualIni;
         bestFin = j;
         bestResult = actualResult;
       }

    }

    cout << bestIni << " " << bestFin << '\n';
  }

  return 0;
}
