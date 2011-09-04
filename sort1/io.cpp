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
	
	student()
	{
	}
	
	student(int a,int b,int c,int d,int e,int f)
	{
		age=a;
		m[0]=b;
		m[1]=c;
		m[2]=d;
		m[3]=e;
		m[4]=f;
		
		total=b+c+d+e+f;
		
		string tmp(20,'a');
		int i;
		for(i=0;i<20;++i)
			tmp[i]=rand()%26+'a';
		s=tmp;
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
	int t=0;
	
	vector< student > s;
	
	int i;
	
	for(i=0;i<5;++i)
		s.push_back( student(19,99,99,99,99,99) );
		
	cout<<"200"<<endl;
	
	vector<int> v(5);
	for(i=0;i<5;++i)
		v[i]=i;
		
	
	
	do
	{
		++t;
		cout<<"5"<<endl;
		for(i=0;i<5;++i)
			s[v[i]].print();
	}while(next_permutation(v.begin(),v.end()));
	
	
	
	for(i=0;i<95;++i)
	{
		s.push_back( student(rand()%10+10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10) );
		v.push_back(i+5);
	}
		
	int j;
	student s1,s2;
	s1=student(15,1,1,1,1,1);
	s2=student(15,1,1,1,1,2);
	
	t+=4;
	cout<<"1"<<endl;
	s1.print();
	
	cout<<"2"<<endl;
	s2.print();
	s2.print();
	
	cout<<"2"<<endl;
	s1.print();
	s2.print();
	
	cout<<"2"<<endl;
	s2.print();
	s1.print();
	
	
	for(;t<200;++t)
	{
		cout<<"100"<<endl;
		int k=rand()%1000+1;
		
		for(j=0;j<k;++j)
			next_permutation(v.begin(),v.end());
		for(j=0;j<100;++j)
			s[v[j]].print();
		
	}
	
	
	
	
	
	return 0;
}
