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
  int numCountries; cin >> numCountries;

  while(numCountries)
  {
    unsigned long long int numPairs = 0, numForeing, numThisCountry;

    cin >> numForeing;

    for(int i = 1; i < numCountries; i++)
    {
      cin >> numThisCountry;

      numPairs   += numThisCountry*numForeing;
      numForeing += numThisCountry;
    }

    cout << numPairs << '\n';
    cin >> numCountries;
  }

  return 0;
}
