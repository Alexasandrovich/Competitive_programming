#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> ABC(n, vector<int>(3));
  vector<int> dp(n);
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      cin >> ABC[i][j];
    }
  }
  dp[0] = ABC[0][0];
  for(int i = 1; i < n; i++)
  {
    dp[i] = ABC[i][0] + (i >= 1 ? dp[i-1] : 0);
    if(i > 0)
    {
      dp[i] = min(dp[i], ABC[i-1][1] + (i >= 2 ? dp[i-2] : 0));
    }
    if(i > 1)
    {
      dp[i] = min(dp[i], ABC[i-2][2] + (i >= 3 ? dp[i-3] : 0));
    }
  }
  cout << dp[n-1];
  return 0;
}
