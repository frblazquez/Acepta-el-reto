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
  int hour, min; char c;
  cin >> hour >> c >> min;

  while(hour!=0 || min!=0)
  {
    cout << 60*(23-hour)+(60-min) << '\n';
    cin >> hour >> c >> min;
  }

  return 0;
}
