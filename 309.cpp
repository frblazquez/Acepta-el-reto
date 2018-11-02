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
  int numCases; cin >> numCases;
  char op, nextOp; int op1, op2, result;

  while(numCases--)
  {
    cin >> op1 >> op;

    while(op != '.')
    {
      cin >> op2 >> nextOp;

      switch(op)
      {
        case '+': result = op1+op2;   break;
        case '-': result = op1-op2;   break;
        default:  cerr << "Something was wrong!\n";
      }

      cout << result;  if(nextOp != '.') cout << ", "; else cout << '\n';

      op1 = result; op = nextOp;
    }
  }

  return 0;
}
