#include<algorithm>
#include<iostream>
#include<string>
#include<set>
#include<utility>
using namespace std;

pair<int, int> find_minmax(set<int>& numb, int num)
{
  int min = 0, max = 0;
  auto low = numb.upper_bound(num);
  if(low != numb.end())
  {
    if(low != numb.begin() && *low != num )
      min = *(--low);
    else min = *low;
  }else min = -1;

  auto up = numb.upper_bound(num);
  if(up != numb.end())
  {
    if(up != numb.begin() && *up != num)
      max = *(++up);
    else max = *up;
  }else max = -1;
  return make_pair(min, max);
}

int main()
{
  int n = 1;
  cin >> n;
  set<int> all_num;
  int num;

  for(size_t i = 0; i < n; i++)
  {
    cin >> num;
    auto res = find_minmax(all_num, num);
    cout << get<0>(res) << " " << get<1>(res) << "\n";
    all_num.insert(num);
  }
  return 0;
}

