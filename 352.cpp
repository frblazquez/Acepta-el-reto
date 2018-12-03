#include <iostream>
#include <vector>
#include <stdexcept>

using Adys = std::vector<int>;  // lista de adyacentes a un vértice

class Grafo {

   int _V;   // número de vértices
   int _E;   // número de aristas
   std::vector<Adys> _ady;   // vector de listas de adyacentes

public:

   /**
    * Crea un grafo con V vértices.
    */
   Grafo(int v) : _V(v), _E(0), _ady(_V) {}

   /**
    * Devuelve el número de vértices del grafo.
    */
   int V() const { return _V; }

   /**
    * Devuelve el número de aristas del grafo.
    */
   int E() const { return _E; }


   /**
    * Añade la arista v-w al grafo.
    * @throws invalid_argument si algún vértice no existe
    */
   void ponArista(int v, int w) {
      if (v >= _V || w >= _V)
         throw std::invalid_argument("Vertice inexistente");
      ++_E;
      _ady[v].push_back(w);
      _ady[w].push_back(v);
   }


   /**
    * Devuelve la lista de adyacencia de v.
    * @throws invalid_argument si v no existe
    */
   Adys const& ady(int v) const {
      if (v >= _V)
         throw std::invalid_argument("Vertice inexistente");
      return _ady[v];
   }


   /**
    * Muestra el grafo en el stream de salida o (para depurar)
    */
   void print(std::ostream & o = std::cout) const {
      o << _V << " vértices, " << _E << " aristas\n";
      for (auto v = 0; v < _V; ++v) {
         o << v << ": ";
         for (auto w : _ady[v]) {
            o << w << " ";
         }
         o << "\n";
      }
   }

   //----------------------------------------------------------------------------//
   //--------------------------- MÉTODOS AÑADIDOS -------------------------------//
   //----------------------------------------------------------------------------//
   // Francisco Javier Blázquez Martínez ----------------------- frblazqu@ucm.es //

   int numElemsMayorCompConexa() const
   {
     if(_V == 0)  return 0;

     std::vector<bool> marcados(_V, false);   // Para marcar los vértices visitados
     std::vector<int>  pendientes;            // Para guardar los vértices por explorar
     int maxElemsComponente = 1, numElemsEstaComponente;

     for(int i = 0; i < _V; i++)
     {
       if(!marcados[i])
       {
       numElemsEstaComponente = 1;

       pendientes.push_back(i);
       marcados[i] = true;

       while(!pendientes.empty())
       {
         int vertex = pendientes.back(); pendientes.pop_back();

         for(int j = 0; j < _ady[vertex].size(); j++)
         {
           int ady = _ady[vertex][j]; // ady es adyacente a vertex

           // Si el vértice no está marcado, uno más de la componente conexa
           if(!marcados[ady])
           {
             numElemsEstaComponente++;
             pendientes.push_back(ady);
             marcados[ady] = true;

             if(numElemsEstaComponente > maxElemsComponente)
                maxElemsComponente = numElemsEstaComponente;
           }
         }
       }
     }
     }

     return maxElemsComponente;
   }

};

/*
*   Copyright © 2018
*
*   Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
*
*   Doble grado Ingeniería informática - Matemáticas
*   Universidad Complutense de Madrid
*/

#include <iostream>
using namespace std;

int main()
{
  int numCases; cin >> numCases;
  int numVertex, numEdges;
  int init, end;

  while(numCases--)
  {
    cin >> numVertex >> numEdges;

    Grafo friends(numVertex);

    for(int i = 0; i < numEdges; i++)
    {
      cin >> init >> end;
      friends.ponArista(init-1, end-1);
    }

    cout << friends.numElemsMayorCompConexa() << endl;
  }

  return 0;
}
