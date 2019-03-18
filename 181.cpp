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

const int MAX_SIZE = 15;

int board[MAX_SIZE][MAX_SIZE];

int main()
{
  int boardSize,act;  char c;
  cin >> boardSize;

  while(boardSize)
  {
    for(int i = 0; i < boardSize; i++)
    for(int j = 0; j < boardSize; j++)
    {
      cin >> c;

      if(c == '.')  board[i][j] =  0;
      else          board[i][j] = -1;
    }

    board[boardSize-1][0] = 1;

    for(int i = 2; i < 2*boardSize; i++)
    for(int j = max(0, i - boardSize); j < boardSize && j-i < 0; j++)
    {
      // We consider board[boardSize-i+j][j]
      act = boardSize-i+j;

      if(board[act][j] != -1)
      {
        if(j > 0 && board[act][j-1] != -1)
          board[act][j] += board[act][j-1];
        if(act < boardSize-1 && board[act+1][j] != -1)
          board[act][j] += board[act+1][j];
      }
    }

    cout << board[0][boardSize-1] << '\n';
    cin >> boardSize;
  }

  return 0;
}
