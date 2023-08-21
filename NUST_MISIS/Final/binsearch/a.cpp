#include <iostream>
#include <vector>
using namespace std;

void binSearch(int searchVal, const vector<int>& arr)
{
  int l = -1, r = arr.size();  
  while(r - l > 1)
  {
    int m = (l + r) / 2;
    if(arr[m] < searchVal)
    {
      l = m;  
    }else r = m;
  }
  if(r < arr.size() && arr[r] == searchVal) cout << "YES\n";
  else cout << "NO\n";
}

int main()
{
  int n = 0, k = 0;
  int valueForSearch = 0;
  cin >> n >> k;
  vector<int> arr(n, 0);
  for(size_t i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  for(size_t i = 0; i < k; i++)
  {
    cin >> valueForSearch;
    binSearch(valueForSearch, arr);  
  }
  return 0;
}
