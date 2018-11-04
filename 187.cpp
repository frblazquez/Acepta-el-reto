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
#include <stack>
#include <vector>
using namespace std;


enum Palo{OROS, COPAS, BASTOS, ESPADAS};
struct Carta
{
	Palo palo;
	int valor;
};

istream& operator>>(istream& in, Carta &carta);
bool resoluble(vector<Carta> &mazo);
bool sePuedenPasarCartas(vector<Carta> const& mazo, int numYaDesplazadas);
void pasarCartas(vector<Carta> &mazo, vector<Carta> &mesa, int &numYaDesplazadas);

int main()
{
	vector<Carta> mazo; Carta cartaAux;
	int numPalos; int yaDesplazadas = 0;

	cin >> numPalos;

	while (numPalos != 0)
	{
		for (int i = 0; i < numPalos * 10; i++)
		{
			cin >> cartaAux; mazo.push_back(cartaAux);
		}

		if (resoluble(mazo))		cout << "GANA\n";
		else						cout << "PIERDE\n";

		mazo.clear();
		cin >> numPalos;
	}

	return 0;
}

istream& operator>>(istream& in, Carta &carta)
{
	char aux; int auxInt;

	in >> auxInt >> aux;

	if (auxInt > 7)
		auxInt -= 2;		//hacemos que las cartas sean consecutivas

	carta.valor = auxInt;

	switch (aux)
	{
	case 'E':	carta.palo = ESPADAS;	break;
	case 'O':	carta.palo = OROS;		break;
	case 'C':	carta.palo = COPAS;		break;
	case 'B':	carta.palo = BASTOS;	
	}

	return in;
}
bool resoluble(vector<Carta> &mazo)
{
	//UNA PILA PARA CADA PALO DE LAS CARTAS
	stack<int> oros, copas, bastos, espadas;
	oros.push(0); copas.push(0); bastos.push(0); espadas.push(0);
	
	//VECTOR (USAREMOS COMO PILA) PARA LAS CARTAS QUE HAY EN LA MESA
	vector<Carta> mesa;	


	bool hayMovimiento = true;			//SI SE PASA EL BUCLE UNA VEZ Y NO SE PONE HAYMOVIMIENTO A TRUE ES QUE SE HA PERDIDO
	bool sePuedeQuitarPrimera;			//DICE SI SE PUEDE QUITAR LA CARTA DE ARRIBA DE LAS QUE HAY EN LA MESA
	int yaDesplazadas;					//DE LAS CARTAS DEL MAZO LAS YADESPLAZADAS PRIMERAS ESTAN EN LA MESA



	while (hayMovimiento && mazo.size() > 0)
	{
		hayMovimiento = false;
		yaDesplazadas = 0;

		while (sePuedenPasarCartas(mazo, yaDesplazadas))
		{
			pasarCartas(mazo, mesa, yaDesplazadas);

			sePuedeQuitarPrimera = true;

			while (sePuedeQuitarPrimera && mesa.size() > 0)
			{
				sePuedeQuitarPrimera = false;

				/////////////////////////////////////////////////////////////////
				switch (mesa[mesa.size() - 1].palo)
				{
				case OROS:
				{
					if (mesa[mesa.size() - 1].valor - 1 == oros.top())
					{
						oros.push(mesa[mesa.size() - 1].valor); mesa.pop_back(); 
						hayMovimiento = true; sePuedeQuitarPrimera = true;
					}
				}break;
				case BASTOS:
				{
					if (mesa[mesa.size() - 1].valor - 1 == bastos.top())
					{
						bastos.push(mesa[mesa.size() - 1].valor); mesa.pop_back();
						hayMovimiento = true; sePuedeQuitarPrimera = true;
					}
				}break;
				case ESPADAS:
				{
					if (mesa[mesa.size() - 1].valor - 1 == espadas.top())
					{
						espadas.push(mesa[mesa.size() - 1].valor); mesa.pop_back();
						hayMovimiento = true; sePuedeQuitarPrimera = true;
					}
				}break;
				case COPAS:
				{
					if (mesa[mesa.size() - 1].valor - 1 == copas.top())
					{
						copas.push(mesa[mesa.size() - 1].valor); mesa.pop_back();
						hayMovimiento = true; sePuedeQuitarPrimera = true;
					}
				}
				}
				/////////////////////////////////////////////////////////////////
			}
		}
		mazo = mesa;
		mesa.clear();

	}//Al llegar aquí debo tener mesa vacía, stacks posibliemente semillenas y en mazo las restantes!!

	return hayMovimiento;
}
bool sePuedenPasarCartas(vector<Carta> const& mazo, int numYaDesplazadas)
{
	return mazo.size() - numYaDesplazadas > 0;
}
void pasarCartas(vector<Carta> &mazo, vector<Carta> &mesa, int &numYaDesplazadas)
{
	if (mazo.size() - numYaDesplazadas > 1)
	{
		mesa.push_back(mazo[numYaDesplazadas]); numYaDesplazadas += 1;
		mesa.push_back(mazo[numYaDesplazadas]); numYaDesplazadas += 1;
	}
	else
	{
		mesa.push_back(mazo[numYaDesplazadas]); numYaDesplazadas += 1;
	}
}
