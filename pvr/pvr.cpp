#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define M 105

bool adj[M][M];
bool visited[M];
bool cycle;
int n;

void dfs(int);

main()
{
	int i;
	int m;
	
	
	while(1)
	{
		cin>>m>>n;
		if(!n)
			break;
			
		memset(adj,0,sizeof(adj));
		
		int x,y;
		
		for(i=0;i<m;++i)
		{
			cin>>x>>y;
	
			--x;
			--y;
			adj[x][y]=true;
			
		}
				
		cycle=false;
		
		for(i=0;i<n &&!cycle;++i)
		{
			memset(visited,0,sizeof(visited));
			dfs(i);
		}
		
		if(cycle)
			cout<<"UNSOLVABLE";
		else
			cout<<"SOLVABLE";
			
		cout<<endl;
	}

	return 0;
}


void dfs(int x)
{
	int i;
	
	if(visited[x])
		cycle=true;
		
	if(cycle)
		return;
	
	visited[x]=true;
	
	for(i=0;i<n;++i)
		if(adj[x][i])
			dfs(i);
			
	visited[x]=false;
}
