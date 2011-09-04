#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>

using namespace std;

#define M                       105
#define SET(x,v)	 	memset(x,v,sizeof(x))
#define ALL(x) 		(x).begin() , (x).end()
#define PB 			push_back
#define TR(i,x) 		for(i=0;i<(x).size();++i)
#define DB(x) 		cout << #x << " : " << x <<endl;
#define LL 			long long
#define INF             1000000000


bool inside(int a,int b,int x1,int y1,int x2,int y2)
{
if(a<x1 || a>x2)
 return false;
if(b<y1 || b>y2)
 return false;
return true;
}



main()
{
int n,q;
int i,j;
int x1[M],y1[M],x2[M],y2[M];

while(1)
{
cin>>n>>q;

if(n==0 && q==0)
 break;

assert(n<=100);
assert(q<=100);

for(i=0;i<n;++i)
{
 cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
 assert(x1[i]<INF);
 assert(x2[i]<INF);
 assert(y1[i]<INF);
 assert(y2[i]<INF);

 assert(x1[i]<=x2[i]);
 assert(y1[i]<=y2[i]);
}
int a,b;
for(i=0;i<q;++i)
{
 cin>>a>>b;
 assert(a<INF);
 assert(b<INF);
 int ans=0;
 for(j=0;j<n;++j)
  if(inside(a,b,x1[j],y1[j],x2[j],y2[j]))
   ++ans;
 cout<<ans<<endl;
}
cout<<endl;

}
return 0;
}
