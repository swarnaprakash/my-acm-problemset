#include<iostream>
#include<algorithm>

using namespace std;

#define M 105

main()
{
int n,a[M];
int i,j,tmp,lis,best[M];

while(1)
{
cin>>n;
if(n==0)
 break;

 for(i=0;i<n;++i)
  cin>>a[i];

 lis=1;

 for(i=n-1;i>=0;--i)
 {
  tmp=0;
  for(j=i+1;j<n;++j)
  {
   if(a[j]<a[i])
    continue;
   tmp=max(tmp,best[j]);
  }

  best[i]=tmp+1;
  lis=max(lis,best[i]);
 }

 cout<<(n-lis)<<endl;
}
}
