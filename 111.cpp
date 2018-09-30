/*
*   Copyright © 2018
*
*   Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
*
*   Doble grado Ingeniería informática - Matemáticas
*   Universidad Complutense de Madrid
*/

#include <iostream>
using namespace std;

const string orbitals[] = {"1s", "2s", "2p", "3s", "3p", "4s",
                           "3d", "4p", "5s", "4d", "5p", "6s",
                           "4f", "5d", "6p", "7s", "5f", "6d", "7p"};
const int maxElectrons[]= {2, 2, 6, 2, 6, 2, 10, 6, 2, 10, 6,
                           2, 14, 10, 6, 2, 14, 10, 6};

int main()
{
  string component; int z; cin >> component >> z;

  while(component != "Exit")
  {
    int i = 0;

    while(z > maxElectrons[i])
    {
      cout << (i==0?"":" ") << orbitals[i] << maxElectrons[i];
      z -= maxElectrons[i]; i++;
    }

    if(z || !i) 
      cout << (i==0?"":" ") << orbitals[i] << z;
      cout << '\n';

    cin >> component >> z;
  }

  return 0;
}
