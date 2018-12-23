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

string dayConverter(int pos)
{
  switch (pos)
  {
    case 0: return "MARTES";
    case 1: return "MIERCOLES";
    case 2: return "JUEVES";
    case 3: return "VIERNES";
    case 4: return "SABADO";
    default:  return "DOMINGO";
  }
}

int main()
{
  int maxPos, minPos;
  float max, min, next, sum;
  bool maxTie,minTie;

  cin >> next;

  while(next != -1)
  {
    max=next; min=next; sum = next;
    maxPos=0; minPos=0;
    maxTie = false; minTie = false;

    for(int i = 1; i<6; i++)
    {
      cin >> next; sum += next;

      if(next>max)      {max=next; maxPos=i; maxTie=false;}
      else if(next==max) maxTie = true;

      if(next<min)      {min=next; minPos=i; minTie=false;}
      else if(next==min) minTie = true;
    }

    cout << (maxTie ? "EMPATE" : dayConverter(maxPos)) << " ";
    cout << (minTie ? "EMPATE" : dayConverter(minPos)) << " ";
    cout << (sum/6 < next ? "SI\n" : "NO\n");
    cin >> next;
  }

  return 0;
}
