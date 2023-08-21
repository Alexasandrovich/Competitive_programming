#include <vector>
#include <iostream>
#include <algorithm>

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

  // bubble sort
  for(size_t i = 0; i < n; i++)
  {
    for(size_t j = i; j < n; j++)
    {
      if(inp[i] < inp[j])
      {
        swap(inp[i], inp[j]);
      }
    }
  }
  for(size_t i = 0; i < n; i++) 
  {
    cout << inp[i] << " ";
  }
}
