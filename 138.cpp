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

int zerosFactorial(int number)
{
  long long int power = 5;
  int zeros = 0;

  while(power <= number)
  {
    zeros += number/power;
    power *= 5;
  }

  return zeros;
}

int main()
{
  int numCases,number; cin >> numCases;

  while(numCases--)
  {
    cin >>  number;
    cout << zerosFactorial(number) << '\n';
  }

  return 0;
}
