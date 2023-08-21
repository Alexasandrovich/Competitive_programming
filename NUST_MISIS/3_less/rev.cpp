#include<iostream>
#include<string>

using namespace std;
void rev(int i)
{
  int num;
  cin >> num;
  i--;
  if(i > 0)
  {
    rev(i);
  }
  cout << num << " ";
}

int main()
{
  int size_inp;
  cin >> size_inp;
  rev(size_inp);
  return 0;
}
