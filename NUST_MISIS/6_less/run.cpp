#include<iostream>
#include<string>
using namespace std;
int main() 
{ 
    string inp;
    cin >> inp;

    int big = -4;
    for(int i = 0; i < inp.size(); i++)
    {
      if(isupper(inp[i]))
      {
        if(i - big > 4 || i - big > 2)
        {
          cout << "NO\n";
          return 0;
        } big = i;
      }      
    }
    if(inp.size() - big <= 4)
    {
      cout << "YES\n";  
    }
    else cout << "NO\n";
    return 0;

    return 0; 
} 
