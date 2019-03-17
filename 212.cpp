/*
*   Copyright © 2019
*
*   Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
*
*   Double degree in Mathematics-Computer engineering.
*   Complutense university, Madrid.
*
*/

#include <iostream>
using namespace std;

const int MAX_VERTICES = 51;
//int unionFind[MAX_VERTICES];

//int father(int pos)
//{
//  if(unionFind[pos] != pos)
//    unionFind[pos] = father(unionFind[pos]);
//
//  return unionFind[pos];
//}

int main()
{
  int numEdges, numVertices, a, b;
  int vertEdges[MAX_VERTICES];
  cin >> numEdges;

  while(numEdges)
  {
    cin >> numVertices;

    //for(int i = 1; i <= numVertices; i++)
    //  unionFind[i] = i;

    for(int i = 1; i <= numVertices; i++)
      vertEdges[i]  = 0;

    for(int i = 1; i <= numEdges; i++)
    {
      cin >> a >> b;

      vertEdges[a]++;
      vertEdges[b]++;

      //unionFind[father(b)] = a;
    }

    int cont = 0;

    for(int i = 1; i <= numVertices; i++)
      if(vertEdges[i]%2)  cont++;

    if(cont == 0 || cont == 2)  cout << "SI\n";
    else                        cout << "NO\n";
    
    cin >> numEdges;
  }

  return 0;
}
