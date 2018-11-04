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
  int numPositions,position,num;

  cin >> numPositions >> position >> num;

  while(numPositions)
  {
    if(position+num <= numPositions) cout << position+num << '\n';
    else                             cout << numPositions+numPositions-position-num << '\n';

    cin >> numPositions >> position >> num;
  }

  return 0;
}
