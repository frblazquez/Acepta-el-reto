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
  int numHs, numMs, numLectures; char c;

  while(numCases--)
  {
    numHs = 0; numMs = 0;
    cin >> numLectures; cin.get(c);
    
    do{
      cin.get(c);

      if(c == 'M')        numMs++;
      else if (c == 'H')  numHs++;
    }while(c != '\n');

    if(numHs == numMs) cout << "POSIBLE\n";
    else               cout << "IMPOSIBLE\n";
  }

  return 0;
}
