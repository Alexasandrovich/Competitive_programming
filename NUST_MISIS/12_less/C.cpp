#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N = 0, K = 0, S = 0;
  cin >> N >> K >> S;
  vector<int> a;
  int tmp = 0;
  for(int i = 0; i < N; i++)
  {
    cin >> tmp;
    a.emplace_back(tmp);
  }
  int sum = 0;
  for(int i = 0; i <= K; i++){
  
    sum += a[i];
  }
  int index = 0;
  for(int i = 1; i < N - K - 1; i++)
  {
    sum += a[i+K];
    sum -= a[i-1];
    if(sum <= S)
    {
      index = i;
      if(S == sum)
      {
        cout << index;
      }
    }
  }

  return 0;
}


