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
#include <vector>
using namespace std;

int main()
{
  int grade, aux; cin >> grade;

  while(grade != 20)
  {
    vector<int> function; double divisions;

    for(int i = 0; i <= grade; i++)
    {cin >> aux;function.push_back(aux);}

    cin >> divisions;

    //All data was read at this point
    double step = 1/divisions, xPoint = 0, sum = 0, power, value;

    for(int i = 0; i < divisions; i++)
    {
      power = 1; value = 0;

      for(int j = grade; j >= 0; j--)
      {
        value += function[j]*power;
        power *= xPoint;
      }

      if(value < 0)      value = 0;
      else if(value > 1) value = 1;
      sum += value;

      xPoint += step;
    }

    sum *= step;

    if((1 - sum - sum) > 0.001)
      cout << "ABEL\n";
    else if(1 - sum - sum < -0.001)
      cout << "CAIN\n";
    else
      cout << "JUSTO\n";

    cin >> grade;
  }

  return 0;
}
