;/*
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
  int numClimbers; cin >> numClimbers;

  int currentSpeed, currentGroupSize, numberOfGroups, currentClimberSpeed;
  int maxGroupSize, minGroupSize;

  while(numClimbers)
  {
    numberOfGroups=1;
    currentGroupSize=1;
    maxGroupSize=1;
    minGroupSize=10001;

    cin >> currentSpeed;

    for(int i = 1; i < numClimbers; i++)
    {
      cin >> currentClimberSpeed;

      if(currentClimberSpeed < currentSpeed)
      {
        numberOfGroups++;

        if(currentGroupSize > maxGroupSize)
          maxGroupSize = currentGroupSize;

        if(currentGroupSize < minGroupSize)
          minGroupSize = currentGroupSize;

        currentGroupSize = 1;
        currentSpeed = currentClimberSpeed;
      } else {
        currentGroupSize++;
      }
    }

    if(currentGroupSize > maxGroupSize)
      maxGroupSize = currentGroupSize;

    if(currentGroupSize < minGroupSize)
      minGroupSize = currentGroupSize;

    cout << numberOfGroups << ' ' << minGroupSize << ' ' << maxGroupSize << '\n';
    cin >> numClimbers;
  }

  return 0;
}
