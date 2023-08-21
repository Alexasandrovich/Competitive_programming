#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
  long double inp = 0;  
  while(cin >> inp)  
  {
    cout << floorl(sqrtl(inp)) << endl;
  }
}
