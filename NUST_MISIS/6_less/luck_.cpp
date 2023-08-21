#include<algorithm>
#include<iostream>
#include<string>
#include<set>
#include<utility>
using namespace std;

int main()
{
  string s; 
  cin >> s;

  if(s.find_first_of("47") == string::npos)
  {
    cout << -1 << "\n";
  }else if(count(s.begin(), s.end(), '4') >= count(s.begin(), s.end(), '7'))
  {
    cout << 4 << "\n";
  }else 
  {
    cout << 7 << "\n";
  }
}
