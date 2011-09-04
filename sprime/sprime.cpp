//Author : swarnaprakash
// Algorithm : sieve of eratosthenes


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

#define N 10000000

using namespace std;

bool prime[N+5];

void sieve(int n)
{
	int i,j,sq;

	sq=(int)(sqrt( (double) n)+1);
	
	prime[0]=prime[1]=false;
	prime[2]=true;
	
	for(i=3;i<n;++i)
		prime[i]=(i&1);

	for(i=3;i<=sq;i+=2)
		if(prime[i])
			for(j=i*i;j<n;j+=i)
				prime[j]=false;

}

int main()
{
	int i;
	sieve(N);
	int c=0;
	for(i=0;i<=N;++i)
		if(prime[i])
		{
			++c;
			if(prime[c])
				printf("%d\n",i);
		}
	return 0;
}