#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

main()
{
	int t=0;
	cout<<"161"<<endl;
	
	int i,j;
	
	t=25;
	for(i=1;i<=5;++i)
		for(j=1;j<=5;++j)
			cout<<i<<'/'<<j<<endl;
			
	
	t+=4;
	puts("1/999999883");
	puts("1/999999893");
	puts("1/999999929");
	puts("1/999999937");
	
	
	for(i=3;i<=30;++i)
		++t,cout<<1<<'/'<<(1<<i)<<endl;
	
	++t;
	cout<<rand()+1<<'/'<<"1"<<endl;
	
	int p,q;
	int x,y;
	for(i=0;i<30;++i)
	{
		t+=3;
		
		q=rand()%1000+1;
		p=q*(rand()%1000+1);
		cout<<p<<'/'<<q<<endl;
		
		p=rand()%1000+1;
		q=rand()%1000+1;
		cout<<p<<'/'<<q<<endl;
		
		x=rand()%5+1;
		y=rand()%5+1;
		
		q=1;
		while(x--)
			q*=2;
		while(y--)
			q*=5;
		
		int tmp=2147483647/q;
		tmp=rand()%tmp+1;
		p=tmp;
		q=q*tmp;
		cout<<p<<'/'<<q<<endl;
		
		
	}
	
	p=1;
	q=1;
	
	for(i=1;i<=13;++i)
	{
		++t;
		q*=5;
		cout<<p<<'/'<<q<<endl;
	}
	

	//cout<<"tests="<<t<<endl;
	
	return 0;
}
