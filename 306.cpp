/*
*   Copyright © 2018
*
*   Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
*
*   Double degree in Mathematics-Computer engineering.
*   Complutense university, Madrid.
*   
*/

class matrix{
public:
  int m[2][2];

  matrix()
  {
    m[0][0] = 0; m[0][1] = 1;
    m[1][0] = 1; m[1][1] = 1;
  }
  matrix(int m00, int m01, int m10, int m11)
  {
    m[0][0] = m00; m[0][1] = m01;
    m[1][0] = m00; m[1][1] = m11;
  }

};

#include <iostream>
using namespace std;

const int k = 46337;
matrix fibMatrix;

matrix operator*(matrix const& m1, matrix const& m2)
{
  matrix m;

  m.m[0][0] = ((m1.m[0][0]*m2.m[0][0])%k + (m1.m[0][1]*m2.m[1][0])%k)%k;
  m.m[0][1] = ((m1.m[0][0]*m2.m[0][1])%k + (m1.m[0][1]*m2.m[1][1])%k)%k;
  m.m[1][0] = ((m1.m[1][0]*m2.m[0][0])%k + (m1.m[1][1]*m2.m[1][0])%k)%k;
  m.m[1][1] = ((m1.m[1][0]*m2.m[0][1])%k + (m1.m[1][1]*m2.m[1][1])%k)%k;

  return m;
}

matrix nTermFib(int n)
{
  if(n   == 1) return fibMatrix;

  matrix m;

  if(n%2 == 0)
  {
    m = nTermFib(n/2);
    return m*m;
  }
  else
  {
    m = nTermFib((n-1)/2);
    return ((m*m)*fibMatrix);
  }
}

int main()
{
  int n; cin >> n;

  while(n)
  {
    cout << nTermFib(n).m[0][1] << endl;
    cin >> n;
  }

  return 0;
}


/*
#include <iostream>
#include <vector>
using namespace std;

const int k = 46337;

int nTerm(vector<int> &v, int n);

int main()
{
  vector<int> fibSequence;
  fibSequence.push_back(1); fibSequence.push_back(1);
  fibSequence.push_back(2); fibSequence.push_back(3);

  int n; cin >> n;

  while(n)
  {
    cout << nTerm(fibSequence, n) << '\n';
    cin >> n;
  }


  return 0;
}


    Memory limit exceded, pretty obvios knowing that the range in wich n moves
    is 2e31. That means that v could need 8Gb (more or less).

    Even with memory enough, the worst case cost is O(n), not fast enough.
*
int nTerm(vector<int> &v, int n)
{
  while(v.size() < n) v.push_back((v[v.size()-1] + v[v.size() - 2])%k);

  return v[n-1];
}*


#include <iostream>
#include <vector>
using namespace std;

typedef int matrix[2][2];

const int k = 46337;
const matrix fibMatrix = {{0,1},{1,1}};

matrix nTermFib(int n);

int main()
{
  int n; cin >> n;
  matrix m;

  while(n)
  {
    m = nTermFib(n);

    cout << m[0][1] << endl;
    cin >> n;
  }

  return 0;
}

matrix operator*(matrix const& m1, matrix const& m2)
{
  matrix m;

  m[0][0] = (m1[0][0]*m2[0][0] + m1[0][1]*m2[1][0])%k;
  m[0][1] = (m1[0][0]*m2[0][1] + m1[0][1]*m2[1][1])%k;
  m[1][0] = (m1[1][0]*m2[0][0] + m1[1][1]*m2[1][0])%k;
  m[1][1] = (m1[1][0]*m2[0][1] + m1[1][1]*m2[1][1])%k;

  return m;
}

matrix nTermFib(int n)
{
  if(n == 1)   return fibMatrix;

  matrix aux;

  if(n%2 == 0)
  {
    aux = nTermFib(n/2);
    return aux*aux;
  }
  else
  {
    aux = nTermFib((n-1)/2);
    return aux*aux*fibMatrix;
  }
}
*/
