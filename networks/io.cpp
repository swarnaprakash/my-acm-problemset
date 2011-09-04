#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<utility>
#include<algorithm>
#include<cassert>

using namespace std;

main()
{
	cout<<"100 400"<<endl;
	int i;
	
	
	set< pair<int,int> > s;
	for(i=0;i<400;++i)
	{
		int x,y;
		while(1)
		{
			x=rand()%100+1;
			y=rand()%100+1;
			
			if(x==y)
				continue;
			
			if(x<y)
				swap(x,y);
			
			pair<int,int> pi=make_pair(x,y);
			
			if(s.find(pi)!=s.end())
				continue;
				
			s.insert(pi);
			cout<<x<<" "<<y<<endl;
			break;
		}
		
	}
	cout<<"4950"<<endl;
	int c=0;
	int j;
	for(i=1;i<=100;++i)
		for(j=i+1;j<=100;++j)
			++c,cout<<i<<" "<<j<<endl;
			
	assert(c==4950);
	cout<<endl;
	
	int k;
	for(k=0;k<10;++k)
	{
	cout<<"20 15"<<endl;
	s.clear();
	for(i=0;i<15;++i)
	{
		int x,y;
		while(1)
		{
			x=rand()%20+1;
			y=rand()%20+1;
			
			if(x==y)
				continue;
			
			if(x<y)
				swap(x,y);
			
			pair<int,int> pi=make_pair(x,y);
			
			if(s.find(pi)!=s.end())
				continue;
				
			s.insert(pi);
			cout<<x<<" "<<y<<endl;
			break;
		}
		
	}
	cout<<"190"<<endl;
	int c=0;
	int j;
	for(i=1;i<=20;++i)
		for(j=i+1;j<=20;++j)
			++c,cout<<i<<" "<<j<<endl;
			
	assert(c==190);
	cout<<endl;
	}
	
	
	
	
	
	cout<<"0 0"<<endl;
	return 0;
}
