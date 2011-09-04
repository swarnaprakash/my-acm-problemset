#include<iostream>
#include<cstdio>

main()
{
	int p,s,u,c;
	
	
	cout<<"243"<<endl;
	for(p=-125;p<=125;p+=25)
	{
		
		for(c=0;c<=20;++c)
			cout<<c<<" "<<p<<endl;
	}
	
	for(p=1000;p>=995;--p)
	{
		
		cout<<"20 "<<p<<endl;
		cout<<"20 "<<-p<<endl;
	}
	
	
	return 0;
}