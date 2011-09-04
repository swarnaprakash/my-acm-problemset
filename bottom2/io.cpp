#include<iostream>
#include<cstdlib>

using namespace std;

main()
{
	int i,j;
	
	for(i=0;i<1<<4;++i)
	{
		cout<<"4"<<endl;
		
		for(j=0;j<4;++j)
		{
			cout<<"A"<<" ";
			if(i&(1<<j))
				cout<<"+"<<endl;
			else
				cout<<"-"<<endl;
		}
	}
	
	for(i=0;i<10;++i)
	{
		cout<<"100"<<endl;
		for(j=0;j<100;++j)
		{
			cout<<(char)(rand()%10+'a')<<" ";
			if(j%2)
				cout<<"+"<<endl;
			else
				cout<<"-"<<endl;
		}
			
		
	}
	
	return 0;
}