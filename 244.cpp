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
#include <unordered_set>
using namespace std;

int main()
{
  int numRows, numQueens; cin >> numRows >> numQueens;

  while(numRows || numQueens)
  {
    unordered_set<int> rowsOccupied, colsOccupied;
    unordered_set<int> mainDiagonals, secondDiagonals;

    bool attacked = false;
    int row, col;

    for(int i = 0; i < numQueens; i++)
    {
      cin >> row >> col;

      if(!attacked)
      {
        if(rowsOccupied.count(row) == 0) rowsOccupied.insert(row);
        else                             attacked = true;
        if(colsOccupied.count(col) == 0) colsOccupied.insert(col);
        else                             attacked = true;
        if(mainDiagonals.count(col-row) == 0) mainDiagonals.insert(col-row);
        else                             attacked = true;
        if(secondDiagonals.count(row+col) == 0) secondDiagonals.insert(row+col);
        else                             attacked = true;
      }
    }

    if(attacked) cout << "SI\n";
    else         cout << "NO\n";

    cin >> numRows >> numQueens;
  }

  return 0;
}
