/*
*   Copyright © 2019
*
*   Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
*
*   Double degree in Mathematics - Computer engineering
*   Complutense University, Madrid
*
*/

#include <iostream>
using namespace std;

int main()
{
  int numValues, value; cin >> numValues;
  long long int maxPos, maxPos2, maxNeg, maxNeg2;

  while(numValues)
  {
    maxPos = -1; maxPos2 = -1;
    maxNeg =  1; maxNeg2 =  1;

    for(int i = 0; i < numValues; i++)
    {
      cin >> value;

      if(value >= 0)
      {
        if(value > maxPos)
          {maxPos2 = maxPos; maxPos = value;}
        else if(value > maxPos2)
           maxPos2 = value;
      }
      else
      {
        if(value < maxNeg)
          {maxNeg2 = maxNeg; maxNeg = value;}
        else if(value < maxNeg2)
           maxNeg2 = value;
      }
    }

    if(maxPos2 == -1 && maxNeg2 == 1)
      cout << maxPos*maxNeg << '\n';
    else if(maxNeg2 == 1)
      cout << maxPos*maxPos2 << '\n';
    else if(maxPos2 == -1)
      cout << maxNeg*maxNeg2 << '\n';
    else
      cout << max(maxPos*maxPos2, maxNeg*maxNeg2) << '\n';

    cin >> numValues;
  }

  return 0;
}
