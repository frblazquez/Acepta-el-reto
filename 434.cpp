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
  int pigeons,niches;

  while(numCases--)
  {
    cin >> pigeons >> niches;

    if(pigeons>niches)  cout << "PRINCIPIO\n";
    else                cout << "ROMANCE\n";
  }

  return 0;
}
