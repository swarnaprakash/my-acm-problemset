//Author - Swarnaprakash.U
#include<cstdio>
#include<iostream>
#include<cassert>

using namespace std;

#define M 105
#define INF 1000000000



main()
{
int n,i,c;
int arr[M];

while(1)
{
 cin>>n;
 if(!n)
  break;

 assert(n<=100);

 for(i=0;i<n;++i)
 {
  cin>>arr[i];
  assert(arr[i]<=INF);
 }

 cin>>c;

 assert(c<=INF);

 int lo=1;
 int hi=INF+1;
 int mid;

 while(lo<hi)
 {
  mid=lo+(hi-lo)/2;

  int tmp=0;
  for(i=0;i<n;++i)
   tmp+=mid/arr[i];

  if(tmp>=c)
   hi=mid;	// mid satifies the condition . so mid can also be the answer
  else
   lo=mid+1; // mid doesnt satisfy the condition ,so we can safely set lo to mid+1
 }
 assert(lo<=INF);
 cout<<lo<<endl;

}
return 0;
}
