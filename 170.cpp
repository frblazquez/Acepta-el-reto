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
#include <cmath>
using namespace std;

int main()
{
  int num, result; cin >> num;

  while(num)
  {
    result = (-1 + sqrt(1 + 8*num))/2;

    cout << result << " " << num - (result*(result+1))/2 << '\n';
    cin >> num;
  }

  return 0;
}
