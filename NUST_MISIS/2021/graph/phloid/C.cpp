#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
  int A, B;
  int W;
};

int main()
{
  int N, M;
  cin >> N >> M;
  vector<Edge> edges(M);
  const long long INF = 1'000'000'000;
  vector<int> dists(N, INF);
  dists[0] = 0;

  for(size_t i = 0; i < M; i++)
  {
    cin >> edges[i].A >> edges[i].B >> edges[i].W; 
  }

  for(int i = 0; i < N-1; i++)
  {
    for(int j = 0; j < M; j++)
    {
      if(dists[edges[j].A] < INF)
      {
        dists[edges[j].B] = min(dists[edges[j].B], dists[edges[j].A] + edges[j].W);
      }
    }
  }

  for(const auto& dist : dists)
  {
    if(dist == INF) cout << 30'000 << " ";
    else cout << dist << " ";
  }
}
