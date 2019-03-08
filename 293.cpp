/*
*   Copyright © 2019
*
*   Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
*
*   Double degree in Mathematics-Computer engineering.
*   Complutense university, Madrid.
*
*/

#include <iostream>
using namespace std;

const int LEGS_INSECT    = 6;
const int LEGS_ARTHROPOD = 8;
const int LEGS_CRUSTACEAN=10;
const int LEGS_CENTIPEDE = 2;

int main()
{
  int numCases, legs, aux1, aux2;
  cin >> numCases;

  while(numCases--)
  {
    legs = 0;

    cin >> aux1;   legs += aux1*LEGS_INSECT;
    cin >> aux1;   legs += aux1*LEGS_ARTHROPOD;
    cin >> aux1;   legs += aux1*LEGS_CRUSTACEAN;
    cin >> aux1;
    cin >> aux2;   legs += aux1*LEGS_CENTIPEDE*aux2;

    cout << legs << '\n';
  }

  return 0;
}
