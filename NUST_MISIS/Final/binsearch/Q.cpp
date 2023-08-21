#include<iostream>
#include<vector>
using namespace std;

static size_t res = 0; // connectivity componets size
static int color = 0;

void dfs(int vertex, const vector<vector<int>>& g, vector<int>& used)
{
  used[vertex] = color;
  for(auto to : g[vertex])
  {
    if(used[to] == 0)
      dfs(to, g, used);
  }
}

int main()
{
  size_t n, m;
  cin >> n >> m;
  vector<vector<int>> g(n); // graph
  vector<int> used(n);
  for(size_t edge = 0; edge < m; edge++)
  {
    int from, to;
    cin >> from >> to;
    from--; to--;
    g[from].emplace_back(to);
    g[to].emplace_back(from);
  }
  for(size_t vertex = 0; vertex < n; vertex++)
  {
    if(used[vertex] == 0) {
      ++res;
      color++;
      dfs(vertex, g, used);
    }
  }
  cout << res << endl;
  for(const auto& color : used)
  {
    cout << color << " ";
  }
  return 0;
}



