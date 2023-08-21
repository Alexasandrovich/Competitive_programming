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
  cin >> inp >> templ;
  string for_search = templ + "#" + inp;
  auto res = prefix_func(for_search);
  cout << count(next(res.begin(), templ.length() + 1), res.end(), templ.length()) << "\n";
  for(size_t i = templ.length() + 1; i < res.size(); i++){
    if(res[i] == templ.length()) cout << i - 2 * templ.length() + 1 << " ";
  }
 
  return 0;
}


