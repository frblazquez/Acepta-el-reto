/*
*   Copyright © 2018
*
*   Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
*
*   Double degree in Mathematics-Computer engineering.
*   Complutense university, Madrid.
*   
*/

/*
    This problem could easily be solved with a stack, however, and following
    the teacher advise, I prefer to solve it recursively just for practise.
*/

#include <iostream>
using namespace std;

int polishExpresion();

int main()
{
  int numCases; cin >> numCases;

  while(numCases--)
  {
    cout << polishExpresion() << '\n';
  }

  return 0;
}

int polishExpresion()
{
  char c; cin >> c;

  switch (c)
  {
    case '+':  return polishExpresion() + polishExpresion();
    case '-':  return polishExpresion() - polishExpresion();
    case '*':  return polishExpresion() * polishExpresion();
    case '/':  return polishExpresion() / polishExpresion();
    default:   return c - '0';
  }
}
