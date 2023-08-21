#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{ 
  int n = 0;
  cin >> n;
  vector<int> inp(n);
  
  for(size_t i = 0; i < n; i++)
  {
    cin >> inp[i];
  }
  vector<int> sort_arr(*max_element(inp.begin(), inp.end()) + 1, 0);
  for(size_t i = 0; i < n; i++)
  {
    sort_arr[inp[i]] += 1;
  }
  for(size_t i = sort_arr.size() - 1; i > 0; i--)
  {
    while(sort_arr[i]-- > 0)
    {
      cout << i << " ";  
    }
  }
  return 0;
}

