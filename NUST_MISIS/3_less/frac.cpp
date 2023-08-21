#include<iostream>
using namespace std;

void f(int N, int& x, int& y)
{
  if(N == 0)
  {
    return;
  }
  int tmp_y = -y, tmp_x = -x;
  x = -tmp_y - tmp_x;
  y = tmp_x - tmp_y; 
  f(N-1, x, y);  
}

int main()
{
  int N = 0;
  cin >> N;
  int x = 0, y = 1;
  f(N-1, x, y);
  cout << x << " " << y;
  return 0;
}

