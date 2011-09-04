// Author : Santhana Krishnan
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<iostream>
#include<vector>
#include<map>

#define LL long long
#define UI unsigned int
#define ULL unsigned long long
#define N 55
#define M 101
#define PB push_back
using namespace std;



int main()
{
	int tc,n,i;
	long long arr[70];
	i=1;arr[0]=1;
	long long a=1;
	for(i=1;;++i)
	{
		a*=5;
		if(a < 0)
			break;
		arr[i]=a;
	}
	int mx=i;
	
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d",&n);
		long long ans=0;
		for(i=0;i<mx-1;++i)
			if(n & (1<<i) )
			{
				ans+=arr[i+1];
			}
			
		cout<<ans<<endl;
	}
	return 0;
}
