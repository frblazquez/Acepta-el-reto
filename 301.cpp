/*
*   Copyright © 2018
*
*   Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
*
*   Double degree in Mathematics-Computer engineering.
*   Complutense university, Madrid.
*   
*/

/*  SOLUCIÓN CON VUELTA ATRÁS, ALTO COSTE EN TIEMPO

#include <iostream>
#include <vector>
using namespace std;

bool minCoins(vector<int> const& coinsValue, vector<int> const& coinsNumber,
              int searchValue, int &actualValue, vector<int> &partialSolution,
              int &coinsUsed, int &minCoinsUsed, vector<int> &bestSolution, int level);

int main()
{
  int numCoins, aux, value; cin >> numCoins;

  while(cin)
  {
    vector<int> coinsValue;
    vector<int> coinsNumber;
    int sum = 0;

    for(int i = 0; i < numCoins; i++)
    {cin >> aux; coinsValue.push_back(aux);}
    for(int j = 0; j < numCoins; j++)
    {cin >> aux; coinsNumber.push_back(aux); sum += aux;}

    cin >> value;

    //All data was read at this point
    bool canBePaid; int partialSum = 0, coinsUsed = 0, minCoinsUsed = sum+1;
    vector<int> partialSolution(coinsNumber.size(), 0);
    vector<int> bestSolution(coinsNumber.size(), 0);

    canBePaid = minCoins(coinsValue, coinsNumber, value, partialSum, partialSolution,
                         coinsUsed, minCoinsUsed, bestSolution, 0);

    if(canBePaid)
    {
      cout << "SI ";

      for(int i = 0; i < bestSolution.size()-1; i++)
          cout << bestSolution[i] << " ";

      cout << bestSolution[bestSolution.size()-1] << '\n';
    }
    else
      cout << "NO\n";

    cin >> numCoins;
  }

  return 0;
}

bool minCoins(vector<int> const& coinsValue, vector<int> const& coinsNumber,
              int searchValue, int &actualValue, vector<int> &partialSolution,
              int &coinsUsed, int &minCoinsUsed, vector<int> &bestSolution, int level)
{
  //Base cases
  if(level == coinsValue.size())
  {
  if(actualValue == searchValue && coinsUsed < minCoinsUsed)
  {
    for(int i = 0; i < coinsValue.size(); i++)
      bestSolution[i] = partialSolution[i];

    minCoinsUsed = coinsUsed;

    return true;
  }
  else
    return false;
  }
    General case
  int n = 0; bool possible = false;

  while(n < coinsNumber[level] && actualValue + coinsValue[level] <= searchValue && coinsUsed < minCoinsUsed)
  {
    actualValue += coinsValue[level];
    partialSolution[level]++;
    coinsUsed++;
    n++;
  }

  //n is the maximum number of coins of this level that we can add
  while(n)
  {
    possible |= minCoins(coinsValue, coinsNumber, searchValue, actualValue, partialSolution,
                        coinsUsed, minCoinsUsed, bestSolution, level + 1);

    actualValue -= coinsValue[level];
    partialSolution[level]--;
    coinsUsed--;
    n--;
  }

  //We try to solve with no coins of this level
  possible |=   minCoins(coinsValue, coinsNumber, searchValue, actualValue, partialSolution,
                         coinsUsed, minCoinsUsed, bestSolution, level + 1);

  return possible;
}
*/
