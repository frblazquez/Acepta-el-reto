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
using namespace std;

//I don't really like this reference for the vector, it's for ordering it
int temporalDisorder(vector<int> &peopleAge, int ini, int end);

int main()
{
  int numPeople, aux; cin >> numPeople;

  while(numPeople)
  {
    vector<int> peopleAge;

    for(int i = 0; i < numPeople; i++)
    {cin >> aux; peopleAge.push_back(aux);}

    cout << temporalDisorder(peopleAge, 0, peopleAge.size()) << '\n';
    cin >> numPeople;
  }

  return 0;
}

int temporalDisorder(vector<int> &peopleAge, int ini, int end)
{
  //Just one element case
  if(end - ini <= 1)  return 0;

  //Recursive calls
  int mid = (ini+end)/2, disorder = 0;

  disorder += temporalDisorder(peopleAge, ini, mid);
  disorder += temporalDisorder(peopleAge, mid, end);

  //Merge
  vector<int> aux; int indexMid = mid, indexIni= ini;

  while(indexIni != mid && indexMid != end)
  {
    if(peopleAge[indexIni] > peopleAge[indexMid])
    {
      aux.push_back(peopleAge[indexMid]);
      indexMid++;

      disorder += mid-indexIni;
    }
    else
    {
      aux.push_back(peopleAge[indexIni]);
      indexIni++;
    }
  }

  while(indexIni != mid) {aux.push_back(peopleAge[indexIni]); indexIni++;}

  for(int i = 0; i < aux.size(); i++)
    peopleAge[ini+i] = aux[i];

  return disorder;
}


/* The idea is correct, the implementation isn't, needs more efficience.

int temporalDisorder(vector<int> &peopleAge, int ini, int end)
{
  if(ini == end-1)  return 0;

  int mid = (ini + end)/2;

  int disorder  = temporalDisorder(peopleAge, ini, mid);
      disorder += temporalDisorder(peopleAge, mid, end);

  int i = ini, m = mid; vector<int> aux;

  while(i != mid && m != end)
  {
    if(peopleAge[m] < peopleAge[i])
    {
      aux.push_back(peopleAge[m]);
      disorder += (mid - i);
      m++;
    }
    else
    {
      if(m == mid)  ini++;
      else          aux.push_back(peopleAge[i]);
      i++;
    }
  }

  if(m != mid)  while(i != mid) {aux.push_back(peopleAge[i]); i++;}
  for(int k = 0; k < aux.size(); k++) peopleAge[ini + k] = aux[k];

  return disorder;
}*/

/*

Wrong answer, don't really know why. Iterative solution.

int temporalDisorder(vector<int> &peopleAge, int ini, int end)
{
  if(ini == end-1)  return 0;

  int middle = (ini + end)/2;
  int disorder  = temporalDisorder(peopleAge, ini, middle);
      disorder += temporalDisorder(peopleAge, middle, end);

  vector<int> aux; int i = ini, m = middle;

  while(i != middle && m != end)
  {
    if(peopleAge[m] < peopleAge[i])
    {
      aux.push_back(peopleAge[m]);
      disorder += (middle - i);
      m++;
    }
    else
    {
      if(m != middle)
        aux.push_back(peopleAge[i]);
      else
        ini++;

      i++;
    }
  }

  if(m != middle)
  {
  while(i != middle)
  {
    aux.push_back(peopleAge[i]);
    i++;
  }

  for(int k = 0; k < aux.size(); k++)
    peopleAge[ini + k] = aux[k];
  }

  return disorder;
}
*/
/*
  This method is correct, however it's memory cost is to high for having an
  accepted veredict.
  Recursive solution!

#include <iostream>
#include <vector>
using namespace std;

int temporalDisorder(vector<int> const& v);

int main()
{
  int numPeople, aux; cin >> numPeople;
  vector<int> administrativeAge;

  while(numPeople)
  {
    administrativeAge.clear();

    for(int i = 0; i < numPeople; i++)
    {cin >> aux; administrativeAge.push_back(aux);}

    cout << temporalDisorder(administrativeAge) << '\n';
    cin >> numPeople;
  }

  return 0;
}

int temporalDisorder(vector<int> const& v)
{
  if(v.size() == 0 || v.size() == 1)  return 0;

  int disorder = 0, pivot = v[0];
  vector<int> lower, greater;

  for(int i = 1; i < v.size(); i++)
  {
    if(v[i] < pivot)
    {
      disorder += 1 + greater.size();
      lower.push_back(v[i]);
    }
    else
    {
      greater.push_back(v[i]);
    }
  }

  return disorder + temporalDisorder(lower) + temporalDisorder(greater);
}*/

/*
    This method is correct, howver it's too slow for being accepted.
    Recursive solution!

#include <iostream>
#include <list>
using namespace std;

int temporalDisorder(list<int> &v);

int main()
{
  int numPeople, aux; cin >> numPeople;

  while(numPeople)
  {
    list<int> administrativeAge;

    for(int i = 0; i < numPeople; i++)
    {cin >> aux; administrativeAge.push_back(aux);}

    cout << temporalDisorder(administrativeAge) << '\n';
    cin >> numPeople;
  }

  return 0;
}

int temporalDisorder(list<int> &v)
{
  if(v.size() == 0 || v.size() == 1)  return 0;

  int disorder = 0, pivot = v.front(), elem; v.pop_front();
  list<int> lower, greater;

  while(!v.empty())
  {
    elem = v.front(); v.pop_front();

    if(elem < pivot)
    {
      disorder += 1 + greater.size();
      lower.push_back(elem);
    }
    else
      greater.push_back(elem);
  }

  return disorder + temporalDisorder(lower) + temporalDisorder(greater);
}
*/
