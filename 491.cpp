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

const int MAX_GRAPES = 24;

int grapes[MAX_GRAPES];     // Grape weight
int solution[MAX_GRAPES];   // Partial solution vector (1 => grape is taken)
// int minGrapes[MAX_GRAPES];  // Minimum grape weight from that grape

int backTracking(int level, int weight, int numGrapesTaken, int numGrapes, int maxWeight)
{
  if(numGrapesTaken == 12)    return 1;   // This is already a solution
  if(level == numGrapes)      return 0;   // Not solution and no more grapes

  int numPossibilities = 0;

  if(grapes[level] + weight <= maxWeight)
  {
    numPossibilities += backTracking(level+1, weight+grapes[level], numGrapesTaken+1, numGrapes, maxWeight);
  }
    numPossibilities += backTracking(level+1, weight, numGrapesTaken, numGrapes, maxWeight);

  return numPossibilities;
}

int numCombinations(int maxWeight, int numGrapes)
{
  return backTracking(0,0,0,numGrapes, maxWeight);
}

int main()
{
  int maxWeight, numGrapes;
  cin >> maxWeight >> numGrapes;

  while(maxWeight || numGrapes)
  {
    for(int i = 0; i < numGrapes; i++)
      cin >> grapes[i];

    // minGrapes[numGrapes-1] = grapes[numGrapes-1];
    //for(int i = numGrapes-2; i >= 0; i--)
      //minGrapes[i] = min(minGrapes[i+1], grapes[i]);

    cout << numCombinations(maxWeight,numGrapes) << '\n';
    cin >> maxWeight >> numGrapes;
  }

  return 0;
}
