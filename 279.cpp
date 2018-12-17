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

   bool esBipartito() const
   {
     if(_V <= 1)  return true;

     bool bipartito = true, oposite;
     int vertex, adyacente;

     bool marcado[_V];    for(int i = 0; i < _V; i++) marcado[i]   = false;
     bool rojoNegro[_V];  for(int i = 0; i < _V; i++) rojoNegro[i] = false;
     std::vector<int> pendientes;

     for(int i = 0; i < _V && bipartito; i++)
     {
       if(!marcado[i])
       {
         pendientes.push_back(i);
         marcado[i] = true;      // Lo marcamos como visitado
         rojoNegro[i] = true;    // El primer vértice de la componente conexa es rojo (true)

         while(!pendientes.empty() && bipartito)
         {
           vertex   = pendientes.back(); pendientes.pop_back(); // Tomamos el vértice
           oposite  = (rojoNegro[vertex]? false : true);        // Color distinto para los adyacentes

           for(int j=0; j<_ady[vertex].size(); j++)
           {
             adyacente = _ady[vertex][j];             // Tomamos el vértice adyacente

             if(!marcado[adyacente])
             {
               marcado[adyacente]   = true;
               rojoNegro[adyacente] = oposite;
               pendientes.push_back(adyacente);
             }
             else bipartito &= (rojoNegro[adyacente] == oposite);
           }
         }

       }
     }

     return bipartito;
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
  int numVertex, numEdges;
  cin >> numVertex;

  while(cin)
  {
    cin >> numEdges;

    Grafo graph(numVertex);

    int origin, end;
    for(int i = 0; i < numEdges; i++)
    {
      cin >> origin >> end;
      graph.ponArista(origin, end);
    }

    if(graph.esBipartito()) cout << "SI\n";
    else                    cout << "NO\n";

    cin >> numVertex;
  }

  return 0;
}
