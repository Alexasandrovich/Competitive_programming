#include <vector>
#include <iostream>
using namespace std;

int main()
{
  long long INF = 1000LL * 1000LL * 1000LL;
  int n = 0; 
  cin >> n;
  vector<int> rc(n); // answer
  vector<int> st; // pseudo-stack
  vector<long long>  a(n+2, -INF);
  for(int i = 1; i < n; i++)
  {
    cin >> a[i];
  }

  // first -INF
  st.emplace_back(0);
  for(int i = 1; i <= n + 1; i++)
  {
    // clear stack
    while(a[st.back()] > a[i])
    {
      rc[st.back()] = i;
      st.pop_back();
    }
    st.emplace_back(i);
  }
  for(const auto& i : rc)
  {
    cout << i << " ";  
  }
  return 0;
}
