// submission by https://www.spoj.pl/KOPC09/users/acrush/ during contest
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


int n,m;
int x,y;

int main()
{
//	freopen("input.txt","r",stdin);
	while (scanf("%d%d",&n,&m)!=-1 && n!=0)
	{
		x=y=0;
		int dx=1,dy=1;
		int R=0;
		while (1)
		{
			int wx=(dx>0)?(n-x):(x);
			int wy=(dy>0)?(m-y):(y);
			int w=min(wx,wy);
			x+=dx*w;
			y+=dy*w;
			if ((x==0 || x==n) && (y==0 || y==m))
				break;
			R++;
			if (x==0 || x==n)
				dx=-dx;
			else
				dy=-dy;
		}
		printf("%d\n",R*4);
	}
	return 0;
}

