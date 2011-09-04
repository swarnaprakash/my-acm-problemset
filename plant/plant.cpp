//Author - Swarnaprakash.U
#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int divisors(int);

main()
{
	int t;
	int n;
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n==1)
			cout<<"0"<<endl;
		else
			cout<<divisors(n)-2<<endl;
	}
	return 0;
}

int divisors(int n)
{
	//prime factorise n = p1^a1 * p2^a2 * p3^a3 * ... * pn^an
	// p1 , p2 ,p3 are primes ....
	// number of divisors = (a1+1) * (a2+1) * (a3+1) * ... * (an+1)
	 
	int sq= (int) (sqrt( (double) n) + 1e-9);
	int i;
	
	int ans=1;
	
	
	for(i=2;n>1 && i<=sq;++i)
	{
		int cnt=0;
		while(n%i==0)
		{
			cnt++;
			n/=i;
		}
		ans*=cnt+1;
	}
	
	// there will be atmost one prime factor above sqrt_n .If there is then n will be greater than 1
	if(n>1)
		ans*=2;
		
	return ans;
}
