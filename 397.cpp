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
  int numCases, num; cin >> numCases;

  while(numCases--)
  {
    cin >> num;

    if(num%3 == 1)  cout << "NO\n";
    else            cout << "SI\n";    
  }

  return 0;
}
