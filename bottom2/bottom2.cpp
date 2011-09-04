//Author - Swarnaprakash.U
#include<iostream>
#include<string>
#include<map>
#include<cctype>

using namespace std;

void normalise(string &a)
{
	int i;
	for(i=0;i<a.size();++i)
		if(isupper(a[i]))
			a[i]+=32;
}

main()
{
	int n;
	
	int t=0;
	while(++t)
	{
		cin>>n;
		if(!n)
			break;
		map<string,int> feedback;
		
		string name,vote;
		while(n--)
		{
			cin>>name>>vote;
			normalise(name);
			
			int v= feedback[name];
			if(vote=="+" && v!=1)
				feedback[name]++;
			else if(vote=="-" && v!=-1)
				feedback[name]--;
		}
		
		int plus,minus;
		plus=minus=0;
		
		for(map<string,int>::iterator it=feedback.begin();it!=feedback.end();++it)
		{
			if(it->second==1)
				++plus;
			else if(it->second==-1)
				++minus;
		}
		cout<<"POST#"<<t<<":"<<" +"<<plus<<" -"<<minus<<endl;
	}
	return 0;
}