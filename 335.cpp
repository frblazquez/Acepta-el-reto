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
  int numCases, height; cin >> numCases;
  unsigned long long int marbles, aux, aux2;

  while(numCases--)
  {
    cin >> height;

    aux  = (height*(height+1))/2;
    aux2 = (aux*(2*height+1))/3;

    marbles = (aux + aux2)/2;

    cout << marbles << '\n';
  }

  return 0;
}
