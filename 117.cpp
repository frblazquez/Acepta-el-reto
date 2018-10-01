/*
*   Copyright © 2018
*
*   Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
*
*   Doble grado Ingeniería informática - Matemáticas
*   Universidad Complutense de Madrid
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
  int n; cin >> n;
  string name;

  for(int i = 0; i < n; i++)
  {
    cin >> name >> name;
    cout << "Hola, " << name << ".\n";
  }

  return 0;
}
