/*
*   Copyright © 2018
*
*   Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
*
*   Double degree in Mathematics-Computer engineering.
*   Complutense university, Madrid.
*
*/

/*
    For this problem I first considered a divide an conquer solution based on
    the quicksort algorithm but I wasn't really able to see how to do it in a
    lower time cost than O(nlog(n)) so I finally used the sort() method from
    the "algorithm" library and then compare both vectors.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  int numTeams,aux; cin >> numTeams;

  while(cin)
  {
    vector<int> attack, defend;

    for(int i = 0; i < numTeams; i++)
    {cin >> aux; attack.push_back(aux);}
    for(int i = 0; i < numTeams; i++)
    {cin >> aux; defend.push_back(aux);}

    sort(attack.begin(), attack.end());
    sort(defend.begin(), defend.end());

    int citiesDefended = 0;
    int attackedEnd = numTeams-1, defendedEnd = numTeams-1;

    while(attackedEnd>=0 && defendedEnd>= 0)
    {
      if(defend[defendedEnd] >= attack[attackedEnd])
      {
        citiesDefended++;
        defendedEnd--;
      }

       attackedEnd--;
    }

    cout << citiesDefended << '\n';
    cin >> numTeams;
  }

  return 0;
}
