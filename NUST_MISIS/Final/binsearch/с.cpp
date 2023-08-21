#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

size_t getCountRopes(const vector<int>& ropes, int cutoff, int houseCount)
{
  size_t res = 0;
  for(const auto& rope : ropes)
  {
    res += rope / cutoff;
  }
  if(houseCount <= res) return 0;
  else return 1;
}

int upperBound(int houseCount, const vector<int>& ropes)
{
  int maxRopeSize = *max_element(ropes.begin(), ropes.end());
  int l = 0, r = maxRopeSize + 1;

  while(l < r)
  {
    int m = (l + r) / 2;
    if(getCountRopes(ropes, m, houseCount))
    {
      l = m + 1;
    }else {
      r = m;
    }
  }

  return r < maxRopeSize ? r - 1 : 0;
}

int main()
{
  int N = 0, K = 0;
  cin >> N >> K;
  vector<int> inp(N, 0);
  for(int i = 0; i < N; i++)
  {
    cin >> inp[i];
  }
  cout << upperBound(K, inp);
  return 0;
}

