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
  char c; cin.get(c);

  while(cin)
  {
    int digits[10]; for(int i=0; i<10; i++) digits[i]=0;

    while(c != '\n')
    {
      digits[c-'0']++;
      cin.get(c);
    }

    bool iguales = true; for(int i=1; i<10; i++) iguales &= (digits[i]==digits[i-1]);

    if(iguales) cout << "subnormal\n";
    else        cout << "no subnormal\n";

    cin.get(c);
  }

  return 0;
}
