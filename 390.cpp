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

  int availableMg, availableCi, availableAm;
  string colours; bool possible;

  while(numCasos--)
  {
    cin >> availableMg >> availableAm >> availableCi;
    getline(cin, colours); possible = true;

    for(int i = 0; i<colours.size() && possible; i++)
    {
      switch(colours[i])
      {
        case 'M':   availableMg--;                                break;
        case 'A':   availableAm--;                                break;
        case 'C':   availableCi--;                                break;
        case 'R':  {availableMg--; availableAm--;}                break;
        case 'L':  {availableMg--; availableCi--;}                break;
        case 'V':  {availableCi--; availableAm--;}                break;
        case 'N':  {availableMg--; availableCi--; availableAm--;} break;
        default: /* Intentionally */;
      }

      possible = availableMg >= 0 && availableCi >= 0 && availableAm >= 0;
    }

    if(possible)  cout << "SI " << availableMg << " " << availableAm << " " << availableCi << '\n';
    else          cout << "NO\n";
  }

  return 0;
}
