// Author -Swarnaprakash.U
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const bool debug=true;

#define SET(x,v)	memset(x,v,sizeof(x))
#define ALL(x) 		(x).begin() , (x).end()
#define PB 			push_back
#define SZ(x)		((int)((x).size()))
#define TR(i,x) 	for(i=0;i<(x).size();++i)
#define DB(x) 		if(debug) cout << #x << " : " << x <<endl;
#define HELLO		if(debug) puts("hello");
#define LL 			long long
#define INF			100000000
#define M			105


set<string> s;

string contest()
{
	string a(10,'a');
	int i;
	TR(i,a)
		a[i]=rand()%26+'A';
	return a;
}

string team()
{
	string a(10,'a');
	int i;
	TR(i,a)
		a[i]=rand()%26+'a';
	if(s.find(a)!=s.end())
		a=team();
	s.insert(a);
	return a;
}

int main()
{
	int t=0;
	int i;
	//cout<<"100\n";
	//append the following
	
	for(t=0;t<93;++t)
	{
		s.clear();
		cout<<contest()<<endl;
		cout<<100<<endl;
		for(i=0;i<100;++i)
			cout<<team()<<" "<<rand()%(i/2+1)<<endl;
		cout<<endl;
	}
	
		s.clear();
		cout<<contest()<<endl;
		cout<<10000<<endl;
		for(i=0;i<10000;++i)
			cout<<team()<<" "<<9<<endl;
		cout<<endl;
	
		s.clear();
		cout<<contest()<<endl;
		cout<<10000<<endl;
		for(i=0;i<10000;++i)
			cout<<team()<<" "<<i<<endl;
		cout<<endl;
		
		s.clear();
		cout<<contest()<<endl;
		cout<<10000<<endl;
		for(i=0;i<10000;++i)
			cout<<team()<<" "<<rand()<<endl;
		cout<<endl;
	
	return 0;
}
