#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n = 3;
  cin >> n;
  vector<int> st(n);
  vector<int> dp(n);
  vector<int> p(n); // p[i] = j
  for(int i = 0; i < n; i++)
  {
    cin >> st[i];
  }
  dp[0] = 0;
  p[0] = st[0];
  for(int i = 0; i <= n; i++)
  {
    dp[i] = dp[i-1] + st[i];
    p[i] = i - 1;
    if(i > 1 && dp[i-2] + st[i] > dp[i])
    {
      dp[i] = dp[i-2] + st[i];
      p[i] = i - 2;
    }
  }
  cout << dp[n] << "\n";
  vector<int> ans;

  for(int i = n; i != 0; i = p[i])
  {
    ans.push_back(i);
  }

  for(int i = ans.size() - 1; i >= 0; i--)
  {
    cout << ans[i] << " ";
  }
  return 0;
}
