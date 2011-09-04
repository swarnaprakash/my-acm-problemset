#include<stdio.h>
#include<iostream>

using namespace std;

int reverse(int);

//Time Limit Exceeded

int main()
{
	int i,r;
	for(i=1;i<=100000000;++i)
	{
		r=reverse(i);
		if(i==r)
			printf("%d\n",i);
	}
	return 0;
}

int reverse(int n)
{
	int r=0;
	while(n>0)
	{
		r*=10;
		r+=n%10;
		n/=10;
	}
	return r;
}
