#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> mas = {3, 1, 2, 1 ,1 , 132, 1,2, 2,3,5,2,3,5,1,6,1,7};

void quickSort(int left, int right) {
  int i = left, j = right;
  int mid = mas[left + rand() % (right - left)];
  while (i <= j) {
    while (mas[i] < mid)
      i++;
    while (mas[j] > mid)
      j--;
    if (i <= j) {
      swap(mas[i], mas[j]);
      i++;
      j--;
    }
  };

  if (left < j)
    quickSort(left, j);
  if (i < right)
    quickSort(i, right);
}

int main()
{
  int n = 0;
//  cin >> n;
//  mas.reserve(n);
//  int tmp = 0;
//  for(size_t i = 0; i < n; i++)
//  {
//    cin >> tmp;
//    mas[i] = tmp;
//  }
  quickSort(0, mas.size()-1);
  for(auto &i :mas)
  {
    cout << i << " ";
  }
}
