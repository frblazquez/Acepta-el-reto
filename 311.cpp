/*
*   Copyright © 2018
*
*   Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
*
*   Double degree in Mathematics-Computer engineering.
*   Complutense university, Madrid.
*
*/

//Cómo preservar el orden ante claves iguales??
//Falla en casos con identificadores repetidos!!

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void reemplazaPrimero(vector<pair<int,string>> &heap);
void flotarUltimo(vector<pair<int,string>> &heap);
void mostrar(vector<pair<int,string>> &heap);

int main()
{
  int numEvents; cin >> numEvents;
  vector<pair<int,string>> events;
  events.push_back({-1,""});
  char code; string name; int gravity;

  for(int i = 0; i<numEvents; i++)
  {
    cin >> code;

    if(code == 'A')
    {
      if(events.size()>1)
      {
      cout << events[1].second << '\n';

      reemplazaPrimero(events);
      }
    }
    else
    {
      cin >> name >> gravity;

      events.push_back({gravity,name});
      flotarUltimo(events);
    }
  }

  cout << "----\n";

  return 0;
}

void mostrar(vector<pair<int,string>> &heap)
{
  for(int i = 1; i < heap.size(); i++)
    cout << heap[i].first << " ";  cout << endl;
  for(int i = 1; i < heap.size(); i++)
    cout << heap[i].second << " "; cout << endl;
}
void reemplazaPrimero(vector<pair<int,string>> &heap)
{
  int i = 1, izq,dcho;

  while(i < heap.size())
  {
    izq = 2*i; dcho = 2*i+1;

    //Ante igualdad, tomamos los de la izquierda primero
    if(dcho < heap.size() && heap[dcho].first > heap[izq].first)
      {heap[i] = heap[dcho]; i = dcho;}
    else if(izq < heap.size())
      {heap[i] = heap[izq];  i = izq;}
    else break;
  }

  heap[i] = heap.back(); heap.pop_back();
}
void flotarUltimo(vector<pair<int,string>> &heap)
{
  int son = heap.size()-1, father = son/2;
  pair<int,string> aux;

  while(father != 0 && heap[father].first < heap[son].first)
  {
    aux=heap[father];
    heap[father] = heap[son];
    heap[son]=aux;

    son = father;
    father = son/2;
  }
}
