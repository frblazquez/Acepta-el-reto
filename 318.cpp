#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

template <typename Valor>
class AristaDirigida_impl
{
public:
   AristaDirigida_impl(int v, int w, Valor valor) : v(v), w(w), _valor(valor) {};
   int from()     const { return v; }
   int to()       const { return w; }
   Valor valor()  const { return _valor; }
private:
   int v, w;
   Valor _valor;
};

template <typename Valor>
class AristaDirigida
{
public:
   AristaDirigida() : pimpl(nullptr) {};
   AristaDirigida(int v, int w, Valor valor) : pimpl(std::make_shared<AristaDirigida_impl<Valor>>(v, w, valor)) {};
   int from()    const { return pimpl->from(); }
   int to()      const { return pimpl->to(); }
   Valor valor() const { return pimpl->valor(); }
private:
   std::shared_ptr<AristaDirigida_impl<Valor>> pimpl;
};

template <typename Valor>
using AdysDirVal = std::vector<AristaDirigida<Valor>>;  // lista de adyacentes a un vértice

template <typename Valor>
class GrafoDirigidoValorado {
public:

   GrafoDirigidoValorado(int v) : _V(v), _E(0), _ady(_V) { minCostFrom0[0] = 0; for(int i=1; i<v; i++) minCostFrom0[i]=-1; }
   int V() const { return _V; }
   int E() const { return _E; }
   void ponArista(AristaDirigida<Valor> arista)
   {
      int v = arista.from();
      int w = arista.to();
      if (v >= _V || w >= _V) throw std::invalid_argument("Vertice inexistente");
      ++_E;
      _ady[v].push_back(arista);
   }

//----------------------------------------------------------------------------//
//---------------------------- MARP38.CPP ------------------------------------//

   /*
      This method returns the minimum cost of going from vertex 0 to vertex _V-1.
      If this is not possible returns -1 as error value.
   */
   int dePrimeroAUltimoRapido()
   {
     bool marcado[_V];            for(int i=0; i<_V; i++) marcado[i] = false;
     int  minCostFrom0[_V];
     std::vector<int> nexts;

     marcado[0] = true;
     minCostFrom0[0] = 0;
     nexts.push_back(0);

     int vertex, adyacente, edgeCost, vertexCost;

     while(!nexts.empty())
     {
       vertex = nexts.back(); nexts.pop_back();
       vertexCost = minCostFrom0[vertex];

       for(int j = 0; j < _ady[vertex].size(); j++)
       {
         adyacente = _ady[vertex][j].to();
         edgeCost =  _ady[vertex][j].valor();

         if(!marcado[adyacente] || vertexCost+edgeCost < minCostFrom0[adyacente])
         {
           marcado[adyacente]      = true;
           minCostFrom0[adyacente] = vertexCost + edgeCost;

           //Solo nos interesa explorar caminos que nos lleven más rápido al último vértice
           if(!marcado[_V-1] || minCostFrom0[adyacente]<minCostFrom0[_V-1])
           nexts.push_back(adyacente);
         }
       }

     }

     if(marcado[_V-1])  return minCostFrom0[_V-1];
     else               return -1;
   }

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//

private:
   int _V;   // número de vértices
   int _E;   // número de aristas
   std::vector<AdysDirVal<Valor>> _ady;   // vector de listas de adyacentes
};

#include <iostream>
using namespace std;

int main()
{
  int numVertex,aux; cin >> numVertex;
  int numEdges, init,end, findTime, totalTime;

  while(cin)
  {
    vector<int> page_loadTime;
    GrafoDirigidoValorado<int> internet(numVertex);

    for(int i = 0; i < numVertex; i++)
    {scanf("%d",&aux); page_loadTime.push_back(aux);}

    scanf("%d", &numEdges);

    for(int i = 0; i < numEdges; i++)
    {
      scanf("%d %d %d", &init, &end, &findTime);
      internet.ponArista({init-1,end-1,findTime + page_loadTime[end-1]});
    }

    totalTime = internet.dePrimeroAUltimoRapido();

    if(totalTime == -1) printf("IMPOSIBLE\n");
    else                printf("%d\n" ,totalTime + page_loadTime[0]);

    cin >> numVertex;
  }

  return 0;
}
