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
  int init, factor, cells; cin >> init >> factor >> cells;

  while(init || factor || cells)
  {
    long long int total = init, power = factor;

    for(int i = 1; i < cells; i++)
    {
      total += init*power;
      power *= factor;
    }

    cout << (cells==0 ? 0 : total) << '\n';
    cin >> init >> factor >> cells;
  }


  return 0;
}
