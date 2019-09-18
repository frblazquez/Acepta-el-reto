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
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int numCases; cin >> numCases;
  int longTunel, numRadios, pos, ratio;
  int until, radioIdx;

  while(numCases--)
  {
    cin >> longTunel >> numRadios;
    vector<pair<int,int>> transmitters;

    for(int i = 0; i < numRadios; i++)
    {
      cin >> pos >> ratio;

      transmitters.push_back({pos, ratio});
    }

    sort(transmitters.begin(), transmitters.end());

    until = 0; radioIdx = 0;

    while(until < longTunel && radioIdx < transmitters.size())
    {
      if(until >= transmitters[radioIdx].first - transmitters[radioIdx].second)
        until = transmitters[radioIdx].first + transmitters[radioIdx].second;

      radioIdx++;
    }

    if(until >= longTunel)  cout << "SI\n";
    else                    cout << "NO\n";
  }


  return 0;
}
