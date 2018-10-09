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

int main()
{
  /*
  int n; cin >> n;

  while(n)
  {
      if(n%2 == 0)  cout << "DERECHA\n";
      else          cout << "IZQUIERDA\n";

      cin >> n;
  }
  */

  string n; cin >> n;

  while(n != "0")
  {
    if((n[n.size()-1] - '0')%2 == 1)  cout << "IZQUIERDA\n";
    else                              cout << "DERECHA\n";

    cin >> n;
  }

  return 0;
}
