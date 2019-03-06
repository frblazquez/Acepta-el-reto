/*
*   Copyright © 2019
*
*   Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
*
*   Double degree in Mathematics-Computer engineering.
*   Complutense university, Madrid.
*
*/

#include <iostream>
using namespace std;

bool isBinTree();
bool binaryTree(int &maxim, int &minim);

int main()
{
  int numCases; cin >> numCases;

  while(numCases--)
  {
    if(isBinTree()) cout << "SI\n";
    else            cout << "NO\n";
  }

  return 0;
}

bool isBinTree()
{
  int max, min;

  return binaryTree(max, min);
}

bool binaryTree(int &maxim, int &minim)
{
  int aux; cin >> aux;

  if(aux == -1) {maxim = -1; minim = -1; return true;}

  int maxR, maxL, minR, minL;
  bool binaryR, binaryL, binary;

  binaryL = binaryTree(maxL, minL);
  binaryR = binaryTree(maxR, minR);
  binary  = (minR==-1 || minR > aux) && (maxL==-1 || maxL<aux);

  if(minL == -1)  minL = aux + 1;
  if(minR == -1)  minR = aux + 1;

  minim = min(aux,min(minL, minR));
  maxim = max(aux,max(maxL, maxR));

  return binaryL && binaryR && binary;
}
