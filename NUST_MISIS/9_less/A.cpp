
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
  if(b == 0) return a;
  return gcd(b, a % b);
}

vector<int> find_cicles(const vector<int>& perm, const vector<int>& up_perm)
{
  vector<int> perm_cir;
  vector<int> was;
  for(int i = 1; i <= perm.size(); i++)
  {
    int circle_len = 0;
    int k = i;
    int iter = 0;
    if(find(was.begin(), was.end(), perm[i-1]) == was.end())
    {
      was.emplace_back(up_perm[i-1]);
      circle_len++;
      while(up_perm[k-1] != up_perm[i-1] || iter++ == 0)
      {
        k = perm[k-1];
        circle_len++;
        if(find(was.begin(), was.end(), k) == was.end())
        {
          was.emplace_back(k);
        }
      }

    }else
    {
      continue;
    }
    if(circle_len != 0)
      perm_cir.emplace_back(circle_len - 1);
  }
  return perm_cir;
}

int main()
{
  vector<int> perm;
  vector<int> up_perm;
  int N;
  cin >> N;
  int tmp;
  for(int i = 0; i < N; i++)
  {
    cin >> tmp;
    perm.emplace_back(tmp);
    up_perm.emplace_back(i+1);
  }
  ll ans = -1;
  for(auto& i: find_cicles(perm, up_perm))
  {
    if(ans == -1) ans = i;
    else ans = ans * i / gcd(ans, i);
  }
  cout << ans;
  return 0;
}
