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
#include <string>
using namespace std;

char complementario(char c);

int main()
{
	string leido; vector<char> v;
	int stackPointer; bool finCaso;

	getline(cin, leido);

	while (cin)
	{
		stackPointer = -1;		//índice del último elemento añadido.
		finCaso = false;		//para cortar la ejecución si ya no puede ser válido.

		for (int i = 0; i < leido.size() && !finCaso; i++)
		{
			if		(leido[i] == '{' || leido[i] == '(' || leido[i] == '[')
			{
				v.push_back(leido[i]); stackPointer++;
			}
			else if (leido[i] == '}' || leido[i] == ')' || leido[i] == ']')
			{
				if (stackPointer < 0 || complementario(leido[i]) != v[stackPointer])
					finCaso = true;
				else
				{
					stackPointer--; v.pop_back();
				}
					
			}
		}

		if (finCaso || v.size() > 0) cout << "NO\n";
		else						 cout << "YES\n";

		v.clear();

		getline(cin, leido);
	}

	return 0;
}

char complementario(char c)
{
	switch (c)
	{
	case ']':	return '[';
	case '}':	return '{';
	case ')':	return '(';
	default:	throw("Eres un makineta!");
	}
}
