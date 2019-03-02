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

int main()
{
  long long int numPeople, act, before; cin >> numPeople;
  bool ascendent, descendent;

  while(numPeople)
  {
    cin >> before;
    ascendent  = true;
    descendent = true;

    for(int i = 1; i < numPeople; i++)
    {
      cin >> act;

      if(ascendent  && act <= before)  ascendent  = false;
      if(descendent && act >= before)  descendent = false;

      before = act;
    }

    if(ascendent || descendent)
      cout << "DALTON" << endl;
    else
      cout << "DESCONOCIDOS" << endl;

    cin >> numPeople;
  }

  return 0;
}
