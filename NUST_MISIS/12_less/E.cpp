#include<vector>
#include<iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> inp(n);
  for(size_t i = 0; i < n; i++)
  {
    cin >> inp[i];
  }

  int ans = inp[0],
	ans_l = 0,
	ans_r = 0,
	sum = 0,
	min_sum = 0,
	min_pos = -1;
  for (int r=0; r<n; ++r) {
	sum += inp[r];
	int cur = sum - min_sum;
	if (cur > ans) {
		ans = cur;
		ans_l = min_pos + 1;
		ans_r = r;
	}

	if (sum < min_sum) {
		min_sum = sum;
		min_pos = r;
	}
  }

  cout << ++ans_l << " " << ++ans_r;
  return 0;
}
