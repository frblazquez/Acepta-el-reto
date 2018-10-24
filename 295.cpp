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

const int k = 31543;
int power(int x, int n);

int main()
{
  int x, n; cin >> x >> n;

  while(x || n)
  {
    cout << power(x, n) << '\n';
    cin >> x >> n;
  }

  return 0;
}

int power(int x, int n)
{
  if(n == 0)    return 1;

  int powerOfTheMiddle;

  if(n%2 == 0)
  {
    powerOfTheMiddle = power(x, n/2);
    return (powerOfTheMiddle*powerOfTheMiddle)%k;
  }
  else
  {
    powerOfTheMiddle = power(x, (n-1)/2);
    return (((powerOfTheMiddle*powerOfTheMiddle)%k) * (x%k))%k;
  }
}
