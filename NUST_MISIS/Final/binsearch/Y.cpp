#include <cstddef>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<iterator>

using namespace std;

vector<size_t> prefix_func(const string& s)
{
  vector<size_t> kmp(s.length());
  for (size_t i=1; i < s.length(); ++i)
  {
    size_t j = kmp[i-1];
    while ((j > 0) && (s[i] != s[j]))
      j = kmp[j-1];

    if(s[i] == s[j])
      ++j;

    kmp[i] = j;
  }
  return move(kmp);
}

int main(){
  string inp;
  string templ;
  int N;
  cin >> inp >> N;
  for(size_t i = 0; i < N; i++)
  {
    cin >> templ;
    string for_search = templ + "#" + inp;
    auto res = prefix_func(for_search);
    if(count(next(res.begin(), templ.length() + 1), res.end(), templ.length()) > 0)
    {
      cout << "Yes\n";
    }else cout << "No\n";
  }
  return 0;
}


