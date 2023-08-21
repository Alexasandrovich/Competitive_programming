
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> num;
    int n = 0;
    cin >> n;
    string tmp;
    for(int i = 0; i < n; i++){
      cin >> tmp;
      num.push_back(tmp);
    }
    sort(num.begin(), num.end(), [](string& a, string& b){
      return a + b > b + a;
    });
    
    for(int j = 0; j < n; ++j)
    {
      cout << num[j];
    }
    return 0;    
}


