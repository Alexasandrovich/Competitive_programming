#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
  int n = 0;
  cin >> n;
  vector<string> strings;
  string tmp;
  for(size_t i = 0; i < n ; i++)
  {
    cin >> tmp;  
    strings.emplace_back(tmp);    
  }
  sort(strings.begin(), strings.end());

  for(auto& i: strings)
  {
    cout << i << endl;
  }
  return 0;
}
