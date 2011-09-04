//Author : swarnaprakash
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cassert>

using namespace std;

#define M 100005
#define INF 0x3f3f3f3f
#define left(x)	x<<1
#define right(x) (x<<1)+1

#define DB(x) cout<< #x << " : " <<x <<endl;

int n;
int a[M];
int rmq[2*M];

void init_rmq()
{
	int i;
	for(i=n;i<(n<<1);++i)
		rmq[i]=i-n+1;		// store the 1-based index
	for(i=n-1;i>0;--i)
	{
		if(a[rmq[left(i)]]>a[rmq[right(i)]])
			rmq[i]=rmq[left(i)];
		else
			rmq[i]=rmq[right(i)];
	}
}

void update(int pos,int val)
{
	a[pos]=val;
	pos+=n-1;
		
	while(pos>1)
	{
		pos>>=1;
		if(a[rmq[left(pos)]]>a[rmq[right(pos)]])
			rmq[pos]=rmq[left(pos)];
		else
			rmq[pos]=rmq[right(pos)];
	}
}

int query(int x,int y)
{
	int max_pos=x;
	int i=x+n-1;
	int j=y+n-1;
	int pos;
	while(i<=j)
	{
		if(a[rmq[i]]>a[rmq[j]])
			pos=rmq[i];
		else
			pos=rmq[j];
			
		if(a[pos]>a[max_pos])
			max_pos=pos;
		i=(i+1)>>1;
		j=(j-1)>>1;
	}
	
	int max2=-INF;
	i=x+n-1;
	j=y+n-1;
	while(i<=j)
	{
		if(rmq[i]!=max_pos)
			max2=max(max2,a[rmq[i]]);
		if(rmq[j]!=max_pos)
			max2=max(max2,a[rmq[j]]);
			
		i=(i+1)>>1;
		j=(j-1)>>1;
	}
	
	pos=max_pos+n-1;
	
	int lp,rp;
	while(pos>1)
	{
		pos>>=1;
		lp=rmq[left(pos)];
		rp=rmq[right(pos)];
		if(lp!=max_pos)
		{
			if(lp>=x && lp<=y)
				max2=max(max2,a[lp]);
		}
		else
		{
			if(rp>=x && rp<=y)
				max2=max(max2,a[rp]);
		}
	}
	
	return a[max_pos]+max2;
}

int main()
{
	scanf("%d",&n);
	assert(n>=2 && n<=100000);
	int i;
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		assert(a[i]>=0 && a[i]<=100000000);
	}
		
	init_rmq();
	int q;
	int x,y;
	char c;
	scanf("%d ",&q);
	assert(q<=100000);
	while(q--)
	{
		c=getchar();
		assert(c=='U' || c=='Q');
		scanf("%d %d ",&x,&y);
	
		if(c=='U')
		{
			assert(x>=1 && x<=n);
			assert(y>=0 && y<=100000000);
			update(x,y);
		}
		else
		{
			assert(x>=1 && x<=n);
			assert(y>=1 && y<=n);
			assert(x<y);
			printf("%d\n",query(x,y));
		}
	}
	return 0;
}
