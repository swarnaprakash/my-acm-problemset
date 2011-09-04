//Author - Swarnaprakash.U
#include<iostream>
#include<string>

using namespace std;

bool check(string &);

//a slow algorithm O(n^2) but fast enough for the given constraints
//i wrote this for checking tests
// keep replacing  occurences of ()  ,[] ,{} in the sequence by "" .If the sequence is valid you must end up with null string 

main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		string s;
		cin>>s;
		if(check(s))
			cout<<"RIGHT"<<endl;
		else
			cout<<"WRONG"<<endl;
	}
	
	return 0;
}

bool check(string &s)
{
	bool ok=true;
	
	while(ok)
	{
		ok=false;
		unsigned pos;
		
		pos=s.find("()");
		if(pos!=-1)
			s.replace(pos,2,""),ok=true;
			
		pos=s.find("[]");
		if(pos!=-1)
			s.replace(pos,2,""),ok=true;
		
		
		pos=s.find("{}");
		if(pos!=-1)
			s.replace(pos,2,""),ok=true;
		
		
		
	}
	
	if(s.size()==0)
		return true;
	else 
		return false;
}