//Author - Swarnaprakash.U
#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

int lcs(string &,string &);

main()
{
	int t;
	
	for(cin>>t;t--;)
	{
		string a,b;
		cin>>a>>b;
		cout<<lcs(a,b)<<endl;
	}
	
	return 0;
}

int lcs(string &a,string &b)
{
	int l,m;
	l=a.size();
	m=b.size();
	int LCS[2][m+1];
	
	int i,j;
	
	LCS[0][0]=LCS[1][0]=0;
	
	for(i=0;i<=m;++i)
		LCS[0][i]=0;
		
	for(i=1;i<=l;++i)
		for(j=1;j<=m;++j)
		{
			if(a[i-1]==b[j-1])
				LCS[i&1][j]=LCS[(i-1)&1][j-1]+1;
			else
				LCS[i&1][j]=max(LCS[(i-1)&1][j],LCS[i&1][j-1]);
		}
	
	
	return LCS[l&1][m];
}