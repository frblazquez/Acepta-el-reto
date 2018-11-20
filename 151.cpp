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
  int numRows; cin >> numRows;

  while(numRows)
  {
    bool Id = true; int aux;

    for(int i = 0; i < numRows; i++)
    for(int j = 0; j < numRows; j++)
    {
      cin >> aux;

      if(Id)
      {
        if(i==j) Id = (aux==1);
        else     Id = (aux==0);
      }
    }

    if(Id)  cout << "SI\n";
    else    cout << "NO\n";

    cin >> numRows;
  }

  return 0;
}
