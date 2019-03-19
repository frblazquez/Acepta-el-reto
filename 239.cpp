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
  int numDays, numSenders, totalTimeSec;
  int days, hours, mins, secs;
  cin >> numDays >> numSenders;

  while(numDays || numSenders)
  {
    totalTimeSec = numDays*24*6*numSenders;

    secs  = totalTimeSec%60; totalTimeSec /= 60;
    mins  = totalTimeSec%60; totalTimeSec /= 60;
    hours = totalTimeSec%24; totalTimeSec /= 24;
    days  = totalTimeSec;

    cout << days << ':' << setw(2) << setfill('0') << hours
                 << ':' << setw(2) << setfill('0') << mins
                 << ':' << setw(2) << setfill('0') << secs << '\n';

    cin >> numDays >> numSenders;
  }

  return 0;
}
