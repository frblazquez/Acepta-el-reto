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
#include <cmath>
//#include <vector>
using namespace std;

// Returns the minimum number of levels the bunch has to have
// int minLevels(int numUvas, vector<int> &v);
int minLevelsFormula(int numUvas);

int main()
{
  int numUvas; cin >> numUvas;
  //vector<int> uvasMax = {1};

  while(numUvas)
  {
    // Hay una solución directa a partir de la eqn que genera
    // cout << minLevels(numUvas, uvasMax) << '\n';
    cout << minLevelsFormula(numUvas) << '\n';
    cin >> numUvas;
  }

  return 0;
}

int minLevelsFormula(int numUvas)
{
  int num = (sqrt(4*numUvas + 1) - 1)/2; //Aproximamos
  int aux = num*(num+1)/2;

  while(aux < numUvas)                   //Alcanzamos la solución
  {
    num++;
    aux += num;
  }

  return num;
}

/*
int minLevels(int numUvas, vector<int> &v)
{
  if(v.back() <= numUvas)
  {
    while(v.back() < numUvas)
      v.push_back(v.back() + v.size() + 1);

    return v.size();
  }

  //else - Búsqueda binaria
  int ini = 0, fin = v.size(), med = fin/2;

  while(fin > med)
  {
         if (v[med] > numUvas)  fin = med;
    else if (v[med] < numUvas)  ini = med+1;

    med = (ini+fin)/2;
  }

  return med+1;
}
*/
