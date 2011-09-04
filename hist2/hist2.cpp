// Author -Swarnaprakash.U
#include <vector>
#include <map>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <set>

using namespace std;

void histogram(vector<int>);
int ways(vector<int>);
int fact(int);

int main()
{
	int n;
	int t=0;
	while(1)
	{
		scanf("%d",&n);
		if(!n)
			break;
		assert(n>=2 && n<=15);
		++t;
		vector<int> v(n);
		int i;
		for(i=0;i<n;++i)
		{
			scanf("%d",&v[i]);
			assert(v[i]>=1 && v[i]<=100);
		}
		set<int> tmp(v.begin(),v.end());
		
		assert(tmp.size()==n);
		histogram(v);
	}
	
	assert(t<=50);
	return 0;
}

void histogram(vector<int> v)
{
	int n=v.size();
	map<int,int> per;
	
	int i,j;
	for(i=0;i<1<<(n-1);++i)
	{
		vector<int> wt(n);
		wt[0]=wt[n-1]=1;
		for(j=0;j<n-1;++j)
			if(i&1<<j)
			{
				wt[j]++;
				wt[j+1]--;
			}
			else
			{
				wt[j]--;
				wt[j+1]++;
			}
		int p=0;
		sort(wt.begin(),wt.end());
		sort(v.begin(),v.end());
		
		for(j=0;j<n;++j)
			p+=wt[j]*v[j];
		per[p]+=ways(wt);	
	}
	printf("%d %d\n",(per.rbegin())->first+2*n,(per.rbegin())->second);
}

int ways(vector<int> p)
{
	map<int,int> m;
	int i;
	for(i=0;i<p.size();++i)
		m[p[i]]++;
	int ans=1;
	for(map<int,int>::iterator it=m.begin();it!=m.end();++it)
		ans*=fact(it->second);
	return ans;
}

int fact(int n)
{
	int ans=1;
	int i;
	for(i=2;i<=n;++i)
		ans*=i;
	return ans;
}
