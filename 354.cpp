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
  int numElems, elem; cin >> numElems;

  while(numElems)
  {
    cin >> elem;
    int maxBefore = elem, max = elem, numKids = 1;

    for(int i = 1; i < numElems; i++)
    {
      cin >> elem;

      if(elem > max)  max = elem;

      if(elem <= maxBefore) {numKids = i+1; maxBefore = max;}
    }

    cout << numKids << '\n';
    cin >> numElems;
  }

  return 0;
}


// DIVIDE AND CONQUER SOLUTION:
/*
int numKids(vector<int> const& v, int ini, int fin, int &minKid, int &maxKid, int &lastKidPos)
{
  if(fin-ini == 1)
  {
    minKid = v[ini];
    maxKid = v[ini];
    lastKidPos = ini;

    return 1;
  }
  else
  {
    int mid = (ini + fin)/2;

    int kidsA, minKidsA, maxKidsA, lastKidA;
    int kidsB, minKidsB, maxKidsB, lastKidB;

    kidsA = numKids(v , ini, mid, minKidsA, maxKidsA, lastKidA);
    kidsB = numKids(v,  mid, fin, minKidsB, maxKidsB, lastKidB);
  //-----------------------------------------------------------------------------------//

    if(minKidsB <= maxKidsA) //minimum in b is a kid     (=> all kids in B are really kids)
    {
      maxKid = max(maxKidsA, maxKidsB);
      minKid = min(minKidsA, minKidsB);
      lastKidPos = lastKidB;

      //Correct value for the maximum kid
      while(lastKidA+1 < mid) {lastKidA++; if(v[lastKidA] > maxKid) maxKid = v[lastKidA];}
      //Correct value for the last kid position
      while(lastKidPos+1 < fin && v[lastKidPos+1] <= maxKid) lastKidPos++;

      return lastKidPos-ini + 1;
    }
    else                     //minimum in b is not a kid (=> any element in B is a kid)
    {
      lastKidPos = lastKidA;
      minKid = minKidsA;
      maxKid = maxKidsA;

      return kidsA;
    }
  }
}
*/
