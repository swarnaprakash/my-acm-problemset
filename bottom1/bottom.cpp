//Author - Swarnaprakash.U
#include<iostream>

using namespace std;

main()
{
	int t;
	int tot,points;
	int i;
	
	bool found;
	
	cin>>t;
	while(t--)
	{
		cin>>tot>>points;
		found=false;
		for(i=0;i<=tot && !found;++i)
		{
			if((i*50 -(tot-i)*25)==points)
			{
				found=true;
				cout<<i<<endl;
			}
		}
		if(!found)
			cout<<"INVALID DATA"<<endl;
	}
	return 0;
}