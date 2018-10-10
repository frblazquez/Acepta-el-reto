/*
*   Copyright © 2018
*
*   Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
*
*   Doble grado Ingeniería informática - Matemáticas
*   Universidad Complutense de Madrid
*/

/*
    This problem could easily be solved iteratively, however, and following
    the teacher advise, I prefer to solve it recursively just for practise.
*/

#include <iostream>
using namespace std;

bool polidivisible(long long int num, int length);
int numberLenght(long long int num);

int main()
{
  long long int num; cin >> num;

  while(cin)
  {
    int length = numberLenght(num);

    if(polidivisible(num, length))  cout << "POLIDIVISIBLE\n";
    else                            cout << "NO POLIDIVISIBLE\n";

    cin >> num;
  }


  return 0;
}

bool polidivisible(long long int num, int length)
{
  if(length == 1) return true;
  else            return num%length == 0 && polidivisible(num/10, length-1);
}

int numberLenght(long long int num)
{
  int count = 0;

  while(num) {count++; num /= 10;}

  return count;
}
