#include <bits/stdc++.h>
 
using namespace std;

double getF(double x, int a, int b, int c, int d)
{
  return pow(x, 3) * a + pow(x, 2) * b + x * c + d;
}
 
int main()
{
  cout << setprecision(7);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  double l = -1, r = 1;
  while (getF(r, a, b, c, d) * getF(l, a, b, c, d) >= 0)
  {
    r *= 2;
    l *= 2;
  }
 
  int q = 100;
  for (;q--;)
  {
    double x, v1, v2;
    x = (l+r)/2;
    v1 = getF(x, a, b, c, d);
    v2 = getF(r, a, b, c, d);
    if (v1*v2<=0) l = x;
    else r = x;
  }
  cout << l;
  return 0;
}
