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
  int numOp; cin >> numOp;
  int max, act, aux;

  while(numOp)
  {
    cin >> aux; max = aux; act = aux;

    for(int i = 1; i < numOp; i++)
    {
      cin >> aux;
      act += aux; if(act>max) max = act;
    }

    cout << act << " " << max << '\n';
    cin >> numOp;
  }

  return 0;
}
