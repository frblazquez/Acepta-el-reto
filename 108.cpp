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

string categoryToString(int i)
{
  switch(i)
  {
    case 0:   return "DESAYUNOS";
    case 1:   return "COMIDAS";
    case 2:   return "MERIENDAS";
    case 3:   return "CENAS";
    case 4:   return "COPAS";
    default:  return "";
  }
}

int main()
{
  char type; double sell, sum; int index;
  double categories[5];

  cin >> type >> sell;

  while(cin)
  {
    for(int i = 0; i < 5; i++)  categories[i] = 0; sum = 0;

    while(type != 'N')
    {
      switch(type)
      {
        case 'D': index = 0; break;
        case 'A': index = 1; break;
        case 'M': index = 2; break;
        case 'I': index = 3; break;
        case 'C': index = 4; break;
        default:  index = -1;
      }

      categories[index] = sell;
      sum += sell;

      cin >> type >> sell;
    }

    double max, min; int maxIndex, minIndex;
    bool maxTie = false, minTie = false;

    if(sum < 0) {max = sum -1; min = 0;}
    else        {max = -1;     min = sum +1;}

    for(int i = 0; i < 5; i++)
    {
      if     (categories[i] == max)  maxTie = true;
      else if(categories[i] >  max) {max = categories[i]; maxTie = false; maxIndex = i;}

      if(categories[i] == min)  minTie = true;
      else if(categories[i] <  min) {min = categories[i]; minTie = false; minIndex = i;}
    }

    cout << (maxTie? "EMPATE": categoryToString(maxIndex)) << '#';
    cout << (minTie? "EMPATE": categoryToString(minIndex)) << '#';
    cout << (categories[1] > sum/5? "SI": "NO")            << '\n';

    cin >> type >> sell;
  }

  return 0;
}
