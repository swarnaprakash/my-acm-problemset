#include<stdio.h>

#define M 105

//Solution using Disjoint Set ADT 
int parent[M];
int rank[M];

void createset(int);
void setunion(int,int);
int findset(int);
///////////////////////////////

main()
{
	int n,m,q;
	int i,a,b;
	
	while(1)
	{
		scanf("%d %d",&n,&m);
		if(!n && !m)
			break;
			
		for(i=1;i<=n;++i)
			createset(i);
			
		for(i=0;i<m;++i)
		{
			scanf("%d %d",&a,&b);
			setunion(a,b);
		}
		
		scanf("%d",&q);
		for(i=0;i<q;++i)
		{
			scanf("%d %d",&a,&b);
			if(findset(a)==findset(b))
				puts("YES");
			else
				puts("NO");
		}
		puts("");
	}
	return 0;
}

void createset(int x)
{
	parent[x]=x;
	rank[x]=0;
}

void setunion(int x,int y)
{
	int px,py;
	px=findset(x);
	py=findset(y);
	
	if(px==py)
		return;
	
	if(rank[px]>rank[py])
		parent[py]=px;
	else
		parent[px]=py;
		
	if(rank[px]==rank[py])
		rank[py]++;
}

int findset(int x)
{
	if(x==parent[x])
		return x;
	return parent[x]=findset(parent[x]);
	
}
