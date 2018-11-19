#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>

// Comparator dice cuándo un valor de tipo T es más prioritario que otro
template <typename T = int, typename Comparator = std::less<T>>
class PriorityQueue {

   // vector que contiene los datos
   std::vector<T> array;     // primer elemento en la posición 1

   /* Objeto función que sabe comparar elementos.
    antes(a,b) es cierto si a es más prioritario que b (a debe salir antes que b) */
   Comparator antes;

public:

   PriorityQueue(Comparator c = Comparator()) : array(1), antes(c) {}

   /* Constructor a partir de un vector de elementos */
   PriorityQueue(std::vector<T> const& v_ini, Comparator c = Comparator()) :
   array(v_ini.size() + 1), antes(c) {
      for (auto i = 0; i < v_ini.size(); ++i)
         array[i + 1] = v_ini[i];
      monticulizar();
   }

   PriorityQueue(PriorityQueue<T, Comparator> const&) = default;

   PriorityQueue<T, Comparator> & operator=(PriorityQueue<T, Comparator> const&) = default;

   ~PriorityQueue() = default;


   /* Insertar el elemento x (que incluye su prioridad).
    Si no hay espacio, el array se agranda. */
   void push(T const& x) {
      array.push_back(x);
      flotar(array.size()-1);
   }

   /* Devuelve el número de elementos en la cola. */
   int size() const { return array.size() - 1; }

   /* Averigua si la cola con prioridad está vacía. */
   bool empty() const { return size() == 0; }

   /* Si la cola no es vacía, devuelve el elemento más prioritario. */
   T const& top()  const {
      if (empty()) throw std::domain_error("La cola vacia no tiene top");
      else return array[1];
   }

   /* Si la cola no es vacía, elimina el elemento más prioritario. */
   void pop() {
      if (empty())
         throw std::domain_error("Imposible eliminar el primero de una cola vacia");
      else {
         array[1] = std::move(array.back());
         array.pop_back();
         if (!empty()) hundir(1);
      }
   }

   /* Si la cola no es vacía, elimina y devuelve el elemento más prioritario. */
   void pop(T & prim) {
      if (empty())
         throw std::domain_error("Imposible eliminar el primero de una cola vacia");
      else {
         prim = std::move(array[1]);
         array[1] = std::move(array.back());
         array.pop_back();
         if (!empty()) hundir(1);
      }
   }

   /* Muestra el montículo por la salida o (solo para depurar) */
   void print(std::ostream & o) const {
      for (auto i = 1; i <= size(); ++i)
         o << array[i] << " ";
   }

private:

   /* Flota el elemento situado en la posición n del montículo. */
   void flotar(int i) {
      T elem = std::move(array[i]);
      int hueco = i;
      while (hueco != 1 && antes(elem, array[hueco / 2])) {
         array[hueco] = std::move(array[hueco / 2]);
         hueco /= 2;
      }
      array[hueco] = std::move(elem);
   }

   /* Hunde el elemento situado en la posición n del montículo. */
   void hundir(int i) {
      T elem = std::move(array[i]);
      int hueco = i;
      int hijo = 2 * hueco; // hijo izquierdo, si existe
      while (hijo <= size())  {
         // cambiar al hijo derecho si existe y va antes que el izquierdo
         if (hijo < size() && antes(array[hijo + 1], array[hijo]))
            ++hijo;
         // flotar el hijo si va antes que el elemento hundiéndose
         if (antes(array[hijo], elem)) {
            array[hueco] = std::move(array[hijo]);
            hueco = hijo; hijo = 2 * hueco;
         }
         else break;
      }
      array[hueco] = std::move(elem);
   }

   /* Convierte un vector en un montículo. */
   void monticulizar() {
      for (auto i = size() / 2; i > 0; --i)
         hundir(i);
   }
};

template <typename T, typename Comparator>
inline std::ostream& operator<<(std::ostream & o, PriorityQueue<T,Comparator> const& a){
   a.print(o);
   return o;
}


#endif /* PRIORITYQUEUE_H_ */

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

int main()
{
  int numCases,elem; cin >> numCases;

  while(cin)
  {
  PriorityQueue<int, greater<int>> underMedian;
  PriorityQueue<int>               overMedian;
  bool hayCero = false;

  for(int i = 0; i < numCases; i++)
  {
    cin >> elem;

    if(elem == 0)
    {
      if(hayCero) cout << " "; hayCero = true;

      if(underMedian.empty())  cout << "ECSA";
      else                    {cout << underMedian.top(); underMedian.pop();}
    }
    else
    {
      if(underMedian.empty())
        underMedian.push(elem);
      else if(underMedian.top() < elem)
        overMedian.push(elem);
      else
        underMedian.push(elem);
    }

    if(underMedian.size() > overMedian.size()+1)
    {
      overMedian.push(underMedian.top());
      underMedian.pop();
    }
    if(overMedian.size() > underMedian.size())
    {
      underMedian.push(overMedian.top());
      overMedian.pop();
    }
  }

  cout << '\n';
  cin >> numCases;
  }

  return 0;
}

/*
#include <iostream>
#include <list>
using namespace std;

int main()
{
  int numEvents, aux; cin >> numEvents;

  while(cin)
  {
    list<int> eventos;
    list<int> listaEspera;
    int cerosAparecidos = 0;
    int numCeros = 0;
    auto mediana = listaEspera.begin();

    for(int i = 0; i < numEvents; i++)
    {
      cin >> aux; eventos.push_back(aux);

      if(aux == 0) cerosAparecidos++;
    }

    for(auto it = eventos.begin(); it != eventos.end(); ++it)
    {
      aux = *it;//Reads the event

      if(aux==0) //The butcher attends a client
      {
        cerosAparecidos++;

        if(listaEspera.size()==0)
        {
          cout << "ECSA";
          if(cerosAparecidos != numCeros) cout << " ";
        }

        else
        {
          cout << *mediana; //Last blank space will disturb us!
          if(cerosAparecidos != numCeros) cout << " ";

          mediana = listaEspera.erase(mediana);

          if(listaEspera.size() != 0 && listaEspera.size()%2==0) --mediana;
        }
      }
      else      //Another client arrives
      {
        //Ordered insertion! (changing mediana value if needed)
        if(listaEspera.size()==0) mediana = listaEspera.insert(listaEspera.begin(), aux);

        else
        {
        auto it = mediana;

        if(aux < *it)
        {
          while(aux < *it && it != listaEspera.begin()) --it;
          listaEspera.insert(it,aux);

          if(listaEspera.size()%2==0) --mediana;
        }
        else
        {
          while(aux > *it && it != listaEspera.end()) ++it;
          listaEspera.insert(it,aux);

          if(listaEspera.size()%2==1) ++mediana;
        }
        }
      }
    }

    cout << '\n';
    cin >> numEvents;
  }

  return 0;
}
*/
