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
  int numCases; cin >> numCases;
  long long int num1, num2, num3;

  while(numCases--)
  {
    cin >> num1 >> num2 >> num3;

    if(num1 <= num2)
    {
      if(num3 <= num1)
        cout << num3 << ' ' << num1 << ' ' << num2 << '\n';
      else if(num3 <= num2)
        cout << num1 << ' ' << num3 << ' ' << num2 << '\n';
      else
        cout << num1 << ' ' << num2 << ' ' << num3 << '\n';
    }
    else
    {
      if(num3 <= num2)
        cout << num3 << ' ' << num2 << ' ' << num1 << '\n';
      else if(num3 <= num1)
        cout << num2 << ' ' << num3 << ' ' << num1 << '\n';
      else
        cout << num2 << ' ' << num1 << ' ' << num3 << '\n';
    }
  }

  return 0;
}
