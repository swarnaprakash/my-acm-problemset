#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

main()
{
	cout<<"100"<<endl;
	int t=0;
	unsigned n;
	
	for(n=1;n<=20;++n)
		cout<<n<<endl;
		
	t+=20;
	n=16;
	
	for(;n<2000000000;n*=2)
	{
		t+=2;
		cout<<(2*n-1)<<endl;
		cout<<(n+1)<<endl;
	}
	
	++t;
	cout<<(n-1)<<endl;
	
	t+=4;
	cout<<"999999883"<<endl;
	cout<<"999999893"<<endl;
	cout<<"999999929"<<endl;
	cout<<"999999937"<<endl;
	
	for(;t<100;++t)
	{
		cout<<(rand()%100+21)<<endl;
	}
	
	
	
	
	return 0;
}