#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int my_lower_bound(int x, const vector<int>& a){
    //finds index of first element that >= x
    int l = 0;
    int r = a.size();
    while(l < r){
        int mid = (l+r)/2;
        if (a[mid] < x)
            l = mid + 1;
        else
            r = mid;
    }
    return r < a.size() ? r : -1;
}
 
int my_upper_bound(int x, const vector<int>& a){
    //finds index of first element that > x
    int l = 0;
    int r = a.size();
    while(l < r){
        int mid = (l+r)/2;
        if (a[mid] <= x)
            l = mid + 1;
        else
            r = mid;
    }
    return r < a.size() ? r : -1;
}

int getElemSizeInRangeForArray(int L, int R, const vector<int>& arrForSearch)
{
  int lInd = my_lower_bound(L, arrForSearch);
  int rInd = my_upper_bound(R, arrForSearch);

  if(lInd < 0 && rInd < 0){
    return 0; // outBounds;
  }
  else if(lInd < 0 && rInd >= 0){
    return rInd;
  }
  else if(lInd >= 0 && rInd >= 0){
    return (rInd - lInd);
  }
  else if(lInd >= 0 && rInd < 0)
  {
    return arrForSearch.size() - lInd;
  }
  else if(L <= arrForSearch[0] && R >= arrForSearch.back()){
    return arrForSearch.size();
  }
  return 0.0;
}

int main()
{
  int N = 0, K = 0, L = 0, R = 0;
  cin >> N;
  vector<int> inp(N, 0);
  for(int i = 0; i < N; i++)
  {
    cin >> inp[i];
  }
  sort(inp.begin(), inp.end());
  cin >> K;
  for(int i = 0; i < K; i++)
  {
    cin >> L >> R;
    cout << getElemSizeInRangeForArray(L, R, inp);
  }
  return 0;
}

