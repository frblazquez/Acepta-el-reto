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
#include <string>
using namespace std;

int main()
{
  int numCasos; cin >> numCasos;
  int superficie, estimacion;

  while(numCasos--)
  {
    cin >> superficie >> estimacion;

    if(90*120*estimacion < superficie || 45*90*estimacion > superficie)
      cout << "NO\n";
    else
      cout << "SI\n";
  }

  return 0;
}
