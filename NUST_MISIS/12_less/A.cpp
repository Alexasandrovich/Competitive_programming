#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  vector<int> nums;
  cin >> N;

  int tmp;
  for(int i = 0; i < N; i++)
  {
    cin >> tmp;
    nums.emplace_back(tmp);
  }
  int  ibest = 0;
  int  jbest = 1;
  int imin = 0;
  int iter = 0;
 
  for(int i = 1; i < N; i++)
  {
    if(nums[i-1] < nums[imin])
    {
      imin = i-1;
    }
    if(nums[i] * nums[ibest] >= nums[jbest] * nums[imin])
    {
      jbest = i;
      ibest = imin;
      ++iter;
    }
  }
  
  if(iter == 0 || nums[ibest] == nums[jbest])  
      cout << 0 << " " << 0;
  else cout << ++ibest << " " << ++jbest;
  return 0;
}
