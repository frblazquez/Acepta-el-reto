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
  int numRows,numCols; cin >> numRows >> numCols;

  while(cin)
  {
    char board[numRows][numCols]; char aux;

    //Reads the entry data
    for(int i = 0; i < numRows; i++)
    for(int j = 0; j < numCols; j++)
    {
      cin >> board[i][j];

      if(board[i][j] == '-') board[i][j] = '0';
    }

    for(int i = 0; i < numRows; i++)
    {
      for(int j = 0; j < numCols; j++)
        cout << board[i][j] << " ";
        cout << '\n';
    }
    cout << '\n';

    //Prepares the board game
    for(int i = 0; i < numRows; i++)
    for(int j = 0; j < numCols; j++)
    {
      if(board[i][j] == '*')
      {
        for(int k = -1; k<=1; k++)
        for(int l = -1; l<=1; l++)
          if(0 <= i+k && i+k < numRows && 0 <= j+l && j+l < numCols && board[i+k][j+l]!='*')
          {
            aux = board[i+k][j+l];
            board[i+k][j+l] = aux+1;
          }
      }
    }

    //At this point our board is made of '*','0','1', ... ,'8'
    for(int i = 0; i < numRows; i++)
    {
      for(int j = 0; j < numCols; j++)
        cout << board[i][j] << " ";
        cout << '\n';
    }
    cout << '\n';

    cin >> numRows >> numCols;
  }

  return 0;
}
