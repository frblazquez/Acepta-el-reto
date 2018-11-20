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

  int numPicos, numValles, numLecturas;
  int actual, anterior, siguiente;

  while(numCases--)
  {
    numPicos = 0; numValles = 0;

    cin >> numLecturas >> anterior;

    if(numLecturas >= 2) cin >> actual;
    if(numLecturas <= 2) cout << "0 0\n";
    else
    {
      for(int i = 2; i < numLecturas; i++)
      {
        cin >> siguiente;

             if(anterior > actual && siguiente > actual) numValles++;
        else if(anterior < actual && siguiente < actual) numPicos++;

        anterior = actual; actual = siguiente;
      }

      cout << numPicos << " " << numValles << '\n';
    }
  }

  return 0;
}
