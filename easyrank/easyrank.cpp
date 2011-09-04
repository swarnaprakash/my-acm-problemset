//Author swarnaprakash
//Algorithm : Sorting O(n lg n)
#include<algorithm>
#include<utility>
#include<cstdio>
#include<iostream>
#include<string>

#define M 10009
using namespace std;

typedef pair<int,string> psi;

psi a[M];

int main()
{
	int t,i,n;
	
	cin>>t;
	
	string contest;
	int score;
	while(t--)
	{
		cin>>contest;
		cin>>n;
		for(i=0;i<n;++i)
		{
			cin>>a[i].second>>score;
			a[i].first=-score;
		}
			
				
		sort(a,a+n);
		cout<<contest<<" RESULTS\n";
		cout<<"1 "<<a[0].second<<endl;
		int prevrank=1;
		for(i=1;i<n;++i)
		{
			if(a[i].first==a[i-1].first)
				cout<<prevrank;
			else
			{
				cout<<i+1;
				prevrank=i+1;
			}
			cout<<" "<<a[i].second<<endl;
		}
	}
	return 0;
}
