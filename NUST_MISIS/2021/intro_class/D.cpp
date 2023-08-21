#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a;
  a.push_back(0);
  for(int i = 1; i <= n; ++i){
    a.push_back(i + a[i - 1] + a[i - 1]);
  }
  cout << a[n - 1];
  return 0;
}


