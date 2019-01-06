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
  int dimension, aux; cin >> dimension;
  
  while(dimension)
  {
    bool triangSuperior = true, triangInferior = true;
    
    for(int i = 0; i < dimension; i++)
    for(int j = 0; j < dimension; j++)
    {
      scanf("%d",&aux);
      
      triangSuperior &= (j<=i || aux == 0);
      triangInferior &= (i<=j || aux == 0);
    }
    
    if(triangSuperior || triangInferior)	
      cout << "SI\n";
    else 
      cout << "NO\n";
    
    cin >> dimension;
  }
    
  return 0;
}
