#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define M 109

bool p[M][M];
bool visited[M];

int n,m;
void dfs(int);

main()
{
	
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
		
		
		int q;
		cin>>q;
		
		
		for(i=0;i<q;++i)
		{
			cin>>a>>b;
			memset(visited,0,sizeof(visited));
			dfs(a);
			if(visited[b])
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
		
		cout<<endl;
	}
	return 0;
}

void dfs(int x)
{
	if(visited[x])
		return;
		
	visited[x]=true;
	
	int i;
	for(i=1;i<=n;++i)
		if(p[x][i])
			dfs(i);
}