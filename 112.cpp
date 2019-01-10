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
  int distance, speedLimit, timeLapse;
  cin >> distance >> speedLimit >> timeLapse;

  while(distance || speedLimit || timeLapse)
  {
    if(distance < 0 || speedLimit < 0 || timeLapse < 0) cout << "ERROR\n";
    else if(distance == 0)                              cout << "OK\n";
    else if(timeLapse == 0)                             cout << "PUNTOS\n";
    else
    {
      double avgSpeedMperS   = double(distance)/timeLapse;
      double speedLimitMperS = double(speedLimit)/3.6;

      if(avgSpeedMperS >= 1.2*speedLimitMperS)   cout << "PUNTOS\n";
      else if(avgSpeedMperS > speedLimitMperS)   cout << "MULTA\n";
      else                                       cout << "OK\n";
    }

    cin >> distance >> speedLimit >> timeLapse;
  }

  return 0;
}
