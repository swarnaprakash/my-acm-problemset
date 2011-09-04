// Author  swarnaprakash
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>

using namespace std;

set<int> pal;
void fun(char *);

int main()
{
	char a[10];
	char i,j,k,x;
		
	for(x='0';x<='9';++x)
	{
		
		for(i='0';i<='9';++i)
			for(j='0';j<='9';++j)
				for(k='0';k<='9';++k)
				{
					a[0]=a[6]=i;
					a[1]=a[5]=j;
					a[2]=a[4]=k;
					a[3]=x;			
					a[7]=0;
					
					fun(a);						
						
					a[0]=a[7]=i;
					a[1]=a[6]=j;
					a[2]=a[5]=k;
					a[3]=a[4]=x;
					a[8]=0;
					
					fun(a);
				}
	}
	
	
	for(set<int>::iterator it=pal.begin();it!=pal.end();++it)
		printf("%d\n",*it);
	
	return 0;
}

void fun(char *a)
{
	int i;
	
	for(i=strlen(a)-1;i>=0 && a[i]=='0';--i);
	a[i+1]=0;		//Remove trailing zeros
	int n=atoi(a);
	if(n>0 && n<=100000000)
		pal.insert(n);
}
