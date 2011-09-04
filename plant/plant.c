//Author - Swarnaprakash.U
#include<stdio.h>
#include<math.h>
#include<assert.h>

int divisors(int);

main()
{
	int t,n;
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n==1)
			puts("0");
		else
			printf("%d\n",divisors(n)-2);
	}
	
	
	return 0;
}

int divisors(int n)
{
	int ans=0;
	int i;
	
	int sq = (int) ( sqrt(n) + 1e-9);
	
	for(i=1;i<=sq;++i)
		if(n%i==0)
			ans+=2;
	
	//be careful with perfect squares
	if(sq*sq==n)
		ans--;
		
	return ans;
}