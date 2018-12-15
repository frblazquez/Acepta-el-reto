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
#include <string>
using namespace std;

int main()
{
  int numCases; cin >> numCases;
  string word; ;

  while(numCases--)
  {
    bool vowels[5] = {false, false, false, false, false};
    cin >> word;

    for(int i = 0; i < word.size(); i++)
    {
      switch(word[i])
      {
        case 'a': vowels[0] = true; break;
        case 'e': vowels[1] = true; break;
        case 'i': vowels[2] = true; break;
        case 'o': vowels[3] = true; break;
        case 'u': vowels[4] = true; break;
      }

    }

    if(vowels[0] && vowels[1] && vowels[2] && vowels[3] && vowels[4])
      cout << "SI\n";
    else
      cout << "NO\n";
  }

  return 0;
}
