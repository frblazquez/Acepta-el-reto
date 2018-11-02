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

void allSolutions(int choc, int van, int numChoc, int numVan, string &partialSol, bool lastSol);

int main()
{
  int numCases; cin >> numCases;
  int numChoc, numVanila; string aux;

  while(numCases--)
  {
    cin >> numChoc >> numVanila;  aux = "";
    allSolutions(numChoc, numVanila, 0, 0, aux, !numChoc || !numVanila);
    cout << endl;
  }

  return 0;
}

void allSolutions(int choc, int van, int numChoc, int numVan, string &partialSol, bool lastSol)
{
    if(numChoc + numVan == choc + van)  cout << partialSol << (!lastSol ? " " : "");
    else
    {
        bool isTheLast = (numChoc == 0 && van == numVan);

        if(numChoc < choc)
        {
          partialSol.push_back('C');
          allSolutions(choc, van, numChoc+1, numVan, partialSol, lastSol || isTheLast);
          partialSol.pop_back();
        }

        if(numVan < van)
        {
          partialSol.push_back('V');
          allSolutions(choc, van, numChoc, numVan+1, partialSol, lastSol || isTheLast);
          partialSol.pop_back();
        }
    }
}
