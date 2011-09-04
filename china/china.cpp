//Author - Swarnaprakash.U
#include<cstdio>
#include<iostream>
#include<cassert>
#include<string>
#include<algorithm>

using namespace std;

#define M 200


string tree;
int p;
int get();

main()
{
int t;


cin>>t;
while(t--)
{
cin>>tree;
p=0;
cout<<get()<<endl;

assert(p==tree.size());
}


return 0;
}

//The height of a tree is the depth of its furthest leaf.
// get the height of the tree
int get()
{
 char c=tree[p++];

 if(c=='0')
  return 1;

 if(c=='1')
  return (1+get());	// get the height of the subtree with first child as root

 if(c=='2')
  {
   int a=1+get();  // get the height of the subtree with first child as root
   int b=1+get();  // get the height of the subtree with second child as root	
   return max(a,b); //return maximum height
  }

  //if the input is valid you should never reach here !!
  assert(0);
}
