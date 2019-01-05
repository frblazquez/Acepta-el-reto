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
  int x1, x2, y1, y2;
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  
  while(x1<=x2 && y1<=y2)
  {
 	cout << (x2-x1)*(y2-y1) << '\n';
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  }
  
  
  return 0;
}
