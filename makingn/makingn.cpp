#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
#define INF 123456789;
#define M 1000
int best[M+9];
int fact[10];

int main()
{
	int i,j,d;
	
	for(i=2;i<=M;++i)
		best[i]=INF;
		
	best[1]=1;
	
	fact[1]=1;
	for(i=2;i<8;++i)
		fact[i]=i*fact[i-1];
		
	for(i=1;i<M;++i)
	{
		if(i<=6)
			best[fact[i]]=min(best[fact[i]],best[i]);
		for(j=1;j<=i;++j)
		{
			d=i+j;
			if(d>M)
				break;
			best[d]=min(best[d],best[i]+best[j]);
		}
		for(j=2;j<=i;++j)
		{
			d=i*j;
			if(d>M)
				break;
			best[d]=min(best[d],best[i]+best[j]);
		}
		d=i*i;
		if(d<=M)
			best[d]=min(best[d],best[i]);
		d=i*i*i;
		if(d<=M)
			best[d]=min(best[d],best[i]);
	}
	
	
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",best[n]);
	}
		
	return 0;
}
