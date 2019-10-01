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
    int numCases; cin >> numCases;
    int numHigh, numWide, numWhite;

    while(numCases--)
    {
      cin >> numHigh >> numWide;

      numWhite = (numWide/2 + numWide%2)*(numHigh/2 + numHigh%2) + (numWide/2)*(numHigh/2);

      cout << numWhite << " " << numHigh*numWide - numWhite << '\n';
    }

    return 0;
}
