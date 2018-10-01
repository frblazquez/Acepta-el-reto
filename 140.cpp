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
  string num; cin >> num;
  int suma;

  while(num[0] != '-')
  {
    suma = 0;

    for(int i = 0; i < num.size() - 1; i++)
    {
      cout << num[i] << " + ";

      suma += (num[i] - '0');
    }

    cout << num[num.size()-1] << " = " << suma + (num[num.size()-1] - '0') << '\n';

    cin >> num;
  }

  return 0;
}
