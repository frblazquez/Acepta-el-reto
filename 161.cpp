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
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int numElems, aux; cin >> numElems;

  while(numElems)
  {
    vector<int> elems;

    for(int i = 0; i < numElems; i++)
    {cin >> aux; elems.push_back(aux);}

    sort(elems.begin(),elems.end());

    int medianPos = elems.size()/2;

    if(elems.size()%2 == 1)
      cout << 2*elems[medianPos] << '\n';
    else
      cout << elems[medianPos -1] + elems[medianPos] << '\n';

    cin >> numElems;
  }

  return 0;
}
