//Author - Swarnaprakash.U
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct student
{
	string s;
	int age;
	int m[5];
	int total;
	
	void read()
	{
		cin>>s;
		cin>>age;
		int i;
		total=0;
		for(i=0;i<5;++i)
			cin>>m[i],total+=m[i];
	}
		
	void print()
	{
		cout<<s<<endl<<age<<endl;
		int i;
		for(i=0;i<5;++i)
		{
			if(i!=0)
				cout<<" ";
			cout<<m[i];
		}
		cout<<endl;
	}
};

bool operator<(student x,student y)
{
	return x.total<y.total;
}


main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		student s[n];
		int i;
		for(i=0;i<n;++i)
			s[i].read();
			
		stable_sort(s,s+n);
		for(i=0;i<n;++i)
			s[i].print();
	}
}