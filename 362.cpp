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
  int day, month;

  while(numCases--)
  {
    cin >> day >> month;

    if(day == 25 && month == 12)  cout << "SI\n";
    else                          cout << "NO\n";
  }

  return 0;
}
