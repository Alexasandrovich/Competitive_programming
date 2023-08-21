#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll F_calc(const ll& a, const ll& b, ll& pre_last, ll& last)
{
  ll res = a * last + b * pre_last;
  pre_last = last;
  last = res;
  return res;
}

int main()
{
  int N = 4, a = 2, b = 3;
  ll F_last = 1, F_pre_last = 0;
  cin >> N >> a >> b;
  cin >> F_last >> F_pre_last;
  if(N == 0)
  {
    cout << F_pre_last;
    return 0;
  }else if(N == 1)
  {
    cout << F_last;
    return 0;
  }

  for(int i = 2; i <= N; i++)
  {
    F_calc(a, b, F_pre_last, F_last);
  }
  cout << F_last;
  return 0;
}


