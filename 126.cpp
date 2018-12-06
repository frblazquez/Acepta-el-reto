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

int main()
{
  int p,n; cin >> p >> n;

  while(p >= 0)
  {
    if(n>= p || p==1) cout << "YES\n";
    else              cout << "NO\n";

    cin >> p >> n;
  }

  return 0;
}
