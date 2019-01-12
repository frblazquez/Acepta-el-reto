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
  int numCases; cin >> numCases;

  while(numCases--)
  {
    int rows, cols;

    cin >> rows >> cols;
    cout << (rows+1)*cols + (cols+1)*rows << '\n';
  }

  return 0;
}
