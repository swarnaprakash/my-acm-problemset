#include<iostream>
#include<map>

using namespace std;

main()
{
int l,r,ns,nq,i,q;

while(1)
{
cin>>ns>>nq;
if(ns==0 & nq==0)
 break;

map<int,int> p;
map<int,int>::iterator it;

for(i=0;i<ns;++i)
{
 cin>>l>>r;
 p[l]++;
 p[r+1]--;
}

for(i=0;i<nq;++i)
{
 cin>>q;
 int s=0;

 for(it=p.begin();it!=p.end() && it->first<=q;++it)
  s+=it->second;

 if(s%2==0)
  cout<<"NO"<<endl;
 else
  cout<<"YES"<<endl;

}
cout<<endl;
}
return 0;
}

