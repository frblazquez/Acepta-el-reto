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
  int numCases, num; cin >> numCases;

  while(numCases--)
  {
    cin >> num;

    if(num == 0 || num == 1) cout << "1\n";
    else if(num == 2)        cout << "2\n";
    else if(num == 3)        cout << "6\n";
    else if(num == 4)        cout << "4\n";
    else                     cout << "0\n";
  }

  return 0;
}
