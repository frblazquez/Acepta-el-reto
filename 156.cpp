/*
*   Copyright © 2019
*
*   Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
*
*   Double degree in Mathematics - Computer engineering
*   Complutense University, Madrid
*
*/

#include <iostream>
using namespace std;

int main()
{
  int num, last, total;
  cin >> last;

  while(last >= 0)
  {
    cin >> num; total = 0;

    while(num != -1)
    {
      total += abs(num - last);
      last = num;

      cin >> num;
    }

    cout << total << '\n';
    cin >> last;
  }

  return 0;
}
