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
#define M			105

int main()
{
	int m,n;
	int t=0;
	while(1)
	{
		scanf("%d %d",&m,&n);
		if(!m)
			break;
		++t;	
		if(m==n)
		{
			puts("0");
			continue;
		}
		
		assert(m>=2 && m<=100000);
		assert(n>=2 && n<=100000);
		if(m<n)
			swap(m,n);
		
		int cx,cy,nx,ny;
		cx=cy=n;
		int cnt=0;
		bool right=true;
		bool up=false;
		//n*m grid
		while(1)
		{
			if(cx==0 && cy==0)
				break;
			if(cx==0 && cy==n)
				break;
			if(cx==m && cy==0)
				break;
			if(cx==m && cy==n)
				break;
			
			++cnt;
			
			if(!up && right)
			{
				if(cx+cy<=m)
				{
					nx=cx+cy;
					ny=0;
					up=true;
				}
				else
				{
					nx=m;
					ny=cx+cy-m;
					right=false;
				}
			}
			else if(up && !right)
			{
				if(cx+cy<=n)
				{
					nx=0;
					ny=cx+cy;
					right=true;
				}
				else
				{
					nx=cx+cy-n;
					ny=n;
					up=false;
				}
			}
			else if(up && right)
			{
				if(cy-cx+m<=n)
				{
					nx=m;
					ny=cy-cx+m;
					right=false;
				}
				else
				{
					nx=cx-cy+n;
					ny=n;
					up=false;
				}
			}
			else
			{
				if(cy-cx>=0)
				{
					nx=0;
					ny=cy-cx;
					right=true;
				}
				else
				{
					nx=cx-cy;
					ny=0;
					up=true;
				}
			}
			cx=nx;
			cy=ny;
		}
		printf("%d\n",cnt*4);
	}
	assert(t<=300);
	return 0;
}
