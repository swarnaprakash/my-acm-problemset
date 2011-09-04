#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

main()
{
	int i;
	int j;
	
	cout<<"100"<<endl;
	
	for(j=0;j<12000;++j)
		putchar((char)(rand()%26+'A'));
	cout<<endl;
	for(j=0;j<12000;++j)
		putchar((char)(rand()%26+'A'));
	cout<<endl;
	
	
	/*
	for(i=0;i<87;++i)
	{
		for(j=0;j<20;++j)
			cout<<(char)(rand()%26+'A');
		cout<<endl;
		for(j=0;j<20;++j)
			cout<<(char)(rand()%26+'A');
		cout<<endl;
	}
	*/
	return 0;
}