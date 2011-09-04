//Author - Swarnaprakash.U
#include<stdio.h>
#include<string.h>

#define M 105

char names[M][25];
int votes[M];
int tot;

int find(char *);
void normalise(char *);

main()
{
	int n;
	int i,pos;
	char user[M];
	char d,v;
	int plus,minus;
	int t=0;
	
	while(++t)
	{
		scanf("%d",&n);
		if(!n)
			break;
			
		tot=0;
		memset(votes,0,sizeof(votes));
		
		for(i=0;i<n;++i)
		{
			scanf("%s",user);
			getchar();
			v=getchar();
			normalise(user);
			pos=find(user);
			
			if(pos==-1)
			{
				strcpy(names[tot],user);
				pos=tot;
				tot++;
				
			}
			if(v=='+' && votes[pos]!=1)
				++votes[pos];
			else if(v=='-' && votes[pos]!=-1)
				--votes[pos];
		}
		
		plus=minus=0;
		for(i=0;i<tot;++i)
		{
			if(votes[i]==1)
				++plus;
			else if(votes[i]==-1)
				++minus;
		}
		
		printf("POST#%d: +%d -%d\n",t,plus,minus);
		
	}
	
	return 0;
}

int find(char *s)
{
	int i;
	for(i=0;i<tot;++i)
		if(strcmp(names[i],s)==0)
			return i;
	return -1;
}

void normalise(char *s)
{
	int i;
	
	for(i=0;s[i]!=0;++i)
		s[i]=tolower(s[i]);
}