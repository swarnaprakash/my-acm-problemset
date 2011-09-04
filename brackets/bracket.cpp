//Author - Swarnaprakash.U
#include<iostream>
#include<cstdio>
#include<cassert>
#include<stack>
#include<string>

using namespace std;

bool check(string &);

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
	
}

bool check(string &symbol)
{
	int i;
	stack<char> stk;
	
	char match[200];
	match[ ')' ] ='(';
	match[ '}' ]='{';
	match[ ']' ]='[';
	
	for(i=0;i<symbol.size();++i)
	{
		if(symbol[i]=='(' || symbol[i]=='{' || symbol[i]=='[')
			stk.push(symbol[i]);
		else
		{
			if(stk.empty())
				return false;
			char c=stk.top();
			stk.pop();
			if(match[symbol[i]]!=c)
				return false;
		}
	}
	
	if(!stk.empty())
		return false;
	else
		return true;
	
}