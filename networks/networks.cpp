#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define M 109

bool p[M][M];

main()
{
	int n,m;
	int i,j,k;
	
	while(1)
	{
		cin>>n>>m;
		if(!n && !m)
			break;
		
		memset(p,0,sizeof(p));
		
		for(i=0;i<=n;++i)
			p[i][i]=true;
			
			
		
		int a,b;
		
		for(i=0;i<m;++i)
		{
			cin>>a>>b;
			p[a][b]=p[b][a]=true;
		}
		
		// compute transitive hull using floyd-warshall
		
		for(k=1;k<=n;++k)
			for(i=1;i<=n;++i)
				for(j=1;j<=n;++j)
					p[i][j] =p[i][j] || (p[i][k] && p[k][j]);
					
		int q;
		cin>>q;
		
		
		for(i=0;i<q;++i)
		{
			cin>>a>>b;
			if(p[a][b])
				cout<<"YES";
			else
				cout<<"NO";
			cout<<endl;
			
		}
		
		cout<<endl;
	}
	return 0;
}