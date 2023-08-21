#include<iostream>
using namespace std;

int lest(int k, int n)
{
  cout << k << " " << n << "\n";  
  int ans = 0;
  if(n == 0) 
  {
    ans += 1;
    return ans;
  }else if(k < n)
  {
    for(size_t i = k + 1; i < size_t(n + 1); i++)
    {
      ans += lest(i, n - i);  
    }
    return ans;
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  cout << lest(0, n);
  return 0;
}

