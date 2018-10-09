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
  int hour, min;  char c;

  cin >> hour >> c >> min;

  while(hour || min)
  {
    cout << (23 - hour)*60 + 60-min << '\n';
    cin >> hour >> c >> min;
  }

  return 0;
}

/*
#include <stdio.h>

int main()
{
  int hour, min;

  scanf("%d:%d", &hour, &min);

  while(hour || min)
  {
    printf("%d\n", (23 - hour)*60 + 60-min);
    scanf("%d:%d", &hour, &min);
  }

  return 0;
}
*/
