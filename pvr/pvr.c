#include<stdio.h>
#include<string.h>

#define M 105

int p[M][M];
main()
{
	int m,n;
	int i,j,k;
	int a,b;
	int nocycle;
	
	while(1)
	{
		scanf("%d %d",&m,&n);
		
		if( !m && !n)
			break;
		
		memset(p,0,sizeof(p));
		
		for(i=1;i<=n;++i)
			p[i][i]=1;
		
		for(i=0;i<m;++i)
		{
			scanf("%d %d",&a,&b);
			p[a][b]=1;
		}
		
		for(k=1;k<=n;++k)
			for(i=1;i<=n;++i)
				for(j=1;j<=n;++j)
					p[i][j] = p[i][j] || (p[i][k] && p[k][j]);
	
		nocycle=1;
		
		for(i=1;i<=n && nocycle;++i)
			for(j=i+1;j<=n && nocycle;++j)
				if(p[i][j] && p[j][i])
					nocycle=0;
		if(nocycle)
			puts("SOLVABLE");
		else
			puts("UNSOLVABLE");
				
	}
	
	return 0;
}