#include<iostream>
using namespace std;

void f(int n, int from, int to, int cen)
{
  if(n == 0) return;  
  f(n - 1, from, cen, to);
  cout << n << " " << from << " " << to << "\n"; 
  f(n - 1, cen, to, from);
}

int main()
{
  int n;
  cin >> n;
  int from = 1;
  int to = 3; 
  int cen = 2;
  f(n, from, to, cen);  
  return 0;
}
