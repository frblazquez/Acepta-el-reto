/*
*   Copyright © 2019
*
*   Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
*
*   Double degree in Mathematics-Computer engineering.
*   Complutense university, Madrid.
*
*/

struct teleski
{
  int ini;
  int end;
  int time;

  bool operator<(teleski const& t2) const
  {
    return ini < t2.ini;
  }
};

struct tSolution
{
  int optimist;
  int time;
  int position;
  int meters;

  bool operator<(tSolution const& s2) const
  {
    return optimist < s2.optimist || (optimist == s2.optimist && meters < s2.meters);
  }
};

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_TSKIS = 25;

int initPoint;
int endPoint;
int freeTime;
int numSkis;
int bestSol;
teleski tskis[MAX_TSKIS];

void BandB(priority_queue<tSolution> &cola);

int main()
{
  cin >> numSkis;

  while(numSkis)
  {
    // Lectura de datos
    for(int i = 0; i < numSkis; i++)
      cin >> tskis[i].ini >> tskis[i].end >> tskis[i].time;

    cin >> initPoint >> endPoint >> freeTime;

    // Ordenación de los teleskis
    sort(tskis, tskis + numSkis);

    // Para mostrar la ordenación
    //for(int i = 0; i < numSkis; i++)
    //  cout << tskis[i].ini << " " << tskis[i].end << " " << tskis[i].time << endl;

    priority_queue<tSolution> cola;
    tSolution first;

    bestSol = -1;   // Código de imposible

    first.position = initPoint;
    first.optimist = freeTime;
    first.time     = freeTime;
    first.meters   = 0;

    // El primer elemento va a la cola
    cola.push(first);

    // Llamamos al método de ramificación y acotación
    BandB(cola);

    // Mostramos la solución obtenida
    if(bestSol == -1) cout << "IMPOSIBLE\n";
    else              cout << bestSol << '\n';

    cin >> numSkis;
  }

  return 0;
}

void BandB(priority_queue<tSolution> &cola)
{
  tSolution act, next;

  while(!cola.empty() && cola.top().optimist > bestSol)
  {
    act = cola.top(); cola.pop();

    // Si podemos descencer hasta la posición de destino
    if(act.position >= endPoint && act.position - endPoint <= act.time)
    {
      // Miramos si mejoramos la mejor solución y lo actualizamos
      if(act.meters + (act.position-endPoint) > bestSol)
        bestSol = act.meters + act.position - endPoint;
    }

    // Exploramos posibles caminos a partir de este nodo
    for(int i = 0; i < numSkis && act.position >= tskis[i].ini; i++)
    {
      if(act.position-tskis[i].ini <= act.time && act.optimist - tskis[i].time > bestSol)
      {
        next.optimist = act.optimist - tskis[i].time;
        next.meters   = act.meters + (act.position - tskis[i].ini);
        next.position = tskis[i].end;
        next.time     = act.time - (act.position - tskis[i].ini) - tskis[i].time;

        cola.push(next);
      }
    }

  }
}

/*
priority_queue<tSolution> testQueue;

tSolution s1,s2, s3, s4;

s1.optimist = 1;  s1.meters = 100;
s2.optimist = 2;  s2.meters = 40;
s3.optimist = 3;  s3.meters = 200;
s4.optimist = 2;  s4.meters = 120;

testQueue.push(s2);
testQueue.push(s1);
testQueue.push(s4);
testQueue.push(s3);

for(int i = 0; i < 4; i++)
{
  cout << testQueue.top().optimist << " " << testQueue.top().meters << endl;
  testQueue.pop();
 }
 */
