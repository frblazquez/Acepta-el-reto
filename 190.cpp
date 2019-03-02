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
  int num, den; cin >> num >> den;
  long long int result;

  while(num >= den)
  {
    result = 1;

    while(num > den)
    {result *= num; num--;}

    cout << result << '\n';
    cin >> num >> den;
  }

  return 0;
}
