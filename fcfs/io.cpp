#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
	int i,j;
	
	puts("10000");
	for(i=0;i<10000;++i)
	{
		if(i)
			putchar(' ');
		printf("%d",1);
	}
	puts("");
	
	puts("10000");
	for(i=0;i<10000;++i)
	{
		if(i)
			putchar(' ');
		printf("%d",2000000000);
	}
	puts("");
	
	puts("10000");
	for(i=0;i<10000;++i)
	{
		if(i)
			putchar(' ');
		printf("%d",i+1);
	}
	puts("");
	
	puts("10000");
	for(i=0;i<10000;++i)
	{
		if(i)
			putchar(' ');
		printf("%d",2000000000-i);
	}
	puts("");
	
	puts("10000");
	for(i=0;i<10000;++i)
	{
		if(i)
			putchar(' ');
		printf("%d",rand()+1);
	}
	puts("");
	
	puts("1\n1");
	puts("1\n2");
	puts("1\n2000000000");
	
	puts("2\n1 1");
	puts("2\n2000000000 2000000000");
	puts("2\n1 2");
	puts("2\n2 1");
	puts("2\n1 2000000000");
	puts("2\n2000000000 1");
	
	puts("3\n1 893 30843848");
	puts("3\n239478 340984804 834");
	puts("5\n398 89323 2328 239 2389");
	
	
	for(j=0;j<30;++j)
	{
		puts("5");
		for(i=0;i<5;++i)
		{
			if(i)
				putchar(' ');
			printf("%d",rand()%5+1);
		}
		puts("");
	}
	
	puts("0");
	return 0;
}
