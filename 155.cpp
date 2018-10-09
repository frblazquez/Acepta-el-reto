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

int main()
{
  int base, high; cin >> base >> high;

  while(base >= 0 && high >= 0)
  {
    cout << base + base + high + high << '\n';
    cin >> base >> high;
  }

  return 0;
}
