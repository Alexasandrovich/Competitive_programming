#include <vector>
#include <iostream>
using namespace std;

static vector<int> ans;

void bfs(const vector<vector<int>>& g, vector<int>& P, vector<int>& used, int vertex, int p = -1)
{
  used[vertex] = 1;
  if(P[vertex] == 0) P[vertex] = p;
  for(const int to : g[vertex])
  {
    if(used[to] == 0)
    {
      bfs(g, P, used, to, vertex);
    }else if(P[vertex] != to)
    {
      cout << "Yes\n";
      ans.emplace_back(to);
      for(int j = vertex; j != to; j = P[j])
      {
        ans.emplace_back(j);
      }
      cout << ans.size() << endl;
      for(int j = 0; j < ans.size(); j++)
      {
        cout << ans[j]+1 << " "; 
      }
      exit(1);
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<int> used(n);
  vector<int> P(n);
  for(int edge = 0; edge < m; edge++)
  {
    int from, to;
    cin >> from >> to;
    from--; to--;
    g[from].emplace_back(to);
    g[to].emplace_back(from);
  }
  for(int vertex = 0; vertex < n; vertex++)
  {
    if(used[vertex] == 0)  
      bfs(g, P, used, vertex);
  }
}
