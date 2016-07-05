#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
  
  int N;
  cin>> N;
  
  string* solutions = new string[N];

  cin.ignore();

  for (int i = 0; i < N; i++)
  {
    getline(cin, solutions[i]);
  }

  for (int i = 0; i < N; i++) 
  {
    vector<string> words;
    istringstream iss(solutions[i]);
    
    string word;
    iss>> word;
    while (iss) 
    {
      words.push_back(word);
      iss>> word;
    }
    
    cout<< "Case #"<< i + 1<< ": ";
    
    for (int j = words.size() - 1; j >= 0; j--)
    {
      cout<< words[j]<< " ";
    }
    cout<< endl;
  }

  delete[] solutions;

}
