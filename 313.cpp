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
  int numCasos; cin >> numCasos;
  int initValue, balance;

  while(numCasos--)
  {
    cin >> initValue >> balance;

    if(initValue + balance >= 0)  cout << "SI\n";
    else                          cout << "NO\n";
  }

  return 0;
}
