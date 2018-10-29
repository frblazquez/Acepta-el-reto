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

int numPossibles(int width, int top);

int main()
{
  int width, top; cin >> width >> top;

  while(width || top)
  {
    cout << numPossibles(width, top) << '\n';
    cin >> width >> top;
  }

  return 0;
}

int numPossibles(int width, int top)
{
    if(width < 10 || top < 10)  return 0;
    if(width < top)             return top/width + numPossibles(width, top - (top/width)*width);
    else                        return width/top + numPossibles(width - (width/top)*top, top);
}
