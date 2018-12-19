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

struct fecha
{
	int dia; 
	int mes;
	int anyo;
};
istream& operator>>(istream& in, fecha& f);
bool operator!=(fecha const& f1, fecha const& f2);
int diasEsteAnyo(fecha const& f);
int cumplePasado(fecha const& actual, fecha const& nacimiento);
int diasMes(int numMes);

int main()
{
	fecha nacimiento, actual, centinela = { 0, 0, 0 };
	int noCumpleanyos;

	cin >> nacimiento >> actual;

	while (nacimiento != actual || actual != centinela)
	{
		if (nacimiento.dia == actual.dia && nacimiento.mes == actual.mes)
			cout << "0\n";
		else
			cout << 364 * (actual.anyo - nacimiento.anyo) + diasEsteAnyo(actual) - diasEsteAnyo(nacimiento) + 1 - cumplePasado(actual, nacimiento) << '\n';

		cin >> nacimiento >> actual;
	}

	return 0;
}

istream& operator>>(istream& in, fecha& f)
{
	cin >> f.dia >> f.mes >> f.anyo;

	return in;
}
bool operator!=(fecha const& f1, fecha const& f2)
{
	return f1.dia != f2.dia || f1.mes != f2.mes || f1.anyo != f2.anyo;
}
int diasEsteAnyo(fecha const& f)
{
	int diasAnyo = f.dia;

	for (int i = 1; i < f.mes; i++)
		diasAnyo += diasMes(i);
	
	return diasAnyo;
}
int diasMes(int numMes)
{
	switch (numMes)
	{
	case 2:		return 28;
	case 4:
	case 6:
	case 9:
	case 11:	return 30;
	default:	return 31;
	}
}
int cumplePasado(fecha const& actual, fecha const& nacimiento)
{
	if		(nacimiento.mes >  actual.mes)									return 0;
	else if (nacimiento.mes == actual.mes && nacimiento.dia > actual.dia)	return 0;
	else																	return 1;
}
