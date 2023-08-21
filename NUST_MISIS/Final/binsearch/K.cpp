#include <iostream>
#include <cmath>
using namespace std;
int main(){
int a[100000],b[320],m,n,i,j=-1,k,L,R,p,q,z,max=0;
scanf("%d",&n); k=sqrt(n);
for(i=0;i<n;++i){
scanf("%d",&a[i]);;
if(i%k==0){j++;b[j]=i;}
else if(a[i]>a[b[j]])b[j]=i;}
scanf("%d",&m);;
while(m){m--;
scanf("%d%d",&L,&R);L--;R--;p=L/k;q=R/k;
if(p==q){
if(L<=b[p]&&R>=b[p])z=a[b[p]];
else{z=a[L];
for(i=L+1;i<=R;i++)
if(a[i]>z)z=a[i];}}
else{
if(L<=b[p])z=a[b[p]];
else{z=a[L];
for(i=L+1;i<(p+1)*k;i++)
if(a[i]>z)z=a[i];}
for(j=p+1;j<q;j++)
if(a[b[j]]>z)z=a[b[j]];
if(R>=b[q]){if(a[b[q]]>z)z=a[b[q]];}
else for(i=q*k;i<=R;i++)
if(a[i]>z)z=a[i];}
printf("%d ",z);}
return 0;} 
