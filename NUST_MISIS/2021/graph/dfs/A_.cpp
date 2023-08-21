#include<iostream>
#include<queue>

using namespace std;

int main() {
  int n,i,j,k,f,s;
  queue<int> q;
  cin>>n;
  int a[n][n],d[n];
  for(i=0;i<n;++i)
  {
    d[i]=1000000000;
    for(j=0;j<n;++j)
        cin>>a[i][j];
  }
  cin>>s>>f;
  s--;f--;
  d[s]=0;
  q.push(s);
  while(!q.empty())
  {
      i=q.front();
      q.pop();
      for(j=0;j<n;++j)
          if(a[i][j]&&d[j]>d[i]+1){
              d[j]=d[i]+1;
              q.push(j);
          }
  }
  if(d[f]<1000000000)
      cout<<d[f];
  else cout<<-1;
  return 0;} 

