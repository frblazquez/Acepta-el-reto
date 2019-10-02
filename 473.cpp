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

int  main()
{
  int numBalls, shootsPerFail;
  cin >> numBalls >> shootsPerFail;

  while(numBalls || shootsPerFail)
  {
    bool ballAvailable[numBalls];
    int luckyShoots, currentBall=0;

    for(int i = 0; i < numBalls; i++)
      ballAvailable[i]=true;

    for(int i = numBalls; i > 0; i--)
    {
      luckyShoots = (shootsPerFail-1)%i;

      while(luckyShoots){
        if(ballAvailable[currentBall])
          luckyShoots--;

        currentBall = (currentBall+1)%numBalls;
      }

      while(!ballAvailable[currentBall])
        currentBall = (currentBall+1)%numBalls;

      if(i == 1)
        cout << currentBall+1 << endl;
      else
        ballAvailable[currentBall] = false;
    }

    cin >> numBalls >> shootsPerFail;
  }

  return 0;
}
