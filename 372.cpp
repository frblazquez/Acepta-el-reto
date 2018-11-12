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
#include <string>
using namespace std;

int main()
{
  int numCases;       cin >> numCases;
  string palabraInit; getline(cin,palabraInit);

  while(numCases--)
  {
    string palabraFin;

    getline(cin, palabraInit);

    for(int i = palabraInit.size()-1; i >= 0; i--)
      palabraFin.push_back(palabraInit[i]);

    if('A' <= palabraInit[0] && 'Z' >= palabraInit[0])
    {
      palabraFin.back()  = 'a' + (palabraFin.back() - 'A');
      palabraFin.front() = 'A' + (palabraFin.front() - 'a');
    }

    cout << palabraFin << '\n';
  }

  return 0;
}
