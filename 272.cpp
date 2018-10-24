/*
*   Copyright © 2018
*
*   Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
*
*   Double degree in Mathematics-Computer engineering.
*   Complutense university, Madrid.
*   
*/

/*
    This problem could easily be solved iteratively, however, and following
    the teacher advise, I prefer to solve it recursively just for practise.
*/

#include <iostream>
using namespace std;

int toSixthBase(int decimalNumber);

int main()
{
  int numCases; cin >> numCases;
  int decimalNumber;

  while(numCases--)
  {
    cin >> decimalNumber;
    cout << toSixthBase(decimalNumber) << '\n';
  }

  return 0;
}

int toSixthBase(int decimalNumber)
{
    if(decimalNumber < 6)  return decimalNumber;
    else                   return decimalNumber%6 + 10*toSixthBase(decimalNumber/6);
}
