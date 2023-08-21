#include <vector>
#include <iostream>
using namespace std;

void dfs(const vector<vector<int>>& g, int vert, vector<int>& color, int cur_color)
{
  color[vert] = cur_color;
  for(const auto& to : g[vert])
  {
    if(color[to] == 0) // not colored
      dfs(g, to, color, 3 - cur_color);
    else
      if(color[to] == cur_color){
        cout << "No";
        exit(1);
      }
  }
}

int main()
{
  size_t n = 0;
  size_t m = 0;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<int> color(n);
  int res = 0;
  for(size_t i = 0; i < m; i++)
  {
    int from = -1, to = -1;
    cin >> from >> to;
    from--;
    to--;
    g[from].emplace_back(to);
    g[to].emplace_back(from);
  }

  for(size_t i = 0; i < n; i++) 
  {
    if(color[i] == 0)  
      dfs(g, i, color, 1); // 1 - color (1, 2)
  }
  cout << "Yes";
  return 0;
}
