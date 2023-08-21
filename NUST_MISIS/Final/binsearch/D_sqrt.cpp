#include <bits/stdc++.h>
#include <limits>
using namespace std;

unsigned long long squareRoot(unsigned long long number)
{
  unsigned long long start = 0, end = numeric_limits<unsigned long long>::max();
  unsigned long long mid = 0;
  unsigned long long ans = 0;

  while (start <= end) {
    mid = (start + end) / 2;
    if (mid * mid == number) {
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
