// Author -Swarnaprakash.U
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cassert>

using namespace std;
int perimeter(vector<int>);
int ways(int);
int fact(int);

int main()
{
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(!n)
			break;
		vector<int> v(n);
		int i;
		for(i=0;i<n;++i)
			scanf("%d",&v[i]);
		printf("%d %d\n",perimeter(v),ways((int)v.size()));
	}
	return 0;
}

int perimeter(vector<int> v)
{
	sort(v.begin(),v.end());
	int lo=0;
	int hi=v.size()-1;
	int ans=v[hi];
	
	int now;
	int prev=v[hi];
	--hi;
	bool f=true;
	while(lo<=hi)
	{
		if(f)
		{
			now=v[lo];
			++lo;
		}
		else
		{
			now=v[hi];
			--hi;
		}
		f=!f;
		ans+=abs(now-prev);
		prev=now;
	}
	ans+=prev;
	
	return ans+=2*v.size();
}

int ways(int n)
{
	if(n%2)
		return fact(n/2)*fact(n/2+1);
	else
		return n*fact(n/2)*fact(n/2-1);
}

int fact(int n)
{
	int ans=1;
	int i;
	for(i=2;i<=n;++i)
		ans*=i;
	return ans;
}
