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

int main()
{
	int numCases, max, min; char c;
  	cin >> numCases;

  	while(numCases--){
    
      cin >> max >> c >> min;
      
      if(max < min) cout << "MAL\n";
      else 			cout << "BIEN\n";
  	}  
  	
  	return 0;
}
