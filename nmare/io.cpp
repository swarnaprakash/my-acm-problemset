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


int main()
{
	int t=0;
	
	cout<<"500\n";
	
	int k,x;
	
	for(k=3;k<=15;++k)
		for(x=-k;x<=k;++x)
			++t,printf("%d %d\n",k,x);
			
	printf("1000 1000\n1000 -1000\n1000 0\n1000 1\n1000 -1\n1000 501\n1000 -337\n");
	t+=7;
	for(;t<500;++t)
	{
		k=rand()%1000+1;
		x=rand()%(2*k)-k;
		printf("%d %d\n",k,x);
	}
	return 0;
}
