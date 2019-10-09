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
  int numCases; cin >> numCases;
  int rabbit, horse;

  while(numCases--)
  {
    cin >> rabbit >> horse;
    cout << rabbit*100/(rabbit+horse) << '\n';
  }

  return 0;
}
