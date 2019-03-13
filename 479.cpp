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

const int MAX_DIM = 100;

bool room[MAX_DIM][MAX_DIM];

int main()
{
  int rows, cols, cont; char c; string dir;
  int requests, row, col, dir_i, dir_j;
  cin >> rows >> cols;

  while(rows || cols)
  {
    for(int i = 0; i < rows; i++)
    for(int j = 0; j < cols; j++)
    {
      cin >> c;

      if(c == '.')  room[i][j] = true;
      else          room[i][j] = false;
    }

    cin >> requests;

    for(int i = 0; i < requests; i++)
    {
      cin >> row >> col >> dir;
      row--; col--;

      if     (dir == "ARRIBA")    {dir_i = -1; dir_j = 0; }
      else if(dir == "ABAJO")     {dir_i =  1; dir_j = 0; }
      else if(dir == "DERECHA")   {dir_i =  0; dir_j = 1; }
      else if(dir == "IZQUIERDA") {dir_i =  0; dir_j = -1;}

      cont = 0;

      while(row < rows && col < cols && 0 <= row && 0 <= col && room[row][col])
      {
        cont++;

        row += dir_i;
        col += dir_j;
      }

      if(row == rows || col == cols || row == -1   || col == -1)
        cout << "NINGUNO\n";
      else
        cout << cont << '\n';
    }

    cout << "---\n";

    cin >> rows >> cols;
  }


  return 0;
}
