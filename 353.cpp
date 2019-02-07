/*
*   Copyright © 2019
*
*   Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
*
*   Doble grado Ingeniería informática - Matemáticas
*   Universidad Complutense de Madrid
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int availableTime, numChests, depth, coins;

  cin >> availableTime;

  while(cin)
  {
    cin >> numChests;

    vector<pair<int,int>> chests; chests.push_back({0,0});

    for(int i = 0; i < numChests; i++)
    {
      cin >> depth >> coins;
      chests.push_back({depth,coins});
    }

    int profit[numChests+1][availableTime+1];

    for(int i = 0; i <= numChests; i++)     profit[i][0] = 0;
    for(int i = 0; i <= availableTime; i++) profit[0][i] = 0;

    for(int i = 1; i <= numChests; i++)
    for(int j = 1; j <= availableTime; j++)
    {
      if(j < 3*chests[i].first) profit[i][j] = profit[i-1][j];
      else  profit[i][j] = max(profit[i-1][j], profit[i-1][j-3*chests[i].first] + chests[i].second);
    }

    vector<pair<int,int>> solution;
    int i = numChests, j = availableTime;

    while(i > 0)
    {
      if(profit[i][j] != profit[i-1][j])
        {solution.push_back(chests[i]); j-= 3*chests[i].first;}

      i--;
    }

    cout << profit[numChests][availableTime] << '\n';
    cout << solution.size() << '\n';

    for(int i = solution.size()-1; i>= 0; i--)
      cout << solution[i].first << " " << solution[i].second << '\n';

    cout << "----\n";

    cin >> availableTime;
  }

  return 0;
}
