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
  string palabrasEncadenadas; getline(cin, palabrasEncadenadas);

  while(cin)
  {
    bool encadenadas = true;

    for(int i = 0; encadenadas && i < palabrasEncadenadas.size(); i++)
    {
      if(palabrasEncadenadas[i] == ' ')
        encadenadas = (palabrasEncadenadas[i-2] == palabrasEncadenadas[i+1]) &&
                      (palabrasEncadenadas[i-1] == palabrasEncadenadas[i+2]);
    }

    if(encadenadas) cout << "SI\n";
    else            cout << "NO\n";

    getline(cin, palabrasEncadenadas);
  }

  return 0;
}
