/*
*   Copyright © 2018
*
*   Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
*
*   Double degree in Mathematics-Computer engineering.
*   Complutense university, Madrid.
*   
*/

/*
    This problem could easily be solved iteratively, however, and following
    the teacher advise, I prefer to solve it recursively just for practise.
*/

#include <iostream>
using namespace std;

/*
    It's not a good practise using references for this methods...
    I'm using it because of the simplicity of the problem.
*/
long long int lengthToPaint(int thisStepLength, long long int &factor);

int main()
{
  int initLength; cin >> initLength;
  long long int fourPower;

  while(cin)
  {
    fourPower = 1;

    cout << lengthToPaint(initLength, fourPower) << '\n';
    cin >> initLength;
  }

  return 0;
}

long long int lengthToPaint(int thisStepLength, long long int &factor)
{
    factor *= 4;

    if(thisStepLength == 1) return factor;
    else                    return thisStepLength*factor + lengthToPaint(thisStepLength/2, factor);
}
