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

char board[9][9];

int main()
{
  int numCases, cont; bool sim;
  cin >> numCases;

  while(numCases--)
  {
    cont = 0;

    for(int i = 0; i<9; i++)
    for(int j = 0; j<9; j++)
    {
      cin >> board[i][j];

      if(board[i][j] != '-') cont++;
    }

    if(cont <= 32)
    {
      sim = true;

      for(int i = 0; i <=4 && sim; i++)
      for(int j = 0; j < 9 && sim; j++)
      {
        if(board[i][j]=='-') sim &= (board[8-i][8-j] == '-');
        else                 sim &= (board[8-i][8-j] != '-');
      }

      if(sim) cout << "SI\n";
      else    cout << "NO\n";
    }
    else
      cout << "NO\n";
  }

  return 0;
}
