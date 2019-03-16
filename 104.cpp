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

bool isBalanced(long long int &pt, bool &okInput);

int main()
{
  long long int aux; bool okInput = true, balanced;

  while(okInput)
  {
    balanced = isBalanced(aux, okInput);

    if(okInput && balanced)
      cout << "SI\n";
    else if(okInput)
      cout << "NO\n";
  }

  return 0;
}

bool isBalanced(long long int &pt, bool &okInput)
{
  long long int pi,di,pd,dd;
  cin >> pi >> di >> pd >> dd;

  okInput = (pi!=0 || di!=0 || pd!=0 || dd!=0);

  bool balancedIzq = true, balancedDcha = true;
  bool aux1, aux2;

  if(pi==0)
    balancedIzq = isBalanced(pi, aux1);

  if(pd==0)
    balancedDcha = isBalanced(pd, aux2);

  pt = pi + pd;
  return balancedIzq && balancedDcha && pi*di == pd*dd;
}
