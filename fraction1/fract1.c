//Author - Swarnaprakash.U
#include<stdio.h>

int gcd(int,int);

main()
{
	int t,p,q,hcf;
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d/%d",&p,&q);
		hcf=gcd(p,q);
		
		
		q/=hcf;
		
		while(q%2==0)
			q/=2;
		while(q%5==0)
			q/=5;
			
		if(q>1)
			puts("NONTERMINATING");
		else
			puts("TERMINATING");
	}
	return 0;
}

int gcd(int a,int b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}