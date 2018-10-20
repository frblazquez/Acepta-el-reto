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
#include <string>
using namespace std;

int main()
{
  int numCases; cin >> numCases;
  int keyNumber; string digitSequence; char aux;
  int partialCount, init, end, numApp;

  while(numCases--)
  {
    cin >> keyNumber; cin.get(aux); //Reads the number and the space character
    getline(cin, digitSequence);    //Reads the stock market sequence

    partialCount = 0; init = 0; end = 0; numApp = 0;

    while(end != digitSequence.size())
    {
      partialCount += digitSequence[end] - '0';
      end++;

      if(partialCount == keyNumber) numApp++;
      else if(partialCount > keyNumber)
      {
        while(partialCount >= keyNumber && init < end)
        {
          partialCount -= digitSequence[init] - '0';
          init++;

          if(partialCount == keyNumber) numApp++;
        }
      }
    }

    cout << numApp << endl;
  }

  return 0;
}
