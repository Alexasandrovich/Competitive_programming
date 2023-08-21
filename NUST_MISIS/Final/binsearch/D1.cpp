#include <bits/stdc++.h>
using namespace std;

unsigned long long squareRoot(unsigned long long number)
{
  unsigned long long start = 0, end = number;
  unsigned long long mid = 0;
  unsigned long long ans = 0;
  double eps = 1e-6;

  while (start <= end) {
    mid = (start / 2) + (end / 2);
    auto residual = mid * mid - number; if(residual < 0) residual *= -1;
    if (residual < eps) {
      ans = mid;
      break;
    }
    if (mid * mid < number) {
      start = mid + 1;
      ans = mid;
    }
    else {
      end = mid - 1;
   }
 }
 return ans;

}
int main()
{
  unsigned long long inpNum = 0;
  while(cin >> inpNum)
  {
    cout << squareRoot(inpNum) << endl;
  }
  return 0;
} 
