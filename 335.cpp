/*
*   Copyright © 2019
*
*   Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
*
*   Double degree in Mathematics - Computer engineering
*   Complutense University, Madrid
*
*   Statement: Number of marbles necessaries for building a pyramid.
*/

#include <iostream>
using namespace std;

int main()
{
  int numCases; cin >> numCases;
  long long int height;

  while(numCases--)
  {
    cin >> height;

    cout << (height*(height+1)*(height+2))/6 << '\n';
  }

  return 0;
}
