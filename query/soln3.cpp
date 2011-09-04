// submission by https://www.spoj.pl/KOPC09/users/acrush during contest
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


const int maxn=100000+5;
const int maxsize=maxn*5;

int n,Q,A[maxn];
int first[maxsize],second[maxsize];

void construct(int v)
{
	int A[4];
	A[0]=first[(v<<1)+1];
	A[1]=second[(v<<1)+1];
	A[2]=first[(v<<1)+2];
	A[3]=second[(v<<1)+2];
	sort(A,A+4);
	first[v]=A[3];
	second[v]=A[2];
}
void inittree(int v,int H,int T)
{
	if (H==T)
	{
		first[v]=A[H];
		second[v]=0;
		return;
	}
	int M=(H+T)>>1;
	inittree((v<<1)+1,H,M);
	inittree((v<<1)+2,M+1,T);
	construct(v);
}
void updatetree(int v,int H,int T,int key)
{
	if (H==T)
	{
		first[v]=A[H];
		second[v]=0;
		return;
	}
	int M=(H+T)>>1;
	if (key<=M)
		updatetree((v<<1)+1,H,M,key);
	else
		updatetree((v<<1)+2,M+1,T,key);
	construct(v);
}
void solvetree(int v,int H,int T,int s,int t,int &x,int &y)
{
	if (H>=s && T<=t)
	{
		x=first[v];
		y=second[v];
		return;
	}
	x=y=0;
	int M=(H+T)>>1;
	int u=0,g=0;
	if (M>=s)
	{
		solvetree((v<<1)+1,H,M,s,t,u,g);
		if (u>x) y=x,x=u;
		else if (u>y) y=u;
		if (g>x) y=x,x=g;
		else if (g>y) y=g;
	}
	if (M<t)
	{
		solvetree((v<<1)+2,M+1,T,s,t,u,g);
		if (u>x) y=x,x=u;
		else if (u>y) y=u;
		if (g>x) y=x,x=g;
		else if (g>y) y=g;
	}
}
int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	scanf("%d",&Q);
	inittree(0,1,n);
	for (;Q>0;Q--)
	{
		char buf[10];
		scanf("%s",buf);
		if (buf[0]=='U')
		{
			int pos,value;
			scanf("%d%d",&pos,&value);
			A[pos]=value;
			updatetree(0,1,n,pos);
		}
		else
		{
			int s,t;
			scanf("%d%d",&s,&t);
			int x,y;
			solvetree(0,1,n,s,t,x,y);
			printf("%d\n",x+y);
		}
	}
	return 0;
}

