#include<bits/stdc++.h>
using namespace std;

struct gnome
{
  int num;
  int for_sleep;
  int sleeping;
};

bool is_sorted_gnomes(vector<gnome>& g)
{
  int free = 0;  
  for(int i = 0; i < g.size(); i++)
  {
    if(i == 0) free += g[i].sleeping;
    else free -= g[i].for_sleep;
    if(free <= 0) return false;
    
    if(i > 0) free += g[i].sleeping;
  }
  return true;
}

int main()
{
  vector<gnome> gnomes;
  vector<int> for_sleeps;
  size_t n = 0;
  cin >> n;
  int for_sleep, sleeping;
  for(size_t i = 1; i <= n; i++)
  {
    cin >> for_sleep;
    for_sleeps.emplace_back(for_sleep);
  }
  for(size_t i = 1; i <= n; i++)
  {
    cin >> sleeping;
    gnomes.push_back({i, for_sleeps[i-1], sleeping});
  }


  sort(gnomes.begin(), gnomes.end(), [](gnome &a, gnome &b) {
       return a.sleeping + a.for_sleep > b.sleeping - b.for_sleep;
  });

  if(is_sorted_gnomes(gnomes)){
    for(auto& i:gnomes)
    {
      cout << i.num << "\n";
    }
    return 0;
  }
  else cout << -1 << "\n";
  return 0;
}


