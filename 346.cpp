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
#include <queue>
using namespace std;

int main()
{
  int numReg, maxInterval; cin >> numReg >> maxInterval;
  int maxNum, year;

  while(numReg || maxInterval)
  {
    maxNum = 0; queue<int> intervalPeople;

    for(int i = 0; i < numReg; i++)
    {
      cin >> year;

      while(!intervalPeople.empty() && year - intervalPeople.front() >= maxInterval)
        intervalPeople.pop();

      intervalPeople.push(year);

      if(intervalPeople.size() > maxNum)  maxNum = intervalPeople.size();
    }

    cout << maxNum << '\n';
    cin >> numReg >> maxInterval;
  }

  return 0;
}
