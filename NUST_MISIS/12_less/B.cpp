#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N = 0, K = 0;
  cin >> N >> K;
  vector<int> max(N), indexmax(N);
  vector<int> a;
  int tmp = 0;
  for(int i = 0; i < N; i++)
  {
    cin >> tmp;
    a.emplace_back(tmp);
  }

  max[N-1] = a[N-1];
  indexmax[N-1] = N-1;
  for(int i = N-2; i >= 0; i--)
  {
    max[i] = max[i+1];
    indexmax[i] = indexmax[i+1];
    if(a[i] >= max[i])
    {
      max[i] = a[i];
      indexmax[i] = i;
    }
  }

  int best = 0;
  int il = -1;
  int ir = -1;
  for(int i = 0; i < N-K-1; i++)
  {
    int cur = a[i] + max[i+K+1];
    if(cur > best)
    {
      best = cur;
      il = i;
      ir = indexmax[i+K+1];
    }
  }
  cout << ++il << " " << ++ir;
  return 0;
}

