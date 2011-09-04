//Author - Swarnaprakash.U
#include<stdio.h>
#include<string.h>

#define M 12009

int LCS[2][M];

main()
{
	int t,i,j;
	char a[M],b[M];
	int l,m,x,y;

	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%s",a);
		scanf("%s",b);
		
		l=strlen(a);
		m=strlen(b);
		
		memset(LCS,0,sizeof(LCS));
		
		for(i=1;i<=l;++i)
			for(j=1;j<=m;++j)
			{
				if(a[i-1]==b[j-1])
					LCS[i&1][j]=LCS[(i-1)&1][j-1]+1;
				else
				{
					x=LCS[(i-1)&1][j];
					y=LCS[i&1][j-1];
					
					if(x>y)
						LCS[i&1][j]=x;
					else
						LCS[i&1][j]=y;
				}
			}

		printf("%d\n",LCS[l&1][m]);
	}
	return 0;
}