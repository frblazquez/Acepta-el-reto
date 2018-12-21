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
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
  int numCases; cin >> numCases;
  int numBurros, numSacos, aux, posibles;
  
  while(numCases--)
  {
    cin >> numBurros >> numSacos;
    vector<int> sacos; posibles=0;
    
    for(int i = 0; i < numSacos; i++)
    {cin >> aux; sacos.push_back(aux);}
    
    sort(sacos.begin(), sacos.end());
    
    for(int i = 0; i+1 < numSacos && posibles<numBurros; i++)
    {
      if(sacos[i+1]== sacos[i])
      {
        posibles++;
        i++;
      }
      
    }
    
    cout << posibles << '\n';
  }
  
  
  
  return 0;
}
