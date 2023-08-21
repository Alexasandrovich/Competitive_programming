#include<iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{
  unordered_set<string> writings;
  int N = 0;
  cin >> N;
  string input;
  for(size_t i = 0; i < N; i++)
  {
    cin >> input;
    writings.emplace(input);
  }
  cout << writings.size() << endl;
  
}
