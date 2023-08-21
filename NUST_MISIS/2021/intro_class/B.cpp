#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n = 0;
  cin >> n;
  vector<double> inp(n);
  for(size_t i = 0; i < n; i++)
  {
    cin >> inp[i]; 
  }

  reverse(inp.begin(),inp.end());
  for(const auto& el : inp)
  {
    cout << el << " ";
  }
  return 0;
}
