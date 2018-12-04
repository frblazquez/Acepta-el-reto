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
  int numCases, value1, value2;
  char c;
  cin >> numCases;

  while(numCases--)
  {
    cin >> value1 >> c >> value2;

    if(min(value1, value2)%2 == 0 && abs(value1-value2)==1)   cout << "SI\n";
    else                                                      cout << "NO\n";
  }

  return 0;
}
