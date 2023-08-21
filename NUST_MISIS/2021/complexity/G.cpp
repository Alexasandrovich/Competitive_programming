#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n = 0;
  cin >> n;
  vector<unsigned long long> inp(n, 0);
  for(size_t i = 0; i < n; i++)
  {
    cin >> inp[i];
  }
  int ans = 0;
  for(size_t i = 0; i < n; i++)
  {
    for(size_t j = i+1; j < n; j++)
    {
      for(size_t k = j+1; k < n; k++)
      {
        if(inp[i] < inp[j] + inp[k] &&
           inp[j] < inp[i] + inp[k] &&
           inp[k] < inp[i] + inp[j]) ans++;
      }
    }
  }
  cout << ans;
  return 0;
}
