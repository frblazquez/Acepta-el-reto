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
  //Conjugación -           Tiempo             - Persona
  // 1ª,2ª,3ª   - Presente, Futuro, Pretérito  - Yo, tu, el ella...
  string conjugaciones[3][3][6];

  //Primera conjugación - Presente
  conjugaciones[0][0][0]= "o";
  conjugaciones[0][0][1]= "as";
  conjugaciones[0][0][2]= "a";
  conjugaciones[0][0][3]= "amos";
  conjugaciones[0][0][4]= "ais";
  conjugaciones[0][0][5]= "an";
  //Primera conjugación - Pretérito perfecto simple
  conjugaciones[0][1][0]= "e";
  conjugaciones[0][1][1]= "aste";
  conjugaciones[0][1][2]= "o";
  conjugaciones[0][1][3]= "amos";
  conjugaciones[0][1][4]= "asteis";
  conjugaciones[0][1][5]= "aron";
  //Primera conjugación - Futuro
  conjugaciones[0][2][0]= "are";
  conjugaciones[0][2][1]= "aras";
  conjugaciones[0][2][2]= "ara";
  conjugaciones[0][2][3]= "aremos";
  conjugaciones[0][2][4]= "areis";
  conjugaciones[0][2][5]= "aran";

  //Segunda conjugación - Presente
  conjugaciones[1][0][0]= "o";
  conjugaciones[1][0][1]= "es";
  conjugaciones[1][0][2]= "e";
  conjugaciones[1][0][3]= "emos";
  conjugaciones[1][0][4]= "eis";
  conjugaciones[1][0][5]= "en";
  //Segunda conjugación - Pretérito perfecto simple
  conjugaciones[1][1][0]= "i";
  conjugaciones[1][1][1]= "iste";
  conjugaciones[1][1][2]= "io";
  conjugaciones[1][1][3]= "imos";
  conjugaciones[1][1][4]= "isteis";
  conjugaciones[1][1][5]= "ieron";
  //Segunda conjugación - Futuro
  conjugaciones[1][2][0]= "ere";
  conjugaciones[1][2][1]= "eras";
  conjugaciones[1][2][2]= "era";
  conjugaciones[1][2][3]= "eremos";
  conjugaciones[1][2][4]= "ereis";
  conjugaciones[1][2][5]= "eran";

  //Tercera conjugación - Presente
  conjugaciones[2][0][0]= "o";
  conjugaciones[2][0][1]= "es";
  conjugaciones[2][0][2]= "e";
  conjugaciones[2][0][3]= "imos";
  conjugaciones[2][0][4]= "is";
  conjugaciones[2][0][5]= "en";
  //Tercera conjugación - Pretérito perfecto simple
  conjugaciones[2][1][0]= "i";
  conjugaciones[2][1][1]= "iste";
  conjugaciones[2][1][2]= "io";
  conjugaciones[2][1][3]= "imos";
  conjugaciones[2][1][4]= "isteis";
  conjugaciones[2][1][5]= "ieron";
  //Tercera conjugación - Futuro
  conjugaciones[2][2][0]= "ire";
  conjugaciones[2][2][1]= "iras";
  conjugaciones[2][2][2]= "ira";
  conjugaciones[2][2][3]= "iremos";
  conjugaciones[2][2][4]= "ireis";
  conjugaciones[2][2][5]= "iran";

  string verbo; int conj, tiempo; char code, vocal;
  cin >> verbo >> code;

  while(code != 'T')
  {
    verbo.pop_back(); vocal=verbo.back();
    verbo.pop_back();

    switch(vocal)
    {
      case 'a': conj = 0; break;
      case 'e': conj = 1; break;
      default:  conj = 2;
    }

    switch(code)
    {
      case 'A': tiempo = 0; break;
      case 'P': tiempo = 1; break;
      default:  tiempo = 2;
    }

    cout << "yo "       + verbo + conjugaciones[conj][tiempo][0] << '\n';
    cout << "tu "       + verbo + conjugaciones[conj][tiempo][1] << '\n';
    cout << "el "       + verbo + conjugaciones[conj][tiempo][2] << '\n';
    cout << "nosotros " + verbo + conjugaciones[conj][tiempo][3] << '\n';
    cout << "vosotros " + verbo + conjugaciones[conj][tiempo][4] << '\n';
    cout << "ellos "    + verbo + conjugaciones[conj][tiempo][5] << '\n';

    cin >> verbo >> code;
  }

  return 0;
}
