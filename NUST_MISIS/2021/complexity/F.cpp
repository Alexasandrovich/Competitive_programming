#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
bool isPerfectSquare(long double x)
{
  long double sr = sqrt(x);

  return ((sr - floor(sr)) == 0);
}

int main()
{
  unsigned long long inp;  
  cin >> inp;

  vector<int> upToRoot;
  for(int i = 1; i < sqrt(inp); i++)
  {
    if(inp % i == 0) upToRoot.emplace_back(i);
  }
  if(isPerfectSquare(inp)) cout << upToRoot.size() * 2 + 1 << endl;
  else cout << upToRoot.size() * 2 << endl;
  for_each(upToRoot.begin(), upToRoot.end(), [](int val){ cout << val << " ";});

  if(isPerfectSquare(inp)) cout << sqrt(inp) << " ";
  for_each(upToRoot.rbegin(), upToRoot.rend(), [inpVal = inp](int val){ cout << inpVal / val << " ";});

  return 0;
}
