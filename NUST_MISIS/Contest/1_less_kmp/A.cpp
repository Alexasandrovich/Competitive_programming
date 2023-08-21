#include<vector>
#include<string>
#include<iostream>
#include<iterator>
#include <sstream>

using namespace std;

vector<size_t> z_func(const string& s)
{
  size_t l = 0;
  size_t r = 0;
  vector<size_t> z(s.length());
  for(size_t i = 1; i < s.length(); i++)
  {
    if(i <= r && i >= l)
    {
      z[i] = min(z[i - l], r - i + 1);
    }
    while(i + z[i] < s.length() && s[z[i]] == s[i + z[i]])
    {
      z[i]++;
    }

    if(i + z[i] - 1 > r)
    {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return move(z);
}

int main(){
  size_t inp_size;
  cin >> inp_size;
  vector<size_t> kmp;
  vector<int> str(inp_size, 0);
  vector<size_t> z;
  while(inp_size--)
  {
    size_t tmp = 0;
    cin >> tmp;
    kmp.emplace_back(tmp);
  }
  int cnt = 0;
  for(size_t i = 0; i < kmp.size(); i++)
  {
    if(kmp[i] == 0)
    {
      str[i] = cnt++;
    }
    else
    {
      str[i] = str[kmp[i] - 1];
    }
  }

  std::stringstream result;
  std::copy(str.begin(), str.end(), std::ostream_iterator<int>(result, ""));
  for(const size_t i : z_func(result.str()))
  {
    cout << i << " ";
  }

  return 0;
}


