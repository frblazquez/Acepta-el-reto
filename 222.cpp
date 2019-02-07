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
  int result, power;
  int x, n; cin >> x >> n;

  while(cin)
  {
    power = 1;
    result = 1;

    for(int i = 0; i < n; i++)
    {
      power = (power*x)%1000007;
      result = (result+power)%1000007;
    }

    cout << result << '\n';
    cin >> x >> n;
  }

  return 0;
}
