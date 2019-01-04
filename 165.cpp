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
  int num; cin >> num;

  while(num>= 0)
  {
    bool hiperOdd = true;

    while(num != 0 && hiperOdd)
    {
      hiperOdd &= (num%2 == 0);
      num /= 10;
    }

    if(hiperOdd)  cout << "SI\n";
    else          cout << "NO\n";
    cin >> num;
  }

  return 0;
}
