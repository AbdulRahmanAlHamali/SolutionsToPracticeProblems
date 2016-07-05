#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main()
{
  int N;
  cin>> N;

  vector<string> solutions;

  cin.ignore();
  for (int i = 0; i < N; i++)
  {
    string input;
    getline(cin, input);

    string result = "";

    int numberPressedOld = -1;
    int numberPressed;
    int nTimes;
    for (int j = 0; j < input.length(); j++)
    {
      if (input[j] != ' ')
      {
        if (input[j] <= 'r')
        {
          nTimes = ((input[j] - 'a' + 1) % 3);
          numberPressed = ceil(((input[j] - 'a' + 1) + 3) / 3.0);
        } else if (input[j] == 's')
        {
          nTimes = 4;
          numberPressed = 7;
        } else if (input[j] == 'z') {
          nTimes = 4;
          numberPressed = 9;
        } else {
          nTimes = ((input[j] - 'a') % 3);
          numberPressed = ceil(((input[j] - 'a' + 1) + 2) / 3.0);
        }

        if (nTimes == 0)
        {
          nTimes = 3;
        }

      } else 
      {
        nTimes = 1;
        numberPressed = 0;
      }
      
      if (numberPressedOld == numberPressed) {
        result+= ' ';
      }

      for (int k = 0; k < nTimes; k++)
      {
        result+= to_string(numberPressed);
      }
      numberPressedOld = numberPressed;

    }
    solutions.push_back(result);    
  }

  for (int i = 0; i < N; i++)
  {
    cout<< "Case #"<< i + 1<< ": "<< solutions[i]<< endl;
  }
}
