#include<algorithm>
#include<iostream>
#include<string>
#include<set>
#include<utility>
using namespace std;

int how_much_room;
string is_stairs;

void solve()
{
  if(is_stairs == string(how_much_room, '0'))
  {
    cout << how_much_room << "\n";
  }else
  {
    cout << max(how_much_room - is_stairs.find("1"), is_stairs.rfind("1") + 1) * 2 << "\n";
  }
}

int main()
{
  int n = 0;
  cin >> n;
  while(n--)
  {
    cin >> how_much_room;
    cin >> is_stairs;
    solve();
  }
}

