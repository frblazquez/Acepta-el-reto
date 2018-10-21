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
#include <vector>
using namespace std;

int varillasDesperdicio(int lv, int nn, int ns, int ls, int habia, int &sobra, int &desperdiciado);

int main()
{
  int longVar;  //Longitud de las varillas primarias
  int numNer;   //Número de nervios del paraguas
  int numSeg;   //Segmentos de cada nervio
  int longSeg;  //Longitud de los Segmentos

  cin >> longVar;

  while(longVar != -1)
  {
    cin >> numNer;

    int resto = 0, desperdicio = 0, habia = 0, numVarillas = 0;
    bool imposible = false;

    while(numNer != -1)
    {
      cin >> numSeg >> longSeg;

      //Hasta aquí es simplemente esquema de leido de entrada
      if(!imposible)
      {
        numVarillas += varillasDesperdicio(longVar, numNer, numSeg, longSeg, habia, resto, desperdicio);

        habia = resto;  //Lo que sobra de la última varilla es lo que hay para la siguiente
        imposible = (resto == longVar);
      }
      //Aquí termina la parte interesante

      cin >> numNer;
    }

    if(imposible)   cout << "IMPOSIBLE\n";
    else            cout << numVarillas << " " << desperdicio + resto << '\n';

    cin >> longVar;
  }


  return 0;
}

int varillasDesperdicio(int lv, int nn, int ns, int ls, int habia, int &sobra, int &desperdiciado)
{
  int nsNecesarios = nn*ns, varillasUsadas = 0;

  //Primero aprovechamos lo que queda de la varilla anterior
  if(habia < nsNecesarios*ls)
  {
    nsNecesarios -= habia/ls;
    desperdiciado+= habia%ls;
  }
  else
  {
    sobra = habia - nsNecesarios*ls;
    nsNecesarios = 0;
  }
  //Si nos hacen falta más, seguimos gastando varillas
  if(nsNecesarios != 0)
  {
      if(lv < ls)
        sobra = lv;
      else
      {
        int segmentosPorVarilla = lv/ls;
        int sobraDeLaVarilla = lv -ls*segmentosPorVarilla;

        varillasUsadas = nsNecesarios/segmentosPorVarilla;
        desperdiciado += sobraDeLaVarilla*varillasUsadas;

        if(nsNecesarios%segmentosPorVarilla == 0)
        {
          sobra = sobraDeLaVarilla;
          desperdiciado -= sobraDeLaVarilla;
        }
        else
        {
          varillasUsadas++;
          sobra = lv - (nsNecesarios%segmentosPorVarilla)*ls;
        }
      }
  }

  return varillasUsadas;
}
