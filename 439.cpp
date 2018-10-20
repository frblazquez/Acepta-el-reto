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
  int numCases; cin >> numCases;
  bool vel, dis, tim; char c, aux;
  int velValue, disValue, timValue;

  while(numCases--)
  {
    vel = false; dis = false; tim = false;

    for(int i = 0; i < 2; i++)
    {
      cin >> c >> aux;

      switch(c)
      {
        case 'V': cin >> velValue; vel = true; break;
        case 'D': cin >> disValue; dis = true; break;
        default:  cin >> timValue; tim = true;
      }
    }

    if(!vel)       cout << "V=" << disValue/timValue << '\n';
    else if(!dis)  cout << "D=" << velValue*timValue << '\n';
    else           cout << "T=" << disValue/velValue << '\n';
  }

  return 0;
}
