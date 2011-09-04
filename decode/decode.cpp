//Author - Swarnaprakash.U
#include<cstdio>
#include<iostream>
#include<string>
#include<set>


using namespace std;

main()
{
int t;
int i,j;

cin>>t;

while(t--)
{
string msg;
int n;
string tmp;

cin>>msg;
cin>>n;

set<string> dict;

for(i=0;i<n;++i)
{
 cin>>tmp;
 dict.insert(tmp);
}
int cont[100];

 //cont[i] represents the number of ways of decoding the string from ith char to end
 
int len=msg.size();

cont[len]=1;

for(i=len-1;i>=0;--i)
{
 tmp="";
 cont[i]=0;
 for(j=i;j<len;++j)
 {
  tmp+=msg[j];
  if(dict.find(tmp)!=dict.end())
   cont[i]+=cont[j+1];
 }
}

cout<<cont[0]<<endl;

}
return 0;
}
