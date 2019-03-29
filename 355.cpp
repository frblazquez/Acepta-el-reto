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
  int numCases, year; cin >> numCases;

  while(numCases--)
  {
    cin >> year;

    if(year%4 == 0 && (year%100!=0 || year%400==0))
      cout << 29 << '\n';
    else
      cout << 28 << '\n';    
  }

  return 0;
}
