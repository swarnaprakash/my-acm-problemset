//Author : swarnaprakash
//Algorithm : BFS

#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;


bool visited[8][8];

struct square
{
	int x,y;
	int moves;
	
	square()
	{
	}
	square(int xx,int yy,int m)
	{
		x=xx;
		y=yy;
		moves=m;
	}
};

int mindist(char *aaa,char *bbb)
{
	square start=square(aaa[0]-'a',aaa[1]-'1',0);
	int endx=bbb[0]-'a';
	int endy=bbb[1]-'1';
	
	queue<square> Q;
	Q.push(start);
	
	memset(visited,0,sizeof(visited));
	
	
	int dx[]={2,2,-2,-2,1,1,-1,-1};
	int dy[]={1,-1,1,-1,2,-2,2,-2};
	int i,nx,ny;
	
	visited[start.x][start.y]=true;
	
	while(Q.empty()==false)
	{
		square now=Q.front();
		Q.pop();
		
		if(now.x==endx && now.y==endy)
			return now.moves;
				
		for(i=0;i<8;++i)
		{
			nx=now.x+dx[i];
			ny=now.y+dy[i];
			
			if(nx>=0 && nx<8 && ny>=0 && ny<8 && visited[nx][ny]==false)
			{
				visited[nx][ny]=true;
				Q.push( square(nx,ny,now.moves+1) );
			}
		}
		
	}
	
	return -42; //If everything is correct you should never reach here !
}

int main()
{
	int t;
	char start[5],end[5];
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%s %s",start,end);
		printf("%d\n",mindist(start,end));
	}
	return 0;
}
