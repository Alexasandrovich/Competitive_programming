#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<vector<int>> Matrix;

int main()
{
  int n = 0;
  cin >> n;
  Matrix graph(n, vector<int>(n));

  for(size_t i = 0; i < n; i++)
  {
    for(size_t j = 0; j < n; j++)
    {
      cin >> graph[i][j];
    }
  }

  int in, out;
  cin >> in >> out;
  in--; out--;

  queue<int> Q;
  vector<int> d(n, 100000000); // distances from "in" to any vertexes
  d[in] = 0;

  Q.push(in);

  while(!Q.empty())
  {
    int now = Q.front();
    Q.pop();
    for(size_t i = 0; i < n; i++)
    {
      if(graph[now][i] && d[i] > d[now] + 1)  
      {
        d[i] = d[now] + 1;
        Q.push(i);
      }
    }
  }
  if(d[out] < 10000000)
  {
    cout << d[out] << endl;
  }else 
  {
    cout << -1 ;
  }
  return 0;
}
