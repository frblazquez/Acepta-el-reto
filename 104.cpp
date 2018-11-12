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

bool isBalanced(int &pt);

int main()
{
  int aux;

  while(cin)
  {
    if(isBalanced(aux))
      cout << "SI\n";
    else if(cin)
      cout << "NO\n";
  }

  return 0;
}

bool isBalanced(int &pt, bool okInput)
{
  int pi,di,pd,dd;
  cin >> pi >> di >> pd >> dd;

  bool balancedIzq = true, balancedDcha = true;

  if(pi==0)
    balancedIzq = isBalanced(pi);

  if(pd==0)
    balancedDcha = isBalanced(pd);

  pt = pi + pd;
  return balancedIzq && balancedDcha && pi*di == pd*dd;
}
