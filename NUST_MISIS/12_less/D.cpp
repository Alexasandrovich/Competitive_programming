#include<bits/stdc++.h>
using namespace std;
typedef vector<int>::iterator It;

int main()
{
  size_t n = 0;
  cin >> n;
  vector<int> inp(n);
  vector<int> sum(n);
  int i_sum = 0;
  for(size_t i = 0; i < n; i++)
  {
    cin >> inp[i];
    inp[i] = ((inp[i] % 3) + 3) % 3;
    i_sum = 0;
    for(size_t j = 0; j <= i; j++)
    {
      i_sum += inp[j];
    }
    sum[i] = i_sum % 3;
  }

  int max = 0;
  It begin = sum.end();
  It end = sum.end();
  if(sum[0] == 0)
  {
    auto it_0_end = find(sum.end(), sum.begin(), 0);
    max = distance(sum.begin(), it_0_end);
    begin = sum.begin();
    end = it_0_end;
  }

  It it_1_begin = find(sum.end(), sum.begin(), 1);
  It it_1_end = find(sum.end(), sum.begin(), 1);
  if(it_1_begin != sum.end()){
    if(distance(it_1_begin, it_1_end) >= max && !(begin < it_1_begin && distance(it_1_begin, it_1_end) == max))
    {
      max = distance(it_1_begin, it_1_end);
      begin = it_1_begin;
      end = it_1_end;
    }
  }
  It it_2_begin = find(sum.begin(), sum.end(), 2);
  It it_2_end = find(sum.end(), sum.begin(), 2);
  if(it_2_begin != sum.end()){
    if(distance(it_2_begin, it_2_end) >= max && !(begin < it_2_begin && distance(it_2_begin, it_2_end) == max))
    {
      max = distance(it_2_begin, it_2_end);
      begin = it_2_begin;
      end = it_2_end;
    }
  }
  if(max == 0)
  {
    cout << -1;
    return 0;
  }else
  {
    cout << (begin - sum.begin()) + 1 << " " << (end - sum.begin()) + 1;
    return 0;
  }
}
