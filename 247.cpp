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
  int numDatums, act, bef; bool increasing;
  cin >> numDatums;

  while(numDatums)
  {
    increasing = true;
    cin >> bef;

    for(int i = 1; i < numDatums; i++)
    {
      cin >> act;

      if(increasing && act <= bef)
        increasing = false;

      bef = act;
    }

    if(increasing)  cout << "SI\n";
    else            cout << "NO\n";
    
    cin >> numDatums;
  }

  return 0;
}
