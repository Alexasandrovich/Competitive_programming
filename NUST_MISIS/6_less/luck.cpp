#include<algorithm>
#include<iostream>
#include<string>
#include<set>
#include<utility>
using namespace std;

struct Item
{
  string v; 
};

bool operator<(const Item& l, const Item& r)
{
  return l.v.size() < r.v.size() || (l.v.size() == r.v.size() && l.v < r.v);  
}

int main()
{  
  int n = 0;
  cin >> n;

  set<Item> s;

  while(n--)
  {
    string x;
    cin >> x;
    string left = "-1", right = "-1";

    Item long_num;
    long_num.v = x;
    auto it = s.lower_bound(long_num);

    if(it != s.end())
    {
      auto tmp = it;
      if(tmp->v == x)
      {
        ++tmp;
      }
      if(tmp != s.end())
      {
        right = tmp->v;
      }
    }
    if(it != s.begin())
    {
      left = prev(it)->v;
    }
    cout << left << ' ' << right << endl;
    s.insert(long_num);
  }
  return 0;

}
