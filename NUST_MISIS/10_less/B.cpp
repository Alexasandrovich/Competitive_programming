#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Colors
{
  vector<int> c1;
  vector<int> c2;
  vector<int> c3;
};

int main()
{
  int n;
  cin >> n;
  vector<Colors> dp(n);
  dp[0].c1[0] = 1;
  dp[0].c2[0] = 1;
  dp[0].c3[0] = 1;
  for(int i = 1; i < n; i++)
  {
    dp[i].c1[i] = dp[i-1].c1[i-1] + dp[i-1].c2[i-1] + dp[i-1].c3[i-1];
    dp[i].c2[i] = dp[i-1].c2[i-1] + dp[i-1].c3[i-1];
    dp[i].c3[i] = dp[i-1].c3[i-1];
  }
  cout << dp[n-1].c1[n-1] + dp[n-1].c2[n-1] + dp[n-1].c3[n-1];
  return 0;
}
