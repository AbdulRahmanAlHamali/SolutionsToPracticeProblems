#include <iostream>
#include <utility>
using namespace std;

pair<int, int> findSolutionSlow(int *list, int length, int credit);

int main() 
{
  int N;
  cin>> N;
  pair<int, int>* solutions = new pair<int, int>[N];
  for (int i = 0; i < N; i++)
  {
    int C, P;
    cin>> C>> P;
    int* l = new int[P];
    
    for (int j = 0; j < P; j++)
    {
      cin>> l[j];
    }

    solutions[i] = findSolutionSlow(l, P, C);

    delete [] l;
  }

  for (int i = 0; i < N; i++) {
    cout<< "Case #"<< i + 1<< ": "<< solutions[i].first + 1<<
        " "<< solutions[i].second + 1<< endl;
  }

  delete [] solutions;
}

pair<int, int> findSolutionSlow(int *list, int length, int credit)
{
  for (int i = 0; i < length; i++)
  {
    for (int j = i + 1; j < length; j++) 
    {
      if (list[i] + list[j] == credit)
      {
        pair<int, int> p(i, j);
        return p;
      }
    }
  }
}
