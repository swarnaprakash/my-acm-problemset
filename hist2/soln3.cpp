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

typedef long long int64;
#define two(X) (1<<(X))
#define contain(S,X) (((S)&two(X))!=0)

const int maxn=15;

int n,A[maxn];
int f[two(maxn)][15];
int64 g[two(maxn)][15];

int solve(int set,int p)
{
	if (set==two(n)-1) 
	{
		g[set][p]=1;
		return A[p];
	}
	int &ret=f[set][p];
	if (ret!=-1) return ret;
	ret=0;
	g[set][p]=0;
	for (int i=0;i<n;i++) if (!contain(set,i))
	{
		int t=solve(set+two(i),i)+abs(A[p]-A[i]);
		if (t>ret) ret=t,g[set][p]=0;
		if (t==ret) g[set][p]+=g[set+two(i)][i];
	}
	return ret;
}
int main()
{
	while (scanf("%d",&n)!=-1 && n!=0)
	{
		for (int i=0;i<n;i++) scanf("%d",&A[i]);
		int m=0;
		int64 c=0;
		memset(f,255,sizeof(f));
		for (int i=0;i<n;i++)
		{
			int m2=solve(two(i),i)+A[i];
			int64 c2=g[two(i)][i];
			if (m2>m) m=m2,c=0;
			if (m2==m) c+=c2;
		}
		m+=(n+n);
		cout<<m<<" "<<c<<endl;
	}
	return 0;
}

