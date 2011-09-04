//Author - Swarnaprakash.U
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int gcd(int,int);

main()
{
	int t;
	
	char a[20];
	int num,den,hcf,len,i;
	
	scanf("%d",&t);
	
	
	while(t--)
	{
		scanf(" 0.%[0-9]...",a);
		
		len=strlen(a);
		
		num=atoi(a);
		
		den=0;
		for(i=0;i<len;++i)
		{
			den*=10;
			den+=9;
		}
		
		hcf=gcd(num,den);
		num/=hcf;
		den/=hcf;
		
		printf("%d/%d\n",num,den);
		
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