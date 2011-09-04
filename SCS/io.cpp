#include<iostream>
#include<cstdlib>

using namespace std;

main()
{
	int i;
	int j;
	
	for(i=0;i<88;++i)
	{
		for(j=0;j<100;++j)
			cout<<(char)(rand()%26+'A');
		cout<<endl;
		for(j=0;j<100;++j)
			cout<<(char)(rand()%26+'A');
		cout<<endl;
	}
	return 0;
}