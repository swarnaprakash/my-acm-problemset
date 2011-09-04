#include<iostream>
#include<cstdio>
#include<cstdlib>

main()
{
	int t=0;
	
	cout<<"200"<<endl;
	
	int i;
	
	for(i=1;i<=9;++i)
	{
		t+=3;
		if(i!=9)
			cout<<"0."<<i<<"..."<<endl;
		cout<<"0.0"<<i<<"..."<<endl;
		cout<<"0."<<i<<"0..."<<endl;
	}
	--t;
	
	t+=6;
	puts("0.142857...");
	puts("0.076923...");
	puts("0.000000009...");
	puts("0.000000001...");
	puts("0.00000011...");
	puts("0.000000111...");
	
	
	int j,k;
	for(i=3;i<=9;++i)
		for(j=0;j<24;++j)
		{
			++t;
			cout<<"0.";
			for(k=0;k<i;++k)
				cout<<rand()%10;
			cout<<"..."<<endl;
		}
	//cout<<"Tests="<<t<<endl;
	
	
	return 0;
}

