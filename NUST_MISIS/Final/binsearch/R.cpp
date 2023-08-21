#include<iostream>
#include<vector>
#include<utility>
using namespace std;

static size_t conect_comp_size = 0;

void dfs(int vertex, const vector<vector<int>>& g, vector<int>& used)
{
  used[vertex] = 1;
  for(auto to : g[vertex])
  {
    if(used[to] == 0){
      dfs(to, g, used); 
    }else if(used[to] == 2)
    {
      cout << "NO"; // cicle
      exit(0);
    }
  }
  used[vertex] = 2;
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
      conect_comp_size++;
      dfs(vertex, g, used);
    }
  }
  if(conect_comp_size == 1)
  {
    cout << "YES";
  }else cout << "NO";
  return 0;
}


