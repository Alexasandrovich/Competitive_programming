#include<iostream>
#include<vector>
#include<utility>
using namespace std;

static size_t conect_comp_size = 0;
vector<pair<int, int>> answer;
vector<int> colored; // black vs white

void dfs(int vertex, const vector<vector<int>>& g, vector<int>& used, int which_color)
{
  used[vertex] = 1;
  colored[which_color] = 1;
  for(auto to : g[vertex])
  {
    if(used[to] == 0){
      dfs(to, g, used, 3 - which_color); 
      int ans_from = vertex + 1;
      int ans_to = to + 1;
      answer.emplace_back(make_pair(ans_from, ans_to));
    }
  }
}

int main()
{
  size_t n, m;
  cin >> n >> m;
  vector<vector<int>> g(n); // graph
  vector<int> used(n);
  colored.assign(n, 0);
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
      dfs(vertex, g, used, 1);
    }
  }
  if(conect_comp_size > 1) cout << "No";
  else
  {
    cout << "Yes\n";
    cout << answer.size() << "\n";
    for(int i =0; i < answer.size(); i++)
    {
      cout << answer[i].first << " " << answer[i].second << "\n";  
    }
  }
  return 0;
}

