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

int main()
{
  int b, h; cin >> b >> h;
  
  while(b || h)
  {
    if(b%2==0 || h%2==0)	cout << b*h/2 << ".0\n";
    else                    cout << b*h/2 << ".5\n";
    
    cin >> b >> h;
  }

  return 0;
}
