//Author : swarnaprakash
//Algorithm : Floyd-Warshall O( (No_of_squares)^3 )

#include<stdio.h>
#include<stdlib.h>

#define INF 1000

short best[8][8][8][8];

short min(short a,short b)
{
	if(a<b)
		return a;
	else
		return b;
}

int main()
{
	int t;
	int i,j,k,l,x,y;
	char start[5],end[5];
	
	for(i=0;i<8;++i)
		for(j=0;j<8;++j)
			for(k=0;k<8;++k)
				for(l=0;l<8;++l)
					if( (abs(i-k)==1 && abs(j-l)==2) || (abs(i-k)==2 && abs(j-l)==1) ) // If Knight can move from square ij to square kl
						best[i][j][k][l]=1;
					else
						best[i][j][k][l]=INF;
						
	for(i=0;i<8;++i)
		for(j=0;j<8;++j)
			best[i][j][i][j]=0;
					
	//Floyd-Warshall
	
	for(x=0;x<8;++x)
		for(y=0;y<8;++y)
			for(i=0;i<8;++i)
				for(j=0;j<8;++j)
					for(k=0;k<8;++k)
						for(l=0;l<8;++l)
							best[i][j][k][l]=min(best[i][j][k][l],best[i][j][x][y]+best[x][y][k][l]);
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%s %s",start,end);
		printf("%hd\n",best[start[0]-'a'][start[1]-'1'][end[0]-'a'][end[1]-'1']);
	}
	
						
	return 0;
}
