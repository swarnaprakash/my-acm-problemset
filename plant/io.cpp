#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

main()
{
	int i;
	cout<<"49"<<endl;
	
	for(i=1;i<=25;++i)
		cout<<i<<endl;
	
	int a=2*3*5*7*11*13*17*19*23;
	
	cout<<a+1<<endl;
	cout<<a-1<<endl;
	
	cout<<"2147483647"<<endl;
	cout<<"2147483647"<<endl;
	
	a=46340;
	a*=a;
	cout<<a<<endl;
	cout<<"1944810000"<<endl;
	
	
	for(i=0;i<18;++i)
		cout<<rand()<<endl;
	
	return 0;
}
