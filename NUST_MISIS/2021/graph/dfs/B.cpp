#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <optional>

using namespace std;
typedef vector<vector<int>> Matrix;

struct Pos
{
  Pos(int x_, int y_) : x(x_), y(y_){}
  Pos() = default;
  friend Pos operator+(const Pos& l, const Pos& r)
  {
    return Pos(l.x + r.x, l.y + r.y);
  }
  int x = 0; 
  int y = 0; 
};

std::optional<Pos> getMoveIfPossible(const std::vector<vector<int>>& matrix,
		                        std::vector<vector<int>>& coloredMap,
         		                const Pos& ourPos,
                  		        const Pos& move)
{
  optional<Pos> res;
  auto finalPos = move + outPos;
  if(finalPos.x < 0 || finalPos.x > matrix.size() 
     || finalPos.y < 0 || finalPos.y > matrix[0].size())
  {
    if(matrix[finalPos.x][finalPos.y] == 1 &&
       coloredMap[finalPos.x][finalPos.y] == 0)
    {
      res = finalPos;
      coloredMap[finalPos.x][finalPos.y] = 1;
      return res;
    }
  }
  return res;
}


int main()
{  
  int n = 0;
  cin >> n;   
  Pos from, to;

  Matrix graph(n, vector<int>(n));
  Matrix colored(n, vector<int>(n));

  // input processing
  for(size_t i = 0; i < n; i++)
  {
    for(size_t j = 0; j < n; j++)
    {
      char inp;
      cin >> inp;
      if(inp == '@') 
      {
        from = Pos(i, j);       
        graph[i][j] = 1;        
      }else if(inp == 'X')
	  {
 		to = Pos(i, j);
        graph[i][j] = 1;        
 	  }else if(inp == '.')
      { 
        graph[i][j] = 1;
      }else graph[i][j] = 0;
    }
  }

  // find possibly way 
  queue<Pos> Q;
  Matrix dists(n, vector<int>(n, 100000000));
  dists[from.x][from.y] = 0;
  Q.push(from);
  array<Pos, 4> movings = {Pos(0, 1), Pos(0, -1), Pos(-1, 0), Pos(1, 0) };
  colored[from.x][from.y] = 1;

  while(!Q.empty())
  {
    auto nowPos = Q.front();
    Q.pop();
    for(size_t moveIndex = 0; moveIndex < movings.size(); moveIndex++)
    {
      auto possibleMove = getMoveIfPossible(graph, colored, nowPos, movings[moveIndex]);
      if(possibleMove.hasValue())
      {
        if(dists[possibleMove.x][possibleMove.y] > dists[nowPos.x][nowPos.y] + 1) 
        {
          dists[possibleMove.x][possibleMove.y] = dists[nowPos.x][nowPos.y];
          Q.push(possibleMove);
        }
      }
    } 
  }
  if(dists[to.x][to.y] < 100000000)
  {
    printAnswer(from, to, graph);  
  }

  return 0;
}
