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
  int chanel, nextChanel;
  cin >> chanel >> nextChanel;
  
  while(chanel || nextChanel)
  {
    cout << min(99-abs(nextChanel - chanel), abs(nextChanel-chanel)) << '\n';
    cin >> chanel >> nextChanel;
  }
  
  
  return 0;
}
