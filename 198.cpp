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
#include <queue>
#include <stack>
using namespace std;

bool resultadoEvPost(string const& expresion, int &resultado);
bool resultadoEvQueue(string const& expresion, int &resultado);
void muestraResultado(bool fallaPost, int resPost, bool fallaQue, int resQue);
bool esOperador(char c);
int evalua(int op1, char c, int op2, bool &fallo);

int main()
{
	string aux;
	bool falloPostfija; int resultadoPostfija;
	bool falloQueue;	int resultadoQueue;

	getline(cin, aux);

	while (cin)
	{
		falloPostfija = resultadoEvPost(aux, resultadoPostfija);
		falloQueue = resultadoEvQueue(aux, resultadoQueue);

		muestraResultado(falloPostfija, resultadoPostfija, falloQueue, resultadoQueue);

		getline(cin, aux);
	}

	return 0;
}

bool resultadoEvPost(string const& expresion, int &resultado)
{
	bool fallo = false;

	stack<int> pilaOperandos;
	int op1, op2;

	for (char c : expresion)
	{
		if (fallo) break;
		else
		{
			if (esOperador(c))
			{
				op2 = pilaOperandos.top(); pilaOperandos.pop();
				op1 = pilaOperandos.top(); pilaOperandos.pop();
				pilaOperandos.push(evalua(op1, c, op2, fallo));
			}
			else
				pilaOperandos.push((int)(c - '0'));
		}
	}

	if (!fallo) resultado = pilaOperandos.top();

	return fallo;
}
int evalua(int op1, char c, int op2, bool &fallo)
{
	switch (c)
	{
	case '+':	return op1 + op2;
	case '*':	return op1 * op2;
	case '-':	return op1 - op2;
	case '/':
	{
		if (op2 == 0)
		{
			fallo = true;
			return 0;
		}
		return op1 / op2;
	}
	}
}
bool resultadoEvQueue(string const& expresion, int &resultado)
{
	bool fallo = false;

	queue<int> pilaOperandos;
	int op1, op2;

	for (char c : expresion)
	{
		if (fallo) break;
		else
		{
			if (esOperador(c))
			{
				op2 = pilaOperandos.front(); pilaOperandos.pop();
				op1 = pilaOperandos.front(); pilaOperandos.pop();
				pilaOperandos.push(evalua(op1, c, op2, fallo));
			}
			else
				pilaOperandos.push((int)(c- '0'));
		}
	}

	if (!fallo) resultado = pilaOperandos.front();

	return fallo;
}
void muestraResultado(bool fallaPost, int resPost, bool fallaQue, int resQue)
{
	if (fallaPost == fallaQue && fallaPost == true)	//DOS ERRORES
			cout << "ERROR = ERROR\n";
	else if (fallaPost == fallaQue)						//DOS EVALUACIONES SIN ERROR
	{
		if (resPost == resQue)								//IGUALDAD
			cout << resPost << " = " << resQue << '\n';
		else                                                //DISTINTAS
			cout << resPost << " != " << resQue << '\n';
	}
	else if (fallaPost == false)						//FALLA SOLO LA QUEUE
			cout << resPost << " != ERROR\n";
	else                                                //FALLA SOLO LA POSTF
			cout << "ERROR != " << resQue << '\n';
}
bool esOperador(char c)
{
	return c == '*' || c == '+' || c == '/' || c == '-';
}
