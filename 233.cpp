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

const int MAX_DIGITS = 112; // 1000/9 +1

int main()
{
  int sumDigits; cin >> sumDigits;
  char result[MAX_DIGITS];

  while(sumDigits)
  {
    int i = 0;

    while(sumDigits >= 9){
      result[i] = '9';
      sumDigits -= 9;
      i++;
    }

    if(sumDigits != 0)
      cout << sumDigits;

    while(i > 0){
      i--;
      cout << result[i];
    }

    cout << '\n';
    cin >> sumDigits;
  }

  return 0;
}
