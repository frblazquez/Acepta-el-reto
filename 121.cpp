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
  string num1,num2; cin >> num1 >> num2;

  while(num1 != "0" && num2 != "0")
  {
    int end1 = num1.size()-1, end2 = num2.size()-1;
    int carry = 0, last1, last2, numCarries = 0;

    while(end1 >= 0 || end2 >= 0)
    {
      if(end1 >= 0)   last1 = num1[end1]-'0';
      else            last1 = 0;

      if(end2 >= 0)   last2 = num2[end2]-'0';
      else            last2 = 0;

      if(last1+last2+carry > 9) {carry = 1; numCarries++;}
      else                       carry = 0;

      end1--; end2--;
    }

    cout << numCarries << '\n';
    cin >> num1 >> num2;
  }

  return 0;
}
