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
#include <iomanip>
using namespace std;

int main()
{
  int numCases, maxDrops, hours, mins, seconds;
  cin >> numCases;

  while(numCases--)
  {
    cin >> maxDrops;

    seconds = maxDrops%60; maxDrops /= 60;
    mins = maxDrops%60; maxDrops /= 60;
    hours = maxDrops;

    cout << setfill('0') << setw(2) << hours << ':' << setfill('0') << setw(2) << mins << ':' << setfill('0') << setw(2) << seconds << '\n';
  }


	return 0;
}
