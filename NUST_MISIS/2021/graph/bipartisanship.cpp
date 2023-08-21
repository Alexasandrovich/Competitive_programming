#include <cstdint>
#include<iostream>
#include<vector>

using namespace std;

void dfs(int v, uint8_t curColorIndex, const vector<vector<int>>& graph, vector<uint8_t>& colors)
{
  colors[v] = curColorIndex;

  for(auto u: graph[v])
  {
    if(colors[u] == 0) // not colores
    {
      dfs(u, 3 - curColorIndex, graph, colors);
    }else if(colors[u] == curColorIndex)
    {
      cout << "No\n";
      exit(0);
    }
  }
}

int main()
{
  int n, m, u, v;
  cin >> n >> m;
  vector<vector<int>> graph(n, vector<int>());
  vector<uint8_t> color(n, 0);
  for(size_t i = 0; i < m; i++)
  {
    cin >> u >> v;  
    graph[u-1].emplace_back(v-1);
  }

  for(size_t i = 0; i < n; i++)
  {
    if(color[i] == 0)
    {
      dfs(i, 1, graph, color);
    }
  }
  cout << "Yes\n";
}
