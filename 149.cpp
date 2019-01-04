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
  int numBulls; cin >> numBulls;

  while(cin)
  {
    int max, aux; cin >> max;

    for(int i = 1; i < numBulls; i++)
    {
      cin >> aux;

      if(aux > max) max = aux;
    }

    cout << max << '\n';
    cin >> numBulls;
  }

  return 0;
}
