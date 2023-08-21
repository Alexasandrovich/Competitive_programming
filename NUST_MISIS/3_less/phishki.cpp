#include<iostream>
#include<vector>
using namespace std;

vector<int> res;

int move(int pos, int add, bool remove = false)
{
  if(pos > 1)
  {
    move(pos - 1, 1);
    res.emplace_back(add * pos);
    if(remove) move(pos - 1, -1);
  }else res.emplace_back(add);
}

int main()
{
  size_t n;
  cin >> n;
  for(size_t i = n; i >= 1; i -= 2)
  {
    move(i, 1, false);
  }
  for(auto &i: res)
  {
    cout << i << " ";
  }
  return 0;
}

