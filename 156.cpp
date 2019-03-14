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
  scanf("%d", &last);

  while(last != -1)
  {
    scanf("%d", &num); total = 0;

    while(num != -1)
    {
      total += abs(num - last);
      last = num;

      scanf("%d", &num);
    }

    cout << total << '\n';
    scanf("%d", &last);
  }

  return 0;
}
