#include <bits/stdc++.h>
using namespace std;
typedef vector<int>::iterator It;

void next_perm(It begin, It end)
{
  if(is_sorted(begin, end, greater<int>()))
  {
    reverse(begin, end);
    return;
  }
  It r = prev(end);
  It l = prev(end, 2);
  while(*l > *r)
  {
    --l;
    --r;
  }
  It r_swap = prev(end);
  It min_r = prev(end);
  bool is_bigger_find = false;
  while(l < min_r)
  {
    if(*min_r > *l && !is_bigger_find) { r_swap = min_r; is_bigger_find = true; }
    if(*min_r < *r_swap && *min_r > *l) r_swap = min_r;
    --min_r;
  }
  iter_swap(l, r_swap);
  sort(next(l), end);
}

int main()
{
  vector<int> v;
  int N;
  cin >> N;
  int tmp;
  for(int i = 0; i < N; i++)
  {
    cin >> tmp;
    v.emplace_back(tmp);
  }
  next_perm(v.begin(), v.end());
  for (int i = 0; i < N; i++)
  {
    cout << v[i] << " ";
  }
  return 0;
}
