#include<cstdlib>
#include<iostream>

using namespace std;

main()
{
	int i;
	
	for(i=0;i<48;++i)
	{
		int x,y,z;
		x=rand()%100-50;
		y=rand()%100-50;
		z=rand()%100-50;
		cout<<x<<" "<<y<<" "<<z<<" ";
		x+=rand()%100+1;
		y+=rand()%100+1;
		z+=rand()%100+1;
		cout<<x<<" "<<y<<" "<<z<<endl;
		
	}
	return 0;
}