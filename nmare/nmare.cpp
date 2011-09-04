//Author : Swarnaprakash
// Algorithm : Brute force   O ( k^2)
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	
	cin>>t;
	while(t--)
	{
		int a,b,c,k,x;
		int ans=0;
		cin>>k>>x;
		for(a=1;a<=k;++a)
			for(b=1;b<=k;++b)
			{
				c=k-a-b;
				if(c>=1 && c<=k)
				{
					int d=abs(a-b-x)*abs(b-c);
					ans=max(ans,d);
				}
			}
		cout<<ans<<endl;
	}
	return 0;
}
