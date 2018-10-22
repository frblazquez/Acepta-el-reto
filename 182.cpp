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

int persistenciaMult(int num);

int main()
{
  int numCasos; cin >> numCasos;

  while(numCasos--)
  {
    int num; cin >> num;
    cout << persistenciaMult(num) << '\n';
  }

  return 0;
}

int persistenciaMult(int num)
{
  if(num <= 9)  return 0;

  int nextNum = 1;

  do{
    nextNum *= (num%10);
    num /= 10;
  } while(num != 0);

  return 1 + persistenciaMult(nextNum);
}
