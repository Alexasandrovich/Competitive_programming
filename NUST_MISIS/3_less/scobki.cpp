#include<iostream>
#include<vector>
using namespace std;

int full_size = 0;

void get_right_hooks(vector<char> hooks, int k, int n)
{
  cout << k << " " << n << "\n";  
  if(k < 0 || n < 0)
  {
    return;
  }
  if(k == 0 && n == 0)
  {
    for(auto &i: hooks)
    {
      cout << i;  
    }
    cout << "\n";
  }

  if(k > full_size / 2 && n > full_size / 2)
  {
      return;
  }else
  {
    hooks.push_back(')');
    get_right_hooks(hooks, k--, n--);
    hooks.pop_back();

    hooks.push_back('(');
    get_right_hooks(hooks, k++, n--);
    hooks.pop_back();
    
    hooks.push_back(']');
    get_right_hooks(hooks, k--, n--);
    hooks.pop_back();

    hooks.push_back('[');
    get_right_hooks(hooks, k++, n--);
    hooks.pop_back();

  }
}

int main()
{
  int n;
  cin >> n;
  full_size = n;
  vector<char> hooks;
  get_right_hooks(hooks, 0, n);
  return 0;
}

