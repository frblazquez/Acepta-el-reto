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
  int dividend, divisor;

  while(numCases--)
  {
    cin >> dividend >> divisor;

    if(divisor == 0)  cout << "DIV0\n";
    else
    {
      int quotient = dividend/divisor, remaind = dividend%divisor;

      if(remaind == 0);

      else if(dividend < 0 && divisor < 0)
      {quotient += 1; remaind -= divisor;}

      else if(dividend < 0 && divisor > 0)
      {quotient -= 1; remaind += divisor;}

      cout << quotient << " " << remaind << '\n';
    }

  }

  return 0;
}
