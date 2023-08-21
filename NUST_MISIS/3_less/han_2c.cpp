#include<iostream>
#include<cmath>
using namespace std;

void move(int n, int start, int finish)
{
  if(n > 0)
  {
    int tmp = 6 - start - finish;
    if((start == 1 && finish == 2) ||
       (start == 2 && finish == 3) ||
       (start == 3 && finish == 1)) 
    {
      move(n-1, start, tmp);
      cout << n << " " << start << " " << finish << "\n"; 
      move(n-1, tmp, finish);
    }else
    {
      move(n-1, start, finish);      
      cout << n << " " << start << " " << tmp << "\n"; 
      move(n-1, finish, start);      
      cout << n << " " << tmp << " " << finish << "\n"; 
      move(n-1, start, finish);
    }
  }
}

int main()
{
  int n; 
  cin >> n;
  move(n, 1, 3);
  return 0;
}
