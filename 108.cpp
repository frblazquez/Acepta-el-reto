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

string toCategoria(int index)
{
  switch (index)
  {
    case 0:  return "DESAYUNOS";
    case 1:  return "COMIDAS";
    case 2:  return "MERIENDAS";
    case 3:  return "CENAS";
    case 4:  return "COPAS";
    default: return "";
  }
}

int main()
{
  char categoria; cin >> categoria;

  while(cin)
  {
    double ventasCategoria[5]; for(int i = 0; i < 5; i++) ventasCategoria[i]=0;
    int numVentas = 0, numComidas = 0; double sumaVentas = 0, venta;

    while(categoria != 'N')
    {
      cin >> venta;

      sumaVentas+= venta; numVentas++;

      if(categoria == 'D')  ventasCategoria[0]+=venta;                else
      if(categoria == 'A') {ventasCategoria[1]+=venta; numComidas++;} else
      if(categoria == 'M')  ventasCategoria[2]+=venta;                else
      if(categoria == 'I')  ventasCategoria[3]+=venta;                else
      if(categoria == 'C')  ventasCategoria[4]+=venta;                else /*Intentionally*/;

      cin >> categoria;
    } cin >> venta; //Last number coming with 'N'

    bool   empateMax = false,              empateMin = false;
    int     indexMax = 0,                   indexMin = 0;
    double actualMax = ventasCategoria[0], actualMin = ventasCategoria[0];

    for(int i = 1; i < 5; i++)
    {
      if     (ventasCategoria[i]>actualMax) {actualMax = ventasCategoria[i]; indexMax = i; empateMax = false;}
      else if(ventasCategoria[i]==actualMax){empateMax = true;}

      if     (ventasCategoria[i]<actualMin) {actualMin = ventasCategoria[i]; indexMin = i; empateMin = false;}
      else if(ventasCategoria[i]==actualMax){empateMin = true;}
    }

    double avgTotal   = (numVentas ? sumaVentas/numVentas         : 0);
    double avgComidas = (numComidas? ventasCategoria[1]/numComidas: 0);

    cout << (empateMax? "EMPATE" : toCategoria(indexMax)) << '#';
    cout << (empateMin? "EMPATE" : toCategoria(indexMin)) << '#';
    cout << (avgComidas>avgTotal? "SI" : "NO") << '\n';

    cin >> categoria;
  }

  return 0;
}
