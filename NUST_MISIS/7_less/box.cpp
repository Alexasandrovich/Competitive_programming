#include<bits/stdc++.h>
using namespace std;

struct box
{
  int num;
  int w;
  int m;
};

bool is_sorted_boxes(vector<box>& boxes)
{
  int all_mass = 0;
  for(int i = 0; i < boxes.size(); i++)
  {
    all_mass += boxes[i].m;
  }

  for(int i = 0; i < boxes.size(); i++)
  {
    all_mass -= boxes[i].m;
    if(boxes[i].w < all_mass)
    {
      return false;
    }
  }
  return true;
}

int main()
{
  vector<box> boxes;
  size_t n = 0;
  cin >> n;
  int w, m;
  for(size_t i = 1; i <= n; i++)
  {
    cin >> w >> m;
    boxes.push_back({i, w, m});
  }
  sort(boxes.begin(), boxes.end(), [](auto &a, auto &b) {
       return a.w + a.m > b.w + b.m;
  });

  if(is_sorted_boxes(boxes)){
    for(auto& i:boxes)
    {
      cout << i.num << "\n";
    }
    return 0;
  }
  else cout << -1 << "\n";
  return 0;
}

