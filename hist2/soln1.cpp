// submission by https://www.spoj.pl/KOPC09/users/anupcshan/ during contest.
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<list>
#include<map>
#include<string>
using namespace std;
#include<assert.h>
#include<stdlib.h>
#include<limits.h>
#define full(v) v.begin(),v.end()
#define FOR(i,v) for(i=0;i<v.size();i++)

typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;

void print(vector<int>& vi)
{
	for(unsigned int i=0; i<vi.size(); i++)
		cerr<<vi[i]<<" ";
	cerr<<endl;
}

int abs(int a)
{
	if(a>=0)
		return a;
	return -a;
}

int dp[16];

void build()
{
	int cur=2, cur2=2, k=3;

	for(int i=2; i<=15; i++)
	{
		if(i%2)
		{
			dp[i]=cur;
			cur2=cur*(i+1);
			cur=(cur*k*(k-1));
			k++;
		}
		else	dp[i]=cur2;
	}
}

int main()
{
	int i, n, t, m;
	vector<int> h;

	build();
	while(1)
	{
		cin>>n;
		if(!n)
			break;
		h.clear();
		for(i=0; i<n; i++)
		{
			cin>>t;
			h.push_back(t);
		}

		sort(h.begin(), h.end());

		m=2*n+h[n-1]+h[(n-1)/2];
		i=0;
		int j=n-1;
		bool begin=false;
		int cur=h[j];
		while(i<=j)
		{
			if(begin)
			{
				m+=cur-h[i];
				cur=h[i];
				i++;
				begin=false;
			}
			else
			{
				m+=h[j]-cur;
				cur=h[j];
				j--;
				begin=true;
			}
		}

		cout<<m<<" "<<dp[n]<<endl;
	}
}
