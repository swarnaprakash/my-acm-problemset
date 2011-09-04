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
#include <cctype>
#include <cassert>

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
#define INF			0x3f3f3f3f
#define M			100005

int a[M];

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
		
	int q;
	int x,y;
	char c;
	scanf("%d ",&q);
	while(q--)
	{
		c=getchar();
		scanf("%d %d ",&x,&y);
	
		if(c=='U')
			a[x]=y;
		else
		{
			int mp=x;
			for(i=x+1;i<=y;++i)
			{
				if(a[i]>a[mp])
					mp=i;
			}
			int m2=-INF;
			for(i=x;i<=y;++i)
				if(i!=mp)
					m2=max(m2,a[i]);
					
			printf("%d\n",a[mp]+m2);
		}
	}
	return 0;
}
